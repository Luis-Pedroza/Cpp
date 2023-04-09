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
	cout<<"\n\nDestructor de perro";
}
int main(void){	

	perro *objetoPerro;
	int i,cantidad;
	cout<<"Ingrese la cantidad de perros: ";
	cin>>cantidad;
	objetoPerro=new perro[cantidad];
	for(i=0;i<cantidad;i++){
		objetoPerro[i].leer();
	}
	for(i=0;i<cantidad;i++){
		objetoPerro[i].imprimir();
	}
	delete[]objetoPerro;
	
	system("pause");
	return 0;
}
