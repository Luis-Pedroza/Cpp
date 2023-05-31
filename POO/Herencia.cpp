#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class persona
{
	protected:
		string nombre,genero;
		int edad;
	public:
		void iniP(string,string,int);
		void impP();
};
class alumno:public persona
{
	string semestre,grupo;
	long int boleta;
	public:
		void iniA(string,string,long int);
		void impA();
};
class docente:public persona
{
	string numE;
	float sueldo;
	public:
		void iniD(string,float);
		void impD();
};
void persona::iniP(string nom,string gen, int ed)
{
	nombre=nom;genero=gen;edad=ed;
}
void persona::impP()
{
	cout<<"Nombre "<<nombre<<endl;
	cout<<"Genero "<<genero<<endl;
	cout<<"Edad "<<edad<<endl;
}
void alumno::iniA(string sem,string g, long int bol)
{
	semestre=sem;grupo=g;boleta=bol;
}
void alumno::impA()
{
	cout<<"Semestre "<<semestre<<endl;
	cout<<"Grupo "<<grupo<<endl;
	cout<<"Boleta "<<boleta<<endl;
}
void docente::iniD(string Nemp,float suel)
{
	numE=Nemp;sueldo=suel;
}
void docente::impD()
{
	cout<<"Numero de empleado "<<numE<<endl;
	cout<<"Sueldo "<<sueldo<<endl;
}
int main()
{
	persona obp;
	alumno oba;
	docente obd;
	int op;
	unsigned char tecla;
do{
	system("cls");
	cout<<"Seleccione una opcion dentro del menu"<<endl<<endl;
	cout<<"Persona -------------------------- 1 "<<endl;
	cout<<"Alumno --------------------------- 2 "<<endl;
	cout<<"Docente -------------------------- 3 "<<endl;
	cout<<"Salir ---------------------------- 4 "<<endl;
	cout<<"Su opcion -----------------------  ";
	cin>>op;
	switch(op)
	{
		case 1:
			system("cls");
			obp.iniP("Martha","F",19);
			obp.impP();
			cout<<endl<<"Precione cualquier tecla para regresar al menu o Esc para salir.";
			tecla=getch();
		break;
		case 2:
			system("cls");
			oba.iniP("Carlos","M",20);
			oba.iniA("segundo","2cv7",2019300019);
			oba.impP();
			oba.impA();
			cout<<endl<<"Precione cualquier tecla para regresar al menu o Esc para salir.";
			tecla=getch();
		break;
		case 3:
			system("cls");
			obd.iniP("Ricardo","M",28);
			obd.iniD("2142E",58428.7);
			obd.impP();
			obd.impD();
			cout<<endl<<"Precione cualquier tecla para regresar al menu o Esc para salir.";
			tecla=getch();
		break;
		case 4:
			system("cls");
			cout<<endl<<"Precione cualquier tecla para regresar al menu o Esc para salir.";
			tecla=getch();
		break;
		default:
			cout<<"\nLa opcion no existe.\nPrecione cualquier tecla para regresar al menu o Esc para salir.";
			tecla=getch();
		break;
	}
}
while(tecla!=27);
}
