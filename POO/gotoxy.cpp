/*
    strlen () toma una cadena de bytes terminada en nulo str como su argumento
    y devuelve su longitud.
    La longitud no incluye el car�cter nulo.
    Si no hay un car�cter nulo en la cadena, el comportamiento de la funci�n no est� definido.

    strcmp () compara dos cadenas de terminaci�n nula.
    La comparaci�n se hace lexicogr�ficamente. strcmp (cadena1, cadena2)

    strncmp () compara un n�mero espec�fico de caracteres de dos cadenas de terminaci�n nulas.
    La comparaci�n se hace lexicogr�ficamente. strcmp (cadena1, cadena2, tama�o)

*/

#include<iostream>
#include<windows.h>


#define INSTITUTO "Instituto Politecnico Nacional"
#define ESCUELA "Escuela Superior de Ingenieria Mecanica y Electrica - Zacatenco"
#define ACADEMIA "Academia de Computacion"
#define MATERIA "Fundamentos de Programacion"
#define ALUMNO "Alumno : Juan Perez "
#define PROFESOR "Profesor : Ing. Jorge Anzaldo"
#define GRUPO "Grupo 1CV#"

using namespace std;

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

main(){
    system("cls");
    gotoxy((80-strlen(INSTITUTO))/2,3);cout<<INSTITUTO;
    gotoxy((80-strlen(ESCUELA))/2,6);cout<<ESCUELA;
    gotoxy((80-strlen(ACADEMIA))/2,9);cout<<ACADEMIA;
    gotoxy((80-strlen(MATERIA))/2,12);cout<<MATERIA;
    gotoxy((80-strlen(ALUMNO))/2,15);cout<<ALUMNO;
    gotoxy((80-strlen(PROFESOR))/2,18);cout<<PROFESOR;
    gotoxy((80-strlen(GRUPO))/2,21);cout<<GRUPO;
    gotoxy(10,25);system("pause");
 }
