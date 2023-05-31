//Programa para crear perros con POO
//Autor: Luis Pedroza
//Fecha: 2020


#include<iostream>
using namespace std;

//Clase perro
class perro{
	private:
	//Atributos
		string nombre;
		string raza;
		int edad;
		float peso;
	public:
	//Métodos
		perro(void);
		perro(string,string,int,float);
		void leer(void);
		void imprimir(void);
		~perro(void);
};
//Constructor vacío
perro::perro(void){
	nombre=" ";
	raza=" ";
	edad=0;
	peso=0;
}
//Constructor con parámetros
perro::perro(string N,string R,int E,float P){
	nombre=N; raza=R; edad=E; peso=P;
}
//Método leer
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
//Método imprimir
void perro::imprimir(void){
	cout<<"El nombre del perro es "<<nombre;
	cout<<"\nLa raza del perros es "<<raza;
	cout<<"\nLa edad del perro es "<<edad;
	cout<<"\nEl peso del perro es "<<peso;
}
//Destructor
perro::~perro(void){
	cout<<"\n\nDestructor de perro";
}

int main(void){
	//Se crea un perro vacío y se imprime
	perro A;
	A.imprimir();
	cout<<"\n\n";

	//Se inicializa un pero con valores y se imprime
	perro B("cerbero","chihuahua",4,10.11);
	B.imprimir();
	cout<<"\n\n";
	
	//Se obtienen los datos del perro y se imprimen
	perro C;
	C.leer();
	C.imprimir();
	cout<<"\n\n\n";
	system("pause");
	return 0;
}
