/******************************************************************************
* Archivo: Datos_RPI-Pico.c
*
* Descripción:
* Se inicializan las siguientes tareas
* 1. Prender y apagar LEDs (5)
* 2. Lectura de teclas numéricas (1-5)
* 3. Lectura de botón en puerto GPIO
* De tal forma que se controle el encendido y apagado de los LEDs con las teclas
* Adicionalmente con el botón en GPIO se ........
* 
* Autor:     Luis Pedroza
*
* Revision:   1.0
* Rev 1.0 (31/05/23): Creado 
*
* Notas:
* 1. Editar el archivo "FreeRTOSConfig.h" con la siguiente línea:
*
*    configUSE_MUTEXES	1
* 
* Asignación de pines de entrada
*---------------------------------------------------------------------------
* pin:	    17
* GPIO     	13	     
* --------------------------------------------------------------------------
*
* Asignación de pines de salida
*---------------------------------------------------------------------------
* pin:	    1	     2	    4	     5	    6
* GPIO     	0      1	    2	     3	    4
* --------------------------------------------------------------------------
* ***************************************************************************/

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"


// Prototipo de funciones
void read(void*);
void write(void*);
void turnOFF();

// Puerto de entrada
uint input = 16;

// Arreglo de puertos GPIO de salida
uint output[]= {
	0,
	1,
  2,
  3,
  4
};

// Estado del LED
bool led[] = 
{
  false, 
  false,
  false,
  false,
  false
};

// Arreglo de niveles lógicos
bool level[]= {
	false,
	false,
  false,
  false,
  false
};

// Arreglo de semi-periodos de parpadeo en ms
uint time[]= {
	100,
	70,
	150,
	10,
	400
};

// Arreglo de mutex para 6 tareas
SemaphoreHandle_t mutex[6];

// variable para obtener la tecla
char usrInput;
// variable para opener la posición de los arreglos según la tecla
uint num;

int main(){
  uint ch = 0;
  stdio_init_all();
  for(ch = 0; ch < 6; ch++){
    mutex[ch] = xSemaphoreCreateMutex();
  }

  // verificar si se puede crear el mutex
  if(mutex != NULL) {
    // args: nombreFunción, nombreTarea, tamañoPila, paramTarea, prioridad, handle
    for(ch = 0; ch < 5; ch++){
      xTaskCreate(read, "read", 256, (void *)ch, 1, NULL);
      xTaskCreate(write, "write", 256, (void *)ch, 1, NULL);
    }
    xTaskCreate(turnOFF, "turnOFF", 256, NULL, 1, NULL);
  }
  // planificador
  vTaskStartScheduler();
  while(true){};
}

void read(void* arg) {
  // variable que permite la sincronización
  uint num = (uint)arg;
  // variable para almacenar el tiempo de inicio de la tarea
  TickType_t xTimeAtWhichMutexWasTaken;

  do {
    // se obtiene la tecla en ascii
    usrInput = getchar();
    // verificar si el rango es de 1 a 5
    if(usrInput<54 && usrInput>48){
      // obtener posición
      num = usrInput - 49;
      // tomar mutex y el tiempo de inicio
      xSemaphoreTake(mutex[num], portMAX_DELAY);
      xTimeAtWhichMutexWasTaken = xTaskGetTickCount(); 

      // maquina de estados
      if(level[num] == true){
        level[num] = false;
        printf("\nEstado de  %d = %d",num,level[num] );
      }
      else{
        level[num] = true;
        printf("\nEstado de  %d = %d",num,level[num] );
      }
      // liberar mutex
      xSemaphoreGive(mutex[num]);
      // verificar si otra tarea se ejecuto y ceder los recursos
      if( xTaskGetTickCount() != xTimeAtWhichMutexWasTaken ) {
        taskYIELD();
      }
    }
    // imprimir error si se presionan teclas diferentes de 1 -5
    else {
      printf("\nEl valor ingresado no es valido.");
      num = 0;
     }
  } 
  while(true);
}

void write(void* arg) {
  // variable que permite la sincronización
  uint num = (uint)arg;
  // variable para almacenar el tiempo de inicio de la tarea
  TickType_t xTimeAtWhichMutexWasTaken;

  while (true) {
    // tomar mutex y el tiempo de inicio
    xSemaphoreTake(mutex[num], portMAX_DELAY);
    xTimeAtWhichMutexWasTaken = xTaskGetTickCount(); 
    // obtener el tiempo en ms de cada led
    const TickType_t xDelay = time[num] / portTICK_PERIOD_MS;
    // inicializar los LEDs
    gpio_init(output[num]);
    gpio_set_dir(output[num], GPIO_OUT);

    // obtener el nivel lógico y asignarlo al led
    led[num] = level[num];
    // verificar si el nivel es true y parpadear
    if (led[num]) {
      gpio_put(output[num], true);
      vTaskDelay(xDelay);
      gpio_put(output[num], false);
    }
    // liberar el mutex
    xSemaphoreGive(mutex[num]);
    // verificar si otra tarea se ejecuto y ceder recursos
    if (xTaskGetTickCount() != xTimeAtWhichMutexWasTaken) {
      taskYIELD();
    }
  }
}

void turnOFF() {
  // variable para almacenar el tiempo en que inicio la tarea
  TickType_t xTimeAtWhichMutexWasTaken;
  // auxiliar para poder apagar todo
  bool auxiliar = false;
  // inicializar el GPIO del botón
  gpio_init(input);
  gpio_set_dir(input, GPIO_IN);

  while (true) {
    // tomar el ultimo mutex y el tiempo de inicio
    xSemaphoreTake(mutex[5], portMAX_DELAY);
    xTimeAtWhichMutexWasTaken = xTaskGetTickCount();
    // verificar si se presiono el botón y el estado de la variable auxiliar
    if (gpio_get(input) && auxiliar == false) {
      printf("\n¿Desea terminar las tareas?");
      printf("\nPresione s para terminar o n para seguir");
      auxiliar = true;
    }
    // verificar el valor de la tecla y el valor del auxiliar
    if(usrInput == 115 && auxiliar == true){
      // apagar todos los LEDs si el input es s
      for (uint i = 0; i < 5; i++) {
        level[i] = false;
        gpio_put(output[i], 0);
      } 
      printf("\nSe apago todo");
      auxiliar = false;
    }
    // continuar con las tareas si el input es n
    if(usrInput == 110 && auxiliar == true){
      printf("\nSe continua con las tareas");
      auxiliar = false;
    }
    // liberar mutex
    xSemaphoreGive(mutex[5]);
    // verificar si se ejecuto otra tarea y ceder los recursos
    if( xTaskGetTickCount() != xTimeAtWhichMutexWasTaken ) {
      taskYIELD();
    }
  }
}
