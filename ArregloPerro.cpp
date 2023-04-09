#include<iostream>
using namespace std;

class perro{
	private:
		string nombre;
		string raza;
		int edad;
		float peso;
	public:
		perro(void);
		perro(string,string,int,float);
		void leer(void);
		void imprimir(void);
		~perro(void);
};
perro::perro(void){
	nombre=" ";
	raza=" ";
	edad=0;
	peso=0;
}
perro::perro(string N,string R,int E,float P){
	nombre=N; raza=R; edad=E; peso=P;
}
void perro::leer(void){
	cout<<"Nombre del perro ";
	fflush(stdin);
	getline(cin,nombre);
	cout<<"Raza del perro ";
	fflush(stdin);
	getline(cin,raza);
	cout<<"Edad del perro ";
	cin>>edad;
	cout<<"Peso del perro ";
	cin>>peso;
}
void perro::imprimir(void){
	cout<<"\nEl nombre del perro es "<<nombre;
	cout<<"\nLa raza del perros es "<<raza;
	cout<<"\nLa edad del perro es "<<edad;
	cout<<"\nEl peso del perro es "<<peso;
}
perro::~perro(void){
	cout<<"\nDestructor de perro";
}
class arregloPerro{
	private:
		perro masPerros[5];
		int i;
	public:
		/*arregloPerro(void);
		arregloPerro(perro,int);*/
		void leer(void);
		void imprimir(void);
		~arregloPerro(void);
};
void arregloPerro::leer(void){
	for(i=0;i<5;i++)
	{
		masPerros[i].leer();
	}
}
void arregloPerro::imprimir(void){
	for(i=0;i<5;i++)
	{
		masPerros[i].imprimir();
	}
}
arregloPerro::~arregloPerro(void){
	cout<<"\nDestructor de arregloPerro";
}
int main(void){
	
	arregloPerro perros;
	perros.leer();
	perros.imprimir();
	cout<<"\n\n\n";
	system("pause");
	return 0;
}
