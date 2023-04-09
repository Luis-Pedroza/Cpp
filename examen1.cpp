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
	alumno *student;
	int ne,i;
	cout<<"Ingrese el numero de alumnos: ";
	cin>>ne;
	student=new alumno[ne];
	for(i=0;i<ne;i++){
		cout<<"Alumno "<<i+1<<"\n";
		student[i].leer();
	}
	for(i=0;i<ne;i++){
		cout<<"Alumno "<<i+1<<"\n";
		student[i].imprimir();
	}
	delete[]student;
	system("pause");
	return 0;
}
