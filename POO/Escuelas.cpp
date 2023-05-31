#include<iostream>
using namespace std;
class alumno{
      private:
              string nombre;
              string boleta;
      public:
             alumno(void);
             alumno(string,string);
             alumno(const alumno&);
             void leer(void);
             void imprimir(void);
             alumno& operator=(const alumno &);
             ~alumno(void);
};
class grupo{
	private:
	    string nombre;
	    alumno *A;
	    int nunAlumno;
	public:
		grupo(void);
		grupo(string,int);
		grupo(const grupo &);
		void leer(void);
		void imprimir(void);
		grupo& operator=(const grupo &);
		~grupo(void);
};
class escuela{
	private:
		string nombre;
		grupo *G;
		int numGrupo;
	public:
		escuela(void);
		escuela(string,int);
		escuela(escuela &);
		void leer(void);
		void imprimir(void);
		escuela& operator=(const escuela &);
		~escuela(void);
};
escuela::escuela(void){
	nombre=" ";numGrupo=0;G=NULL;
}
escuela::escuela(string N,int NUM){
	nombre=N;numGrupo=NUM;
	if(numGrupo!=0){
		G=new grupo[numGrupo];
	}
	else{
		G=NULL;
	}
}
escuela::escuela(escuela &instituto){
	nombre=instituto.nombre;numGrupo=instituto.numGrupo;
	if(instituto.G!=NULL){
		G=new grupo[numGrupo];
		for(int i=0;i<numGrupo;i++){
			G[i]=instituto.G[i];
		}
	}
	else{
		G=instituto.G;
	}
}
void escuela::leer(void){
	int i;
	if(nombre==" "){
		cout<<"\nIngrese el nombre de la escuela: ";
    	fflush(stdin);
    	getline(cin,nombre);
	}
	if(G==NULL){
		cout<<"\nIngrese el numero de grupos: ";cin>>numGrupo;
	    G=new grupo[numGrupo];
    	for(i=0;i<numGrupo;i++){
	    G[i].leer();
	}
	}
	else{
		cout<<"Ingrese datos del grupo "<<nombre;
		for(i=0;i<numGrupo;i++){
			G[i].leer();
		}
	}
}
void escuela::imprimir(void){
	cout<<"\nEscuela: "<<nombre;
	int i;
	if(G!=NULL){
		for(i=0;i<numGrupo;i++){
	    G[i].imprimir();
    	}
	}
	else{
		cout<<"Escuela vacía";
	}
}
escuela& escuela::operator=(const escuela &instituto){
	if(this!=&instituto){
		this->nombre=instituto.nombre;
		this->numGrupo=instituto.numGrupo;
		if(instituto.G!=NULL){
			this->G=new grupo[numGrupo];
			for(int i=0;i<numGrupo;i++){
				this->G[i]=instituto.G[i];
			}
		}
		else{
			this->G=instituto.G;
		}
	}
	return *this;
}
escuela::~escuela(void){
	if(G!=NULL){
		delete[]G;
	}
	cout<<"\nDestructor de escuela";
}
grupo::grupo(void){
	nombre=" ";nunAlumno=0;A=NULL;
}
grupo::grupo(string N,int NUN){
	nombre=N;nunAlumno=NUN;
	if(nunAlumno!=0){
		A=new alumno[nunAlumno];
	}
	else{
		A=NULL;
	}
}
grupo::grupo(const grupo &conjunto){
	nombre=conjunto.nombre;nunAlumno=conjunto.nunAlumno;
	if(conjunto.A!=NULL){
		A=new alumno[nunAlumno];
		for(int i=0;i<nunAlumno;i++){
			A[i]=conjunto.A[i];
		}
	}
	else{
		A=conjunto.A;
	}
}
void grupo::leer(void){
	int i;
	if(nombre==" "){
		cout<<"\nIngrese el nombre del grupo: ";
	    fflush(stdin);
	    getline(cin,nombre);
	}
	if(A==NULL){
		cout<<"\nIngrese el numero de alumnos: ";cin>>nunAlumno;
	    A=new alumno[nunAlumno];
	    for(i=0;i<nunAlumno;i++){
	    A[i].leer();
	} 
	}
	else{
		cout << "\n Ingrese datos del alumno " << nombre;
		for ( i = 0; i < nunAlumno; i++ ){
			A[i].leer();
	    }
	}
}
void grupo::imprimir(void){
	cout<<"\nGrupo: "<<nombre;
	int i;
	if(A!=NULL){
		for(i=0;i<nunAlumno;i++){
	    A[i].imprimir();
	    }
	}
	else{
		cout<<"Grupo vació";
	}
}
grupo& grupo::operator=(const grupo &conjunto){
	if (this != &conjunto){
		this->nombre=conjunto.nombre;
		this->nunAlumno=conjunto.nunAlumno;
		if (conjunto.A != NULL){
			this->A = new alumno [nunAlumno];
			for (int i=0;i<nunAlumno;i++){
				this->A[i] = conjunto.A[i];
			}
		}
		else{
			this->A = conjunto.A;
		}
	}
	return *this;
}
grupo::~grupo(void){
	if(A!=NULL){
		delete[]A;
	}
	cout<<"\nDestructor de grupo";
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
	cout<<"\nNombre: "<<nombre;
	cout<<"\nBoleta: "<<boleta;
}
alumno& alumno::operator=(const alumno &estudiante){
	if(this!=&estudiante){
		this->nombre=estudiante.nombre;this->boleta=estudiante.boleta;
	}
	return *this;
}
alumno::~alumno(void){
	cout<<"\nDestructor de alumno";
}
int main(void){
    escuela E;
	E.leer();
	E.imprimir();
	cout<<"\n";
	system("pause");
	return 0;
}
