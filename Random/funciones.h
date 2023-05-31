#include<iostream>
#include<iomanip>
#include<math.h>
#include<conio.h>
//Esta librería es obsoleta
#include<graphics.h>
using namespace std;
void marco(){
	setcolor(WHITE);
	rectangle(10,10,780,580);
}
void eje(){
	setcolor(DARKGRAY);
	line(390,10,390,580);
	line(10,290,780,290);
	for(int i=10;i<580;i+=10){
		setcolor(DARKGRAY);
		line(387,i,393,i);
	}
	for(int i=10;i<780;i+=10){
		setcolor(DARKGRAY);
		line(i,287,i,293);
	}
}
void portada(){
	cout<<"Instituto Politecnico Nacional";
	cout<<"\nEscuela superior de Ingenieria Mecanica y Electrica";
	cout<<"\nUnidad Zacatenco";
	cout<<"\nAnalisis numerico";
	cout<<"\nBernal Mendoza Jose Antonio";
	cout<<"\nGrupo: 4CV6";
	cout<<"\nPractica 1 Biseccion y Newton Raphson";
	cout<<"\nCalcular y graficar una funcion exponencial y binomial mediante los metodos de biseccion y newton raphson";
	cout<<"\nPedroza Morachel Luis Fernando: 2019300019\nFeliciano Morales Juan Daniel: 2019301436";
}
void menu(){
	cout<<"Ingrese el metodo a utilizar";
	cout<<"\nBiseccion ------------------ 1";
	cout<<"\nNewton Raphson ------------- 2";
	cout<<"\nSalir ---------------------- 3";
	cout<<"\nSu opcion ------------------ ";
}
void submenu(){
	cout<<"\nIngrese la funcion a utilizar";
	cout<<"\nExponencial --------------------- 1";
	cout<<"\nPolinomial ---------------------- 2";
	cout<<"\nSalir --------------------------- 3";
	cout<<"\nSu opcion ----------------------- ";
}
