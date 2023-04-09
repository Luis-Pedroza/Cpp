//Programa con métodos matemáticos
//Este programa requiere la librería III-IV.h

//Autor: Luis Pedroza
//Fecha: 2020

#include "III-IV.h"
void UIII()
{	int sub;
	do
	{	system("cls");
		cout<<"1=Gauss Jordan\n2=Matriz Inversa\n3=Metodo de Jacobi\n4=Gauss Seidel\n5=Regresar\nSeleccionaste: "; cin>>sub;
		switch(sub)
		{	case 1: InicioGJ(); break;
			case 2: InicioMI(); break;
			case 3: InicioJac(); break;
			case 4: InicioGS(); break;
			case 5: break;
			default: cout<<"Opcion invalida verifica tu seleccion"<<endl; break;
		}
		system("pause"); system("cls");
	}while(sub!=5);	
}
void UIV()
{	int sub;
	do
	{	system("cls");
		cout<<"1=Interpolacion de Lagrange\n2=Minimos Cuadrados\n3=Regresar\nSeleccionaste: "; cin>>sub;
		switch(sub)
		{	case 1: InicioIL(); break;
			case 2: InicioMC(); break;
			case 3: break;
			default: cout<<"Opcion invalida verifica tu seleccion"<<endl; break;
		}
		system("pause"); system("cls");
	}while(sub!=3);
}
main ()
{	int opc;
	Portada();
	do
	{	cout<<"Menu Final\n1=Unidad III\n2=Unidad IV\n3=Salir\nSeleccionaste: "; cin>>opc;
		switch(opc)
		{	case 1: UIII(); break;
			case 2: UIV(); break;
			case 3: cout<<"Saliste del programa Adios"<<endl; break;
			default: cout<<"Opcion invalida verifica tu seleccion"<<endl; break;
		}
		system("pause"); system("cls");
	}while(opc!=3);	
}
