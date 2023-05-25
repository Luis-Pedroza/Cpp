/******************************************************************************
* Archivo: read_gpio.c
*
* Descripción:
* Programa que inicializa 6 tareas para prender y apagar 5 LEDs con 6 botones
* Este programa fue probado en la tarjeta raspberry Pi Pico.
* 
* Autor:     Conejo
* Modificado: Luis Pedroza
*
* Revision:   0.2
* Rev 0.1 (12/05/22): Reestructuración de código
* Rev 0.1 (12/05/22): Actualización de la descripción 
* Rev 0.0 (09/05/22): Creado 
*
* Notas:
* 1. Editar el archivo "FreeRTOSConfig.h" con la siguiente línea:
*
*    configUSE_MUTEXES	1
* 
* Asignación de pines de entrada
*---------------------------------------------------------------------------
* variable:	x(0)	x(1)
* pin:	    17	    19	    24	     22	    21	    20 
* GPIO     	13      14	    18	     17	    16	    15	     
* --------------------------------------------------------------------------
*
* Asignación de pines de salida
*---------------------------------------------------------------------------
* variable:	y(0)	y(1)
* pin:	    1	     2	    4	     5	    6
* GPIO     	0      1	    2	     3	    4
* --------------------------------------------------------------------------
* ***************************************************************************/

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

// Arreglo de puertos GPIO de entrada (General Port)
uint input[] = {
	13,
	14,
  18,
  17,
  16,
  15 // Entrada para apagar todo
};

// Arreglo de puertos GPIO de salida
uint output[]= {
	0,
	1,
  2,
  3,
  4
};

// Arreglo de niveles lógicos
bool level[]= {
	false,
	false,
  false,
  false,
  false
};

// Estado del botón
bool estado[] = {
    false,
    false,
    false,
    false,
    false
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

// Arreglo de semi-periodos de parpadeo en ms
uint tiempo[]= {
	100,
	70,
	150,
	10,
	400
};

// Arreglo de mutex para 6 tareas
SemaphoreHandle_t mutex[6];

// Prototipos de funciones
void read(void*);
void write(void*);
void apagar(void*);

int main(){
  
  uint ch = 0;

  // Crear mutex para las 6 tareas
  for(ch = 0; ch < 6; ch++){
    mutex[ch] = xSemaphoreCreateMutex();
  }

  // Si no es posible crear mutex por memoria
  // insuficiente, no crea las tareas.
  if(mutex != NULL) {
    // args: nombreFunción, nombreTarea, tamañoPila, paramTarea, Prioridad
    // prioridad, handle
    for(ch = 0; ch < 5; ch++){
        xTaskCreate(read, "read", 256, (void *)ch, 1, NULL);
        xTaskCreate(write, "write", 256, (void *)ch, 1, NULL);
    }
    xTaskCreate(apagar, "apagar", 256, (void *)ch, 1, NULL);

  }
  
  // Inicio del planificador
  vTaskStartScheduler();

  // Bucle de ejecución infinito
  while(true){};
}


void read(void* arg) {
  uint ch = (uint)arg;
  
  // Variable que almacena el numero de ciclo de reloj
  TickType_t xTimeAtWhichMutexWasTaken;
  
  // Inicializa un GPIO para I/O habilitada, fija función como GPIO_FUNC_SIO,
  // fija el puerto como entrada. Limpia cualquier valor de salida.  
  // Raspberry Pi Pico C/C++ SDK, páginas: 115-116. Por defecto, todas 
  // las entradas tienen conectada una resistencia de bajada de 80k ohms.
  gpio_init(input[ch]);
  gpio_set_dir(input[ch], GPIO_IN);

  // Ciclo infinito para ejecutar la tarea
  while(true) {
    xSemaphoreTake(mutex[ch], portMAX_DELAY);
    xTimeAtWhichMutexWasTaken = xTaskGetTickCount();  
    level[ch] = gpio_get(input[ch]);

    xSemaphoreGive(mutex[ch]);

    // Lineas agregadas para garantizar el cambio entre tareas
    // con la misma prioridad si se usa el algoritmo de planificación
    // pre-empt (con preferencia por prioridad con valor más bajo).
    // Adelanta el cambio de tarea si el algoritmo de planificación
    // usado es el Round Robin (time slicing).
    if( xTaskGetTickCount() != xTimeAtWhichMutexWasTaken ) {
      taskYIELD();
    }
  } // fin de la sentencia while
} // fin de la función read()

void write(void* arg) {
  uint ch = (uint)arg;
  const TickType_t xDelay = tiempo[ch] / portTICK_PERIOD_MS;

  
  // Variable que almacena el numero de 
  // ciclo de reloj
  TickType_t xTimeAtWhichMutexWasTaken;

  gpio_init(output[ch]);
  gpio_set_dir(output[ch], GPIO_OUT);

  while(true) {
    // Espera a que la tarea actual termine para poder ejecutar mutex[ch]
    xSemaphoreTake(mutex[ch], portMAX_DELAY);
    xTimeAtWhichMutexWasTaken = xTaskGetTickCount();
    
    if (level[ch] && !estado[ch]) { // si se detecta un flanco de subida del botón
      led[ch] = !led[ch]; // cambiar el estado del LED
    }
    estado[ch] = level[ch]; // actualizar el estado del botón
    
    if(led[ch]){
        gpio_put(output[ch], true);
        vTaskDelay(xDelay);
        gpio_put(output[ch], false);
        vTaskDelay(xDelay);
    }
    // Suspende la tarea durante 20ms
    vTaskDelay(pdMS_TO_TICKS(20));
    xSemaphoreGive(mutex[ch]);
    
    // Lineas agregadas para garantizar el cambio entre tareas
    // con la misma prioridad si se usa el algoritmo de planificación
    // pre-empt (con preferencia por prioridad con valor más bajo).
    // Adelanta el cambio de tarea si el algoritmo de planificación
    // usado es el Round Robin (time slicing).
    if( xTaskGetTickCount() != xTimeAtWhichMutexWasTaken ) {
      taskYIELD();
    }
  } // fin de la sentencia while
} // fin de la función write()

void apagar(void* arg) {
  uint btnApagar = input[5];
  // Variable para almacenar el tiempo en que inicio el mutex
  TickType_t xTimeAtWhichMutexWasTaken;

  gpio_init(btnApagar);
  gpio_set_dir(btnApagar, GPIO_IN);

  while (true) {
    // Espera a que el mutex se libere para ejecutar la tarea 5
    xSemaphoreTake(mutex[5], portMAX_DELAY);
    // Se almacena el inicio de la tarea
    xTimeAtWhichMutexWasTaken = xTaskGetTickCount();
    // Apagar todos los botones
    if (gpio_get(btnApagar)) {
      for (uint i = 0; i < 5; i++) {
        led[i] = false;
      }
    }
    xSemaphoreGive(mutex[5]);

    // Verifica si se ejecuto otra tarea, y la adelanta
    if( xTaskGetTickCount() != xTimeAtWhichMutexWasTaken ) {
      taskYIELD();
    }
  }
}