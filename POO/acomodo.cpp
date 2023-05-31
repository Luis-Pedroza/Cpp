/*  ancho del campo - cout.width(20); o,
     utilizando un manipulador:  cout << setw(20); Estos solo cambian el ancho de la salida del siguiente elemento solamente.

    Rellenar carácter cout.fill('0'); o
    cout << setfill('0');

    precision
    El formato de los flotadores se puede establecer por:
    cout.setf(scientific, floatfield);

    y el número de decimales por:  cout.precision(2); o:
    cout << setprecision(2);
*/
//Autor: Luis Pedroza
//Fecha: 2020

#include<iostream>
#include<math.h>
#include<windows.h>

#define pi 3.141592  // usamos 6 cifras significativas

using namespace std;


main( ){
    int g;
    float r;

    cout<<"\n Programa que tabula la funcion coseno\n";
    cout<<"\n Presione enter para continuar \n\n";
    //system("pause");
    cout<<"Grados |      r        | sin (r) - Resultado   \n";
    cout<<"------------------------------------------- \n";

    for(g=0;g<361;g+=15){  // recuerda g+=15  es igual a  g=g+15;
            r=g*(pi/180);
            cout.width(6);  // delimita el ancho del siguiente cout
            cout.precision(6);  // identifica el numero de dígitos / cifras significativas
            cout<<g<<" | ";
            cout.width(10);
            cout.precision(6);
            cout<<right<<r<<"    |    ";// right - palabra reservada - alinea el cout a la derecha
            cout.width(6);
            cout.precision(6);
            cout<<left<<sin(r)<<"\n";   // left - palabra reservada - alinea el cout a la izquierda
    }

    cout<<"\n\nGrados  |      r        | cos (r) - Resultado   \n";
    cout<<"------------------------------------------- \n";
    for(g=0;g<361;g+=15){  // recuerda g+=15  es igual a  g=g+15;
            r=g*(pi/180);

            cout<<fixed;  //fixed usa el punto decimal fijo para n�meros en punto flotante
            cout.width(7);
            cout.precision(6);
            cout<<right<<g<<" |   ";
            cout<<r<<"    |   ";
            cout<<left<<cos(r)<<"\n";
    }

    system("pause");
}


