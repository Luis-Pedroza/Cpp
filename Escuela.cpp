#include<iostream>
using namespace std;
class alumno{
      private:
              string nombre;
              string boleta;//string por que no se hacen operaciones
      public:
             alumno(void);
             alumno(string,string);
             alumno(const alumno &estudiante);
             void leer(void);
             void imprimir(void);
             ~alumno(void);
};
class grupo{
	private:
	    string nombre;
	    alumno a[2];
	public:
		void leer(void);
		void imprimir(void);
};
class carrera{
	private:
		string nombre;
		grupo b[2];
	public:
		void leer(void);
		void imprimir(void);
};
class escuela{
	private:
		string nombre;
		carrera c[2];
	public:
		void leer(void);
		void imprimir(void);
};
class ipn{
	private:
		string nombre;
		escuela superior[2];
		escuela media[2];
	public:
		void leer(void);
		void imprimir(void);
};
void ipn::leer(void){
	cout<<"\nIngrese el nombre del instituo";
	fflush(stdin);
	getline(cin,nombre);
	int i;
	for(i=0;i<2;i++){
	    superior[i].leer();
	}
	for(i=0;i<2;i++){
	    media[i].leer();
	}
}
void ipn::imprimir(void){
	cout<<"\nInstituto Superior: "<<nombre;
	int i;
	for(i=0;i<2;i++){
	    superior[i].imprimir();
	}
	cout<<"\nInstituto media: "<<nombre;
	for(i=0;i<2;i++){
	    media[i].imprimir();
	}
}
void escuela::leer(void){
	cout<<"\nIngrese el nombre de la escuela";
	fflush(stdin);
	getline(cin,nombre);
	int i;
	for(i=0;i<2;i++){
	    c[i].leer();
	}
}
void escuela::imprimir(void){
	cout<<"\nEscuela: "<<nombre;
	int i;
	for(i=0;i<2;i++){
	    c[i].imprimir();
	}
}
void carrera::leer(void){
	cout<<"\nIngrese el nombre de la carrera";
	fflush(stdin);
	getline(cin,nombre);
	int i;
	for(i=0;i<2;i++){
	    b[i].leer();
	}
}
void carrera::imprimir(void){
	cout<<"\ncarrera: "<<nombre;
	int i;
	for(i=0;i<2;i++){
	    b[i].imprimir();
	}
}
void grupo::leer(void){
	cout<<"\nIngrese el nombre del grupo";
	fflush(stdin);
	getline(cin,nombre);
	int i;
	for(i=0;i<2;i++){
	    a[i].leer();
	}
}
void grupo::imprimir(void){
	cout<<"\nGrupo: "<<nombre;
	int i;
	for(i=0;i<2;i++){
	    a[i].imprimir();
	}
}
alumno::alumno(void){
	nombre=" "; boleta=" ";
}
alumno::alumno(string N,string B){
	nombre=N;boleta=B;
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
	cout<<"\nEl nombre es: "<<nombre;
	cout<<"\nLa boleta es: "<<boleta;
}
alumno::~alumno(void){
	cout<<"\nDestructor de alumno";
}
int main(void){
	ipn INS;
	INS.leer();
	INS.imprimir();
	
	
/*	escuela E;
	E.leer();
	E.imprimir();
	carrera C;
	C.leer();
	C.imprimir();
	grupo G;
	G.leer();
	G.imprimir();
    alumno *student;
	int ne,i;
	cout<<"Ingrese el numero de alumnos: \n";
	cin>>ne;
	student=new alumno[ne];
	for(i=0;i<ne;i++){
		cout<<"\nAlumno "<<i+1<<"\n";
		student[i].leer();
	}
	for(i=0;i<ne;i++){
		cout<<"Alumno "<<i+1<<"\n";
		student[i].imprimir();
	}
	delete[]student;
	system("pause");
	return 0;*/

}
