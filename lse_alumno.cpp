/*Pedroza Moranchel Luis Fernando 3CV8
Lista simplemente enlasada de alumno
*/
#include <iostream>
using namespace std;
class alumno{
	private:
		string nombre;
		string boleta;
	public:
		alumno(void);
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
//**********Fin de clase alumno**********
class nodoAlumno{
	private:
		alumno dato;
		nodoAlumno *aptSig;
	public:
		nodoAlumno(void);
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
//**********Fin de clase nodoAlumno**********
class lse_alumno{
	private:
		nodoAlumno *inicio;
		nodoAlumno *nuevoAlumno;
		nodoAlumno *apt;
	public:
		lse_alumno(void);
		lse_alumno(const lse_alumno &);
		void insertarInicio(void);
		void insertarFinal(void);
		void insertarDespues(void);
		nodoAlumno *obtenerAlumno(string);
		void eliminarInicio(void);
		void eliminarFinal(void);
		void eliminarAlumno(void);
		void editarAlumno(void);
		void imprimir(void);
		lse_alumno &operator=(const lse_alumno &);
		~lse_alumno(void);	
};
//**********Fin de clase lse_alumno**********
alumno::alumno(void){
	nombre=" "; boleta=" ";
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
	cout<<"\n~DESTRUCTOR DE alumno~";
}
//********Fin de la implementacion de clase alumno********
nodoAlumno::nodoAlumno(void){
	aptSig=NULL;
}
nodoAlumno::nodoAlumno(const nodoAlumno &nodo){
	dato=nodo.dato;aptSig=nodo.aptSig;
}
void nodoAlumno::leer(void){
	cout<<"Ingrese los datos:\n";
	dato.leer();
}
void nodoAlumno::imprimir(void){
	dato.imprimir();
	cout<<"\n";
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
	cout<<"\n~DESTRUCTOR DE nodoAlumno~";
}
//**********Fin de la implementacion de clase nodoAlumno*********
lse_alumno::lse_alumno(void){
	inicio=NULL;nuevoAlumno=NULL;apt=NULL;
}
lse_alumno::lse_alumno(const lse_alumno &lista){
	inicio=lista.inicio;nuevoAlumno=lista.nuevoAlumno;apt=lista.apt;
}
void lse_alumno::insertarInicio(void){
	nuevoAlumno=new nodoAlumno;
	if(new nodoAlumno!=NULL){
	    nuevoAlumno->leer();
	    if(inicio==NULL){
		    inicio=nuevoAlumno;
		    cout<<"\nSe inserto el alumno";
	    }
	    else{
		    nuevoAlumno->editarAptSig(inicio);
		    inicio=nuevoAlumno;
		    cout<<"\nSe inserto el alumno";
	    }
	    nuevoAlumno=NULL;	
	}
	else{
		cout<<"\n\nLa memoria esta llena";
	}
}
void lse_alumno::insertarFinal(void){
	if(inicio==NULL){
		insertarInicio();
	}
	else{
		nuevoAlumno=new nodoAlumno;
		if(nuevoAlumno!=NULL){
			apt=inicio;
		    while(apt->obtenerAptSig()!=NULL){
			    apt=apt->obtenerAptSig();
		    }
		    nuevoAlumno->leer();
		    apt->editarAptSig(nuevoAlumno);
		    cout<<"\nSe inserto el alumno";
		}
	}
}
void lse_alumno::insertarDespues(void){
	string boleta;
	int opcion;
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia\n";
		cout<<"\nDesea agregar el elemento a una nueva lista?";
		cout<<"\nSI-------1";
		cout<<"\nNO-------2";
		cout<<"\nopcion---";cin>>opcion;
		cout<<"\n\n";
		switch(opcion){
			case 1:
				insertarInicio();
			break;
			case 2:
				cout<<"\nNo se ingreso ningun elemento";
			break;
			default:
				cout<<"\nIngrese una opcion correcta";
			break;
		}
	}
	else{
		cout<<"\nIngrese la boleta de un alumno en la lista: ";
		fflush(stdin);
		getline(cin,boleta);
		for(apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
			if(apt->obtenerDato().obtenerBoleta()==boleta){
				apt->imprimir();
				cout<<endl;
			}
	    }
		nuevoAlumno=new nodoAlumno;
		if(new nodoAlumno!=NULL){
			apt=inicio;
			while(apt!=NULL&&apt->obtenerDato().obtenerBoleta()!=boleta){
				apt=apt->obtenerAptSig();
			}
			if(apt!=NULL){
				nuevoAlumno->leer();
				nuevoAlumno->editarAptSig(apt->obtenerAptSig());
				apt->editarAptSig(nuevoAlumno);
				nuevoAlumno=NULL;
				cout<<"\nSe inserto el alumno";
			}
			else{
				cout<<"\nNo se encontro el alumno indicado";
				delete nuevoAlumno;
			}
		}
		else{
			cout<<"\nMemoria llena";
		}
	}
}
nodoAlumno *lse_alumno::obtenerAlumno(string boletaBuscar){
	nodoAlumno *nodoEncontrado;
	nodoEncontrado=NULL;
	for (apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		if(apt->obtenerDato().obtenerBoleta()==boletaBuscar){
			nodoEncontrado=apt;
		}
	} 
	return nodoEncontrado;
}
void lse_alumno::eliminarInicio(void){
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		apt=inicio;
		inicio=apt->obtenerAptSig();
		delete apt;
		apt=NULL;
		cout<<"\nSe elimino el alumno";
	}
}
void lse_alumno::eliminarFinal(void){
	nodoAlumno *eliminando;
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		apt=inicio;
		if(apt->obtenerAptSig()==NULL){
			eliminarInicio();
		}
		else{
			while(apt->obtenerAptSig()->obtenerAptSig()!=NULL){
				apt=apt->obtenerAptSig();
			}
			eliminando=apt->obtenerAptSig();
			delete eliminando;
			apt->editarAptSig(NULL);
			eliminando=NULL;
			cout<<"\nSe elimino el alumno";
		}
	}
}
void lse_alumno::eliminarAlumno(void){
	string datoEliminar;
	nodoAlumno *eliminar;
	cout<<"\nIngrese el numero de boleta del alumno que quiere eliminar: ";
	fflush(stdin);
	getline(cin,datoEliminar);
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		if(inicio->obtenerDato().obtenerBoleta()==datoEliminar){
			eliminarInicio();
		}
		else{
			for(apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		        if(apt->obtenerAptSig()->obtenerDato().obtenerBoleta()==datoEliminar){
		        	if(apt->obtenerAptSig()->obtenerAptSig()==NULL){
		        		eliminarFinal();
					}
				    else{
				    	eliminar=apt->obtenerAptSig();
				    	apt->editarAptSig(eliminar->obtenerAptSig());
				    	eliminar->editarAptSig(NULL);
				    	delete eliminar;
				    	eliminar=NULL;
				    	cout<<"\nSe elimino el alumno";
				    	break;
				    }
		        }
	        }
		}
	}
}
void lse_alumno::editarAlumno(void){
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		string boleta;
		string boletaNueva;
		string nombre;
		cout<<"\nIngrese el numero de boleta del alumno que quiere editar: ";
		fflush(stdin);
		getline(cin,boleta);
		apt=inicio;
		while(apt!=NULL&&apt->obtenerDato().obtenerBoleta()!=boleta){
				apt=apt->obtenerAptSig();
			}
			if(apt!=NULL){
				apt->imprimir();
				cout<<"\nIngrese el nuevo nombre del alumno: ";
				fflush(stdin);
	         	getline(cin,nombre);
				cout<<"\nIngrese el nuevo numero de boleta: ";
				fflush(stdin);
	         	getline(cin,boletaNueva);
	         	apt->obtenerDato().editarBoleta(boletaNueva);
		    	apt->obtenerDato().editarNombre(nombre);
		    	cout<<"\n\nSe edito el alumno";
			}
			else{
				cout<<"\nNo se encontro el dato";
			}
	}
}
void lse_alumno::imprimir(void){
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		for(apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		    apt->imprimir();
	    }
	}
}
lse_alumno &lse_alumno::operator=(const lse_alumno &lista){
	if(this!=&lista){
		this->inicio=lista.inicio;
		this->nuevoAlumno=lista.nuevoAlumno;
		this->apt=lista.apt;
	}
	return *this;
}
lse_alumno::~lse_alumno(void){
	nodoAlumno *aux;
	apt=inicio;
	while(apt!=NULL){
		aux=apt;
		apt=apt->obtenerAptSig();
		delete aux;
	}
	cout<<"\n\n~DESTRUCTOR DE lse_alumno~";
}
//**********Fin de la implementacion de clase lse_alumno**********
int main(void){
	lse_alumno lista;
	nodoAlumno *nodoBuscar;
	string boletaBuscar;
	int opcion;
	int variable;
	do{
		system("cls");
		cout<<"LISTA SIMPLEMENTE ENLASADA DE ALUMNO\n";
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"Menu principal\n";
		cout<<"\nInsertar un alumno ------- 1";
		cout<<"\nImprimir ----------------- 2";
		cout<<"\nEliminar un alumno ------- 3";
		cout<<"\nBuscar un alumno --------- 4";
		cout<<"\nEditar un alumno --------- 5";
		cout<<"\nSalir del programa ------- 6";
		cout<<"\nSu opcion ---------------- ";cin>>opcion;
		switch(opcion){
			case 1:
				do{
					int opcion1;
					system("cls");
					cout<<"Insertar un alumno\n";
					cout<<"\nAl inicio ---------------------- 1";
					cout<<"\nAl final ----------------------- 2";
					cout<<"\nDespues de --------------------- 3";
					cout<<"\nRegresar al menu anterior ------ 4";
					cout<<"\nSu opcion ---------------------- ";cin>>opcion1;					
					switch(opcion1){
						case 1:
							cout<<"\nINSERTAR AL INICIO\n\n";
							lista.insertarInicio();
							cout<<"\n\n";
							system("pause");
						break;
						case 2:
							cout<<"\nINSERTAR AL FINAL\n\n";
							lista.insertarFinal();
							cout<<"\n\n";
							system("pause");
						break;
						case 3:
							cout<<"\nINSERTAR DESPUES\n\n";
							lista.insertarDespues();
							cout<<"\n\n";
							system("pause");
						break;
						case 4:
							variable=1;
						break;
						default:
							cout<<"\nIngrese una opcion dentro del menu\n";
				            system("pause");
						break;
					}
				}while(variable!=1);
			break;
			case 2:
				system("cls");
				cout<<"LISTA\n\n";
				lista.imprimir();
				cout<<"\n\n";
				system("pause");
			break;
			case 3:
				do{
					int opcion2;
					system("cls");
					cout<<"Eliminar un alumno\n";
					cout<<"\nAl inicio ---------------------- 1";
					cout<<"\nAl final ----------------------- 2";
					cout<<"\nUn alumno especifico ----------- 3";
					cout<<"\nRegresar al menu anterior ------ 4";
					cout<<"\nSu opcion ---------------------- ";cin>>opcion2;					
					switch(opcion2){
						case 1:
							cout<<"ELIMINAR AL INICIO\n\n";
							lista.eliminarInicio();
							cout<<"\n\n";
							system("pause");
						break;
						case 2:
							cout<<"\nELIMINAR AL FINAL\n\n";
							lista.eliminarFinal();
							cout<<"\n\n";
							system("pause");
						break;
						case 3:
							cout<<"\nELIMINAR ALUMNO\n\n";
							lista.eliminarAlumno();
							cout<<"\n\n";
							system("pause");
						break;
						case 4:
							variable=3;
						break;
						default:
							cout<<"\nIngrese una opcion dentro del menu\n";
				            system("pause");
						break;
					}
				}while(variable!=3);
			break;
			case 4:
				system("cls");
				cout<<"BUSCAR UN ALUMNO\n\n";
				cout<<"\nIngrese la boleta del alumno que quiere buscar: ";
				fflush(stdin);
				getline(cin,boletaBuscar);
				nodoBuscar=lista.obtenerAlumno(boletaBuscar);
				if(nodoBuscar!=NULL){
					cout<<"\nEl alumno es: ";
					nodoBuscar->obtenerDato().imprimir();
				}
				else{
					cout<<"\nNo se encontro el alumno";
				}
				cout<<"\n\n";
				system("pause");
			break;
			case 5:
				system("cls");
				cout<<"EDITAR UN ALUMNO\n\n";
				lista.editarAlumno();
				cout<<"\n\n";
				system("pause");
			break;
			case 6:
				variable=6;
			break;
			default:
				cout<<"\nIngrese una opcion dentro del menu\n";
				system("pause");
			break;
		}
		
	}while(variable!=6);
	cout<<"\n\n";
	system("pause");
	return 0;
}
