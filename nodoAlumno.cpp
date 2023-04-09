#include<iostream>
using namespace std;

class alumno{
	private:
		string nombre;
		string boleta;
	public:
		alumno(void);
		alumno(string, string);
		alumno(const alumno &);
		void leer(void);
		void imprimir(void);
		string obtenerNombre(void);
		string obtenerBoleta(void);
		void editarNombre(string);
		void editarBoleta(string);
		alumno &operator=(const alumno &);
		~alumno(void);
};
class nodoAlumno{
	private:
		alumno dato;
		nodoAlumno *aptSig;
	public:
		nodoAlumno(void);
		nodoAlumno(alumno&,nodoAlumno*);
		nodoAlumno(const nodoAlumno&);
		void leer(void);
		void imprimir(void);
		alumno &obtenerDato(void);
		nodoAlumno *obtenerAptSig(void);
		void editarDato(alumno&);
		void editarAptSig(nodoAlumno*);
		nodoAlumno&operator=(const nodoAlumno&);
		~nodoAlumno(void);
};
alumno::alumno(void){
	nombre=" "; boleta=" ";
}
alumno::alumno(string nom,string bol){
	nombre=nom;boleta=bol;
}
alumno::alumno(const alumno &estudiante){
	nombre=estudiante.nombre;boleta=estudiante.boleta;
}
void alumno::leer(void){
	cout<<"Ingrese el nombre del alumno: ";
	fflush(stdin);
	getline(cin,nombre);
	cout<<"Ingrese la boleta del alumno: ";
	fflush(stdin);
	getline(cin,boleta);
}
void alumno::imprimir(void){
	cout<<"\nNombre: "<<nombre;
	cout<<"\nBoleta: "<<boleta;
}
string alumno::obtenerNombre(void){
	return nombre;
}
string alumno::obtenerBoleta(void){
	return boleta;
}
void alumno::editarNombre(string nom){
	nombre=nom;
}
void alumno::editarBoleta(string bol){
	boleta=bol;
}
alumno &alumno::operator=(const alumno &estudiante){
	if(this!=&estudiante){
		this->nombre=estudiante.nombre;
		this->boleta=estudiante.boleta;
	}
	return *this;
}
alumno::~alumno(void){
	cout<<"\nDestructor de alumno ";
}
nodoAlumno::nodoAlumno(void){
	aptSig=NULL;
}
nodoAlumno::nodoAlumno(alumno &estudiante,nodoAlumno *student){
	dato=estudiante; aptSig=student;
}
nodoAlumno::nodoAlumno(const nodoAlumno &nodo){
	dato=nodo.dato;aptSig=nodo.aptSig;
}
void nodoAlumno::leer(void){
	cout<<"Ingrese los datos:\n";
	dato.leer();
}
void nodoAlumno::imprimir(void){
	cout<<"Los datos son: ";
	dato.imprimir();
}
alumno &nodoAlumno::obtenerDato(void){
	return dato;
}
nodoAlumno *nodoAlumno::obtenerAptSig(void){
	return aptSig;
}
void nodoAlumno::editarDato(alumno &info){
	dato=info;
}
void nodoAlumno::editarAptSig(nodoAlumno *sigApt){
	aptSig=sigApt;
}
nodoAlumno &nodoAlumno::operator=(const nodoAlumno &nodo){
	if(this!=&nodo){
		this->dato=nodo.dato;
		this->aptSig=nodo.aptSig;
	}
	return *this;
}
nodoAlumno::~nodoAlumno(void){
	cout<<"\nDestructor de nodoAlumno";
}
int main(void){
	alumno yo("Pedroza Moranchel Luis Fernando","2019300019");
	nodoAlumno alumnoVacio;
	nodoAlumno alumnoParametros(yo,&alumnoVacio);
	nodoAlumno alumnoEditar;
	cout<<"Prueba de los metodos de la clase nodoAlumno\n";
	cout<<"\n\nConstructor con valores por omicion\n";
	alumnoVacio.imprimir();
	cout<<"\n\n";
	system("pause");
	cout<<"\n\nConstructor con parametros\n";
	alumnoParametros.imprimir();
	cout<<"\n\n";
	system("pause");
	cout<<"\n\nConstructor copia y sobrecarga del operador =\n";
	alumnoVacio=alumnoParametros;
	alumnoVacio.imprimir();
	cout<<"\n\n";
	system("pause");
	cout<<"\n\nMetodos Leer e imprimir\n";
	alumnoEditar.leer();
	alumnoEditar.imprimir();
	cout<<"\n\n";
	system("pause");
	cout<<"\n\nMetodos Obtener";
	cout<<"\n\nObtener dato de alumnoVacio";
	alumnoVacio.obtenerDato().imprimir();
	cout<<"\nObtener aptSig de alumnoVacio: "<<alumnoVacio.obtenerAptSig();
	cout<<"\nLa direccion de este nodo es: "<<&alumnoVacio;
	cout<<"\n\nObtener dato de alumnoParametros";
	alumnoParametros.obtenerDato().imprimir();
	cout<<"\nObtener aptSig de alumnoParametros: "<<alumnoParametros.obtenerAptSig();
	cout<<"\nLa direccion de este nodo es: "<<&alumnoParametros;
	cout<<"\n\nObtener dato de alumnoEditar";
	alumnoEditar.obtenerDato().imprimir();
	cout<<"\nObtener aptSig de alumnoEditar: "<<alumnoEditar.obtenerAptSig();
	cout<<"\nLa direccion de este nodo es: "<<&alumnoEditar;
	cout<<"\n\n";
	system("pause");
	cout<<"\n\nMetodos Editar";
	cout<<"\nEditando todos los datos";
	cout<<"\nalumnoVacio";
	alumnoVacio.editarDato(yo);
	alumnoVacio.obtenerDato().imprimir();
	cout<<"\nalumnoParametros";
	alumnoParametros.editarDato(yo);
	alumnoParametros.obtenerDato().imprimir();
	cout<<"\nalumnoEditar";
	alumnoEditar.editarDato(yo);
	alumnoEditar.obtenerDato().imprimir();
	cout<<"\nEditando las direcciones alumnoVacio->alumnoParametros->alumnoEditar";
	alumnoVacio.editarAptSig(&alumnoParametros);
	alumnoParametros.editarAptSig(&alumnoEditar);
	cout<<"\nLa dirreccion de alumnoVacio es -------- "<<&alumnoVacio;
	cout<<"\nLa direccion de aptSig es -------------- "<<alumnoVacio.obtenerAptSig();
	cout<<"\nLa dirreccion de alumnoParametros es --- "<<&alumnoParametros;
	cout<<"\nLa direccion de aptSig es -------------- "<<alumnoParametros.obtenerAptSig();
	cout<<"\nLa dirreccion de alumnoEditar es ------- "<<&alumnoEditar;
	cout<<"\nLa direccion de aptSig es -------------- "<<alumnoEditar.obtenerAptSig();
	cout<<"\n\n";
	system("pause");
	return 0;
}
