//Ejemplo de uso define
//Autor: Luis Pedroza
//Fecha: 2020

#include<stdio.h>
#define PI 3.1416
#define MENSAJE "El valor de PI es "

main()
{
    printf(MENSAJE);
    printf("%f",PI);
    printf("\n \n");
    
    printf("El area de un circulo con radio 3 es %f",PI*(3*3));
    printf("\n \n Oprima una tecla para continuar ... ");
    getch();
}
