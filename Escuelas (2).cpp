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
             string obtenerNombre(void);
             string obtenerBoleta(void);
             void editarNombre(string);
			 void editarBoleta(string);
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
		string obtenerNombre(void);
		void editarNombre(string);
		void obtenerAlumno(void);
		void editarAlumno(void);
		grupo& operator=(const grupo &);
		~grupo(void);
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
	cout<<"\nNombre: "<<nombre;
	cout<<"\nBoleta: "<<boleta;
}
string alumno::obtenerNombre(void){
	return nombre;
}
string alumno::obtenerBoleta(void){
	return boleta;
}
void alumno::editarNombre(string cambioNombre){
	nombre=cambioNombre;
}
void alumno::editarBoleta(string cambioBoleta){
	boleta=cambioBoleta;
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
		cout<<"Grupo vacio";
	}
}
string grupo::obtenerNombre(void){
	return nombre;
}
void grupo::editarNombre(string cambioNombre){
	nombre=cambioNombre;
}
void grupo::obtenerAlumno(void){
	string buscarNombre;
	string buscarBoleta;
	int opcion;
	cout<<"Seleccione como quiere encontrar al alumno";
	cout<<"\nPor nombre ------------ 1";
	cout<<"\nPor boleta ------------ 2";
	cout<<"\nSu opcion ------------- ";
	cin>>opcion;
	switch(opcion){
		case 1:
			cout<<"Ingrese el nombre que desea buscar ";
		    fflush(stdin);
    	    getline(cin,buscarNombre);
	        for(int i=0;i<nunAlumno;i++){
	     	    if(buscarNombre==A[i].obtenerNombre()){
		            cout<<"\nNombre: "<<A[i].obtenerNombre();
				    cout<<"\nBoleta: "<<A[i].obtenerBoleta();
	            }
	        }
		break;
		case 2:
			int i;
		    cout<<"Ingrese la boleta que desea buscar ";
		    fflush(stdin);
		    getline(cin,buscarBoleta);
		    for(int i=0;i<nunAlumno;i++){
			    if(buscarBoleta==A[i].obtenerBoleta()){
				    cout<<"\nNombre: "<<A[i].obtenerNombre();
				    cout<<"\nBoleta: "<<A[i].obtenerBoleta();
			    }
		    }
		break;
		default:
			cout<<"Ingrese una opcion correcta";
		break;
	}
}
void grupo::editarAlumno(void){
	string buscarNombre;
	string buscarBoleta;
	string cambiarNombre;
	string cambiarBoleta;
	int opcion;
	cout<<"Seleccione como quiere encontrar al alumno";
	cout<<"\nPor nombre ------------ 1";
	cout<<"\nPor boleta ------------ 2";
	cout<<"\nSu opcion ------------- ";
	cin>>opcion;
	switch(opcion){
		case 1:
			cout<<"Ingrese el nombre que desea editar ";
		    fflush(stdin);
    	    getline(cin,buscarNombre);
	        for(int i=0;i<nunAlumno;i++){
	     	    if(buscarNombre==A[i].obtenerNombre()){
		            cout<<"\nNombre: "<<A[i].obtenerNombre();
				    cout<<"\nBoleta: "<<A[i].obtenerBoleta();
				    cout<<"\nIngrese el nuevo nombre ";
				    fflush(stdin);
				    getline(cin,cambiarNombre);
				    A[i].editarNombre(cambiarNombre);
				    cout<<"\nEl nuevo nombre es "<<A[i].obtenerNombre();
	            }
	        }
		break;
		case 2:
			int i;
		    cout<<"Ingrese la boleta que desea buscar ";
		    fflush(stdin);
		    getline(cin,buscarBoleta);
		    for(int i=0;i<nunAlumno;i++){
			    if(buscarBoleta==A[i].obtenerBoleta()){
				    cout<<"\nNombre: "<<A[i].obtenerNombre();
				    cout<<"\nBoleta: "<<A[i].obtenerBoleta();
				    cout<<"\nIngrese el nuevo numero de boleta ";
				    fflush(stdin);
				    getline(cin,cambiarBoleta);
				    A[i].editarBoleta(cambiarBoleta);
				    cout<<"\nLa nueva boleta es "<<A[i].obtenerBoleta();
			    }
		    }
		break;
		default:
			cout<<"Ingrese una opcion correcta";
		break;
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
int main(void){
	grupo *group;
	group=NULL;
	int opcion;
	do{
		system("cls");
		cout<<"Menu principal\n";
		cout<<"\nLeer grupo -------------------- 1";
		cout<<"\nImprimir grupo----------------- 2";
		cout<<"\nBuscar alumno en el grupo------ 3";
		cout<<"\nEditar alumno en el grupo------ 4";
		cout<<"\nEditar nombre del grupo-------- 5";
		cout<<"\nSalir del programa------------- 6";
		cout<<"\nSu opcion --------------------- ";cin>>opcion;
		switch(opcion){
			case 1:
				system("cls");
				if(group==NULL){
					group=new grupo[1];
					group[0].leer();
				    cout<<"\n\n";
				    system("pause");
				}
				else{
					cout<<"Ya se han ingresado los datos a este grupo\n\n";
					system("pause");
				}
			break;
			case 2:
				system("cls");
				if(group!=NULL){
					group[0].imprimir();
				}
				else{
					cout<<"Aun no se han ingresado los datos";
				}
				cout<<"\n\n";
				system("pause");
			break;
			case 3:
				system("cls");
				if(group!=NULL){
					group[0].obtenerAlumno();
				}
				else{
					cout<<"Aun no se han ingresado los datos";
				}
				cout<<"\n\n";
				system("pause");
			break;
			case 4:
				system("cls");
				if(group!=NULL){
					group[0].editarAlumno();
				}
				else{
					cout<<"Aun no se han ingresado los datos";
				}
				cout<<"\n\n";
				system("pause");
			break;
			case 5:
				system("cls");
				if(group!=NULL){
					string nombreGroup;
					cout<<"Grupo: "<<group[0].obtenerNombre();
					cout<<"\nIngrese el nuevo nombre ";
					fflush(stdin);
					getline(cin,nombreGroup);
					group[0].editarNombre(nombreGroup);
					cout<<"El nuevo nombre del grupo es "<<group[0].obtenerNombre();
				}
				else{
					cout<<"Aun no se han ingresado los datos";
				}
				cout<<"\n\n";
				system("pause");
			break;
			default:
				if(opcion==6){
				}
				else{
					cout<<"\nIngrese una opcion dentro del menu";
				}
			break;
		}
	}while(opcion!=6);
	delete[]group;
	cout<<"\n\n";
	system("pause");
	return 0;
}
