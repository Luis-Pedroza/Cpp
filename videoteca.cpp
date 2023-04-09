#include<iostream>
using namespace std;

class videoteca{
	private:
		string nombre;
		string autor;
		string genero;
		int anio;
		int cantidad;
	public:
		videoteca(void);
		videoteca(string,string,string,int,int);
		void leer(void);
		void imprimir(void);
		~videoteca(void);
};
videoteca::videoteca(void){
    nombre=" "; autor=" "; genero=" "; anio=0; cantidad=0;
}
videoteca::videoteca(string Nombre,string Autor,string Genero,int Anio,int Cantidad){
	nombre=Nombre; autor=Autor; genero=Genero; anio=Anio; cantidad=Cantidad;
}
void videoteca::leer(void){
	cout<<"Ingrese el nombre de la pelicula ";
	fflush(stdin);
	getline(cin,nombre);
	cout<<"Ingrese el autor de la pelicula ";
	fflush(stdin);
	getline(cin,autor);
	cout<<"Ingrese el genero de la pelicula ";
	fflush(stdin);
	getline(cin,genero);
	cout<<"Ingrese el anio de la pelicula ";
	cin>>anio;
	cout<<"Ingrese la cantidad de peliculas ";
	cin>>cantidad;
}
void videoteca::imprimir(void){
	cout<<"\nPelicula :"<<nombre;
	cout<<"\nAutor :"<<autor;
	cout<<"\nGenero :"<<genero;
	cout<<"\nAnio :"<<anio;
	cout<<"\nCantidad :"<<cantidad;
}
videoteca::~videoteca(void){
	cout<<"\n\n\nDestructor de videoteca";
}
int main(void){
	videoteca pelicula;
	pelicula.videoteca(void);
	pelicula.leer();
	pelicula.imprimir();
	cout<<"\n\n";
	system("pause");
	return 0;
}
