/*Pedroza Moranchel Luis Fernando 3CV8
Lista simplemente enlasada de grupo
*/
#include<iostream>
#include<windows.h>
#include<conio.h>
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
		nodoAlumno(const nodoAlumno &);
		void leer(void);
		void imprimir(void);
		alumno &obtenerDato(void);
		nodoAlumno *obtenerAptSig(void);
		void editarDato(alumno &);
		void editarAptSig(nodoAlumno *);
		nodoAlumno&operator=(const nodoAlumno &);
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
class grupo{
	private:
		string nombre;
	    lse_alumno *alumnos;
	public:
		grupo(void);
		grupo(const grupo &);
		void leer(void);
		void imprimir(void);
		string obtenerNombre(void);
		lse_alumno *obtenerLista(void);
		void editarNombre(string);
		void editarLista(lse_alumno *);
		grupo &operator=(const grupo &);
		~grupo(void);
};
//**********Fin de clase grupo**********
class nodoGrupo{
	private:
		grupo lista;
		nodoGrupo *aptSig;
	public:
		nodoGrupo(void);
		nodoGrupo(const nodoGrupo &);
		void leer(void);
		void imprimir(void);
		grupo &obtenerLista(void);
		nodoGrupo *obtenerAptSig(void);
		void editarLista(grupo &);
		void editarAptSig(nodoGrupo *);
		nodoGrupo&operator=(const nodoGrupo &);
		~nodoGrupo(void);
};
//**********Fin de clase nodoGrupo**********
class lse_grupo{
	private:
		nodoGrupo *inicio;
		nodoGrupo *nuevoGrupo;
		nodoGrupo *apt;
	public:
		lse_grupo(void);
		lse_grupo(const lse_grupo &);
		void insertarInicio(void);
		void insertarFinal(void);
		void insertarDespues(void);
		nodoGrupo *obtenerGrupo(string);
		void eliminarInicio(void);
		void eliminarFinal(void);
		void eliminarGrupo(void);
		void editarGrupo(void);
		void imprimir(void);
		lse_grupo &operator=(const lse_grupo &);
		~lse_grupo(void);
		
};
//**********Fin de clase lse_grupo**********
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
	cout<<"\nDATOS DEL ALUMNO\n";
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
		    cout<<"\n***Se inserto el alumno***";
		    Sleep(500);
	    }
	    else{
		    nuevoAlumno->editarAptSig(inicio);
		    inicio=nuevoAlumno;
		    cout<<"\n***Se inserto el alumno***";
		    Sleep(500);
	    }
	    nuevoAlumno=NULL;	
	}
	else{
		cout<<"\n***La memoria esta llena***";
		Sleep(500);
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
		    cout<<"\n***Se inserto el alumno***";
		    Sleep(500);
		}
	}
}
void lse_alumno::insertarDespues(void){
	string boleta;
	int opcion;
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***\n";
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
				cout<<"\n***No se ingreso ningun elemento***";
				Sleep(500);
			break;
			default:
				cout<<"\n***Ingrese una opcion correcta***";
				Sleep(500);
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
				cout<<"\n***Se inserto el alumno***";
				Sleep(1000);
			}
			else{
				cout<<"\n***No se encontro el alumno indicado***";
				delete nuevoAlumno;
				Sleep(1000);
			}
		}
		else{
			cout<<"\n***Memoria llena***";
			Sleep(1000);
		}
	}
}
nodoAlumno *lse_alumno::obtenerAlumno(string boletaBuscar){
	nodoAlumno *nodoEncontrado;
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
	}
	else{
	    nodoEncontrado=NULL;
	    for (apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		    if(apt->obtenerDato().obtenerBoleta()==boletaBuscar){
			    nodoEncontrado=apt;
		    }
	    } 
	    return nodoEncontrado;
	}
}
void lse_alumno::eliminarInicio(void){
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
		Sleep(500);
	}
	else{
		apt=inicio;
		inicio=apt->obtenerAptSig();
		delete apt;
		apt=NULL;
		cout<<"\n***Se elimino el alumno***";
		Sleep(500);
	}
}
void lse_alumno::eliminarFinal(void){
	nodoAlumno *eliminando;
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
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
			cout<<"\n***Se elimino el alumno***";
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
		cout<<"\n***La lista esta vacia***";
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
				    	cout<<"\n***Se elimino el alumno***";
				    	break;
				    }
		        }
	        }
		}
	}
}
void lse_alumno::editarAlumno(void){
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
		Sleep(500);
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
		    	cout<<"\n***Se edito el alumno***";
		    	Sleep(500);
			}
			else{
				cout<<"\n***No se encontro el dato***";
				Sleep(500);
			}
	}
}
void lse_alumno::imprimir(void){
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
		Sleep(500);
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
grupo::grupo(void){
	nombre=" ";alumnos=NULL;
}
grupo::grupo(const grupo &group){
	nombre=group.nombre;alumnos=group.alumnos;
}
void grupo::leer(void){
	int variable;
	unsigned char tecla;
	cout<<"\nIngrese el nombre del grupo: ";
	fflush(stdin);
	getline(cin,nombre);
	alumnos=new lse_alumno;
	do{
		alumnos->insertarFinal();
		cout<<"\nPrecione Enter para seguir ingresando alumnos o Esc para salir: ";
		tecla=getch();
	}while(tecla!=27);
}
void grupo::imprimir(void){
	cout<<"\nGrupo: "<<nombre;
	if(alumnos!=NULL){
	    alumnos->imprimir();
	    cout<<"-------";
	}
	else{
		cout<<"\n***Grupo vacio***";
		Sleep(500);
	}
}
string grupo::obtenerNombre(void){
	return nombre;
}
lse_alumno *grupo::obtenerLista(void){
	return alumnos;
}
void grupo::editarNombre(string NOMBRE){
	nombre=NOMBRE;
}
void grupo::editarLista(lse_alumno *lista){
	alumnos=lista;
}
grupo &grupo::operator=(const grupo &group){
	if(this!=&group){
		this->nombre=group.nombre;
		this->alumnos=group.alumnos;
	}
	return *this;
}
grupo::~grupo(void){
	delete alumnos;
	cout<<"\n~DESTRUCTOR DE grupo~";
}
//**********Fin de la implementacion de clase grupo**********
nodoGrupo::nodoGrupo(void){
	aptSig=NULL;
}
nodoGrupo::nodoGrupo(const nodoGrupo &nodo){
	lista=nodo.lista;aptSig=nodo.aptSig;
}
void nodoGrupo::leer(void){
	cout<<"\nDATOS DEL GRUPO\n";
	lista.leer();
}
void nodoGrupo::imprimir(void){
	lista.imprimir();
	cout<<"\n";
}
grupo &nodoGrupo::obtenerLista(void){
	return lista;
}
nodoGrupo *nodoGrupo::obtenerAptSig(void){
	return aptSig;
}
void nodoGrupo::editarLista(grupo &listaAlumnos){
	lista=listaAlumnos;
}
void nodoGrupo::editarAptSig(nodoGrupo *sigApt){
	aptSig=sigApt;
}
nodoGrupo &nodoGrupo::operator=(const nodoGrupo &nodo){
	if(this!=&nodo){
		this->lista=nodo.lista;
		this->aptSig=nodo.aptSig;
	}
	return *this;
}
nodoGrupo::~nodoGrupo(void){
	cout<<"\n~DESTRUCTOR DE nodoGrupo~";
}
//**********Fin de la implementacion de clase nodoGruo**********
lse_grupo::lse_grupo(void){
	inicio=NULL;nuevoGrupo=NULL;apt=NULL;
}
lse_grupo::lse_grupo(const lse_grupo &lista){
	inicio=lista.inicio;nuevoGrupo=lista.nuevoGrupo;apt=lista.apt;
}
void lse_grupo::insertarInicio(void){
	nuevoGrupo=new nodoGrupo;
	if(new nodoGrupo!=NULL){
	    nuevoGrupo->leer();
	    if(inicio==NULL){
		    inicio=nuevoGrupo;
		    cout<<"\n\n***Se inserto el grupo***";
		    Sleep(500);
	    }
	    else{
		    nuevoGrupo->editarAptSig(inicio);
		    inicio=nuevoGrupo;
		    cout<<"\n\n***Se inserto el grupo***";
		    Sleep(500);
	    }
	    nuevoGrupo=NULL;	
	}
	else{
		cout<<"\n\n***La memoria esta llena***";
		Sleep(500);
	}
}
void lse_grupo::insertarFinal(void){
	if(inicio==NULL){
		insertarInicio();
	}
	else{
		nuevoGrupo=new nodoGrupo;
		if(nuevoGrupo!=NULL){
			apt=inicio;
		    while(apt->obtenerAptSig()!=NULL){
			    apt=apt->obtenerAptSig();
		    }
		    nuevoGrupo->leer();
		    apt->editarAptSig(nuevoGrupo);
		    cout<<"\n\n***Se inserto el grupo***";
		    Sleep(500);
		}
	}
}
void lse_grupo::insertarDespues(void){
	string nombreGrupo;
	int opcion;
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***\n";
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
				cout<<"\n***No se ingreso ningun elemento***";
				Sleep(500);
			break;
			default:
				cout<<"\n***Ingrese una opcion correcta***";
				Sleep(500);
			break;
		}
	}
	else{
		cout<<"\nIngrese el nombre de un grupo en la lista: ";
		fflush(stdin);
		getline(cin,nombreGrupo);
		nuevoGrupo=new nodoGrupo;
		if(new nodoGrupo!=NULL){
			apt=inicio;
			while(apt!=NULL&&apt->obtenerLista().obtenerNombre()!=nombreGrupo){
				apt=apt->obtenerAptSig();
			}
			if(apt!=NULL){
				nuevoGrupo->leer();
				nuevoGrupo->editarAptSig(apt->obtenerAptSig());
				apt->editarAptSig(nuevoGrupo);
				nuevoGrupo=NULL;
				cout<<"\n***Se inserto el grupo***";
				Sleep(500);
			}
			else{
				cout<<"\n***No se encontro el grupo indicado***\n";
				delete nuevoGrupo;
				Sleep(500);
			}
		}
		else{
			cout<<"\n***Memoria llena***";
			Sleep(500);
		}
	}
}
nodoGrupo *lse_grupo::obtenerGrupo(string nombreGrupo){
	nodoGrupo *nodoEncontrado;
	nodoEncontrado=NULL;
	for (apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		if(apt->obtenerLista().obtenerNombre()==nombreGrupo){
			nodoEncontrado=apt;
		}
	} 
	return nodoEncontrado;
}
void lse_grupo::eliminarInicio(void){
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
	}
	else{
		apt=inicio;
		inicio=apt->obtenerAptSig();
		delete apt;
		apt=NULL;
	}
}
void lse_grupo::eliminarFinal(void){
	nodoGrupo *eliminando;
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
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
			cout<<"\n***Se elimino el grupo***";
			Sleep(500);
		}
	}
}
void lse_grupo::eliminarGrupo(void){
	string datoEliminar;
	nodoGrupo *eliminar;
	cout<<"\nIngrese el nombre del grupo que quiere eliminar: ";
	fflush(stdin);
	getline(cin,datoEliminar);
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
	}
	else{
		if(inicio->obtenerLista().obtenerNombre()==datoEliminar){
			eliminarInicio();
		}
		else{
			for(apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		        if(apt->obtenerAptSig()->obtenerLista().obtenerNombre()==datoEliminar){
		        	if(apt->obtenerAptSig()->obtenerAptSig()==NULL){
		        		eliminarFinal();
					}
				    else{
				    	eliminar=apt->obtenerAptSig();
				    	apt->editarAptSig(eliminar->obtenerAptSig());
				    	eliminar->editarAptSig(NULL);
				    	delete eliminar;
				    	eliminar=NULL;
				    	cout<<"\n***Se elimino el grupo***";
				    	break;
				    }
		        }
	        }
		}
	}
}
void lse_grupo::editarGrupo(void){
	int opcion;
	int variable;
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
		Sleep(500);
	}
	else{
		string nombreGrupo;
		string grupoNuevo;
		cout<<"\nIngrese el nombre del grupo que quiere editar: ";
		fflush(stdin);
		getline(cin,nombreGrupo);
		apt=inicio;
		while(apt!=NULL&&apt->obtenerLista().obtenerNombre()!=nombreGrupo){
				apt=apt->obtenerAptSig();
			}
			if(apt!=NULL){
				apt->imprimir();
				cout<<"\nIngrese el nuevo nombre del grupo: ";
				fflush(stdin);
	         	getline(cin,grupoNuevo);
	         	apt->obtenerLista().editarNombre(grupoNuevo);
	         	do{
	         		system("cls");
	         		cout<<"\n\nElija una opcion";
	         	    cout<<"\nInsertar nuevo alumno ------ 1";
	         	    cout<<"\nEliminar un alumno --------- 2";
	         	    cout<<"\nEditar un alumno ----------- 3";
	         	    cout<<"\nSalir ---------------------- 4";
	         	    cout<<"\nSu opcion -------------------";cin>>opcion;
	         	    switch(opcion){
	         		    case 1:
	         			    apt->obtenerLista().obtenerLista()->insertarFinal();
	         		    break;
	         		    case 2:
	         			  apt->obtenerLista().obtenerLista()->eliminarAlumno();
	         		    break;
	         		    case 3:
	         		    	apt->obtenerLista().obtenerLista()->editarAlumno();
	         		    break;
	         		    case 4:
	         			    variable=4;
	         		    break;
	         		    default:
	         			    cout<<"\n***Ingrese una opcion correcta***";
				            Sleep(500);
	         		    break;
				     }
				 }while(variable!=4);
				 cout<<"\n***Se edito el grupo***";
			}
			else{
				cout<<"\n***No se encontro el dato***";
				Sleep(500);
			}
	}
}
void lse_grupo::imprimir(void){
	if(inicio==NULL){
		cout<<"\n***La lista esta vacia***";
	}
	else{
		for(apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		    apt->imprimir();
		    
	    }
	}
}
lse_grupo &lse_grupo::operator=(const lse_grupo &lista){
	if(this!=&lista){
		this->inicio=lista.inicio;
		this->nuevoGrupo=lista.nuevoGrupo;
		this->apt=lista.apt;
	}
	return *this;
}
lse_grupo::~lse_grupo(void){
	nodoGrupo *aux;
	apt=inicio;
	while(apt!=NULL){
		aux=apt;
		apt=apt->obtenerAptSig();
		delete aux;
	}
	cout<<"\n\n~DESTRUCTOR DE lse_grupo~";
}
//**********Final de la implementacion de clase lse_grupo**********
int main(void){
	lse_grupo lista;
	nodoGrupo *nodoBuscar;
	string nombreGrupo;
	int opcion;
	int variable;
	do{
		system("cls");
		cout<<"LISTA SIMPLEMENTE ENLASADA DE GRUPO\n";
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"Menu principal\n";
		cout<<"\nInsertar un grupo ------- 1";
		cout<<"\nImprimir ---------------- 2";
		cout<<"\nEliminar un grupo ------- 3";
		cout<<"\nBuscar un grupo --------- 4";
		cout<<"\nEditar un grupo --------- 5";
		cout<<"\nSalir del programa ------ 6";
		cout<<"\nSu opcion --------------- ";cin>>opcion;
		switch(opcion){
			case 1:
				do{
					int opcion1;
					system("cls");
					cout<<"Insertar un grupo\n";
					cout<<"\nAl inicio ---------------------- 1";
					cout<<"\nAl final ----------------------- 2";
					cout<<"\nDespues de --------------------- 3";
					cout<<"\nRegresar al menu anterior ------ 4";
					cout<<"\nSu opcion ---------------------- ";cin>>opcion1;					
					switch(opcion1){
						case 1:
							system("cls");
							cout<<"INSERTAR AL INICIO\n\n";
							lista.insertarInicio();
							cout<<"\n\n";
							system("pause");
						break;
						case 2:
							system("cls");
							cout<<"INSERTAR AL FINAL\n\n";
							lista.insertarFinal();
							cout<<"\n\n";
							system("pause");
						break;
						case 3:
							system("cls");
							cout<<"INSERTAR DESPUES\n\n";
							lista.insertarDespues();
							cout<<"\n\n";
							system("pause");
						break;
						case 4:
							variable=1;
						break;
						default:
							cout<<"\n***Ingrese una opcion dentro del menu***\n";
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
					cout<<"Eliminar un grupo\n";
					cout<<"\nAl inicio ---------------------- 1";
					cout<<"\nAl final ----------------------- 2";
					cout<<"\nUn grupo especifico ------------ 3";
					cout<<"\nRegresar al menu anterior ------ 4";
					cout<<"\nSu opcion ---------------------- ";cin>>opcion2;					
					switch(opcion2){
						case 1:
							cout<<"\nELIMINAR AL INICIO\n\n";
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
							cout<<"\nELIMINAR AL GRUPO\n\n";
							lista.eliminarGrupo();
							cout<<"\n\n";
							system("pause");
						break;
						case 4:
							variable=3;
						break;
						default:
							cout<<"\n***Ingrese una opcion dentro del menu***\n";
				            system("pause");
						break;
					}
				}while(variable!=3);
			break;
			case 4:
				system("cls");
				cout<<"BUSCAR UN GRUPO\n\n";
				cout<<"\nIngrese el nombre del grupo que quiere buscar: ";
				fflush(stdin);
				getline(cin,nombreGrupo);
				nodoBuscar=lista.obtenerGrupo(nombreGrupo);
				if(nodoBuscar!=NULL){
					cout<<"\nEl grupo es: ";
					nodoBuscar->obtenerLista().imprimir();
				}
				else{
					cout<<"\n***No se encontro el grupo***";
					Sleep(500);
				}
				cout<<"\n\n";
				system("pause");
			break;
			case 5:
				system("cls");
				cout<<"EDITAR UN GRUPO\n\n";
				lista.editarGrupo();
				cout<<"\n\n";
				system("pause");
			break;
			case 6:
				variable=6;
			break;
			default:
				cout<<"\n***Ingrese una opcion dentro del menu***\n";
				system("pause");
			break;
		}
		
	}while(variable!=6);
	cout<<"\n\n";
	system("pause");
	return 0;
}
