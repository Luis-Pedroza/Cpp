//sobrecarga de funciones

//Autor: Luis Pedroza
//Fecha: 2020

#include <iostream>
using namespace std;
int suma(int a, int b)
{
   int c;
   c=a+b;
   return c;
}
float suma(float a, float b)
{
	float c;
   c=a+b;
   return c;
}
double suma(int a, float b)
{
	float c;
   c=a+b;
   return c;
}
int main()
{
	int x,y;
	float a,b;
	cout<<"Ingrese un valor entero ";cin>>x;
	cout<<"Ingrese un valor entero ";cin>>y;
	cout<<"Ingrese un valor decimal ";cin>>a;
	cout<<"Ingrese un valor decimal ";cin>>b;
    cout<<"La suma de los enteros es "<<suma(x,y)<<endl;
    cout<<"La suma de los decimales es "<<suma(a,b)<<endl;
    cout<<"La suma de las cuatro cifras es "<<suma(suma(x,y),suma(a,b))<<endl;
}
