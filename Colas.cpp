#include <iostream>
using namespace std;
class nodo{
	private:
		int dato;		
		nodo *aptSig;
	public:
		nodo(void);
		nodo(int,nodo *);
		nodo(const nodo &);
		void leer(void);
		void imprimir(void);
		int obtenerDato(void);
		nodo *obtenerAptSig(void);
		void editarDato(int);
		void editarAptSig(nodo *);
		nodo &operator=(const nodo &);
		~nodo(void);
};
//**********Fin de clase nodo**********
class lse_int{
	//protected para ver el estado de la pila
	protected:
		nodo *inicio;
		nodo *nuevoNodo;
		nodo *apt;
	public:
		lse_int(void);
		lse_int(const lse_int &);
		void insertarInicio(void);
		void insertarFinal(void);
		void insertarDespues(void);
		nodo *obtenerNodo(int);
		void eliminarInicio(void);
		void eliminarFinal(void);
		void eliminarNodo(void);
		void editarNodo(void);
		void imprimir(void);
		lse_int &operator=(const lse_int &);
		~lse_int(void);	
};
//**********Fin de clase lse_int**********
class cola_int:private lse_int{
	public:
		void poner(void);
		void quitar(void);
		void estado(void); 
		void imprimirPila(void);
};
//**********Fin de clase cola_int**********
nodo::nodo(void){
	dato=0;aptSig=NULL;
}
nodo::nodo(int info,nodo *sigApt){
	dato=info;aptSig=sigApt;
} 
nodo::nodo(const nodo &node){
	dato=node.dato;aptSig=node.aptSig;
}
void nodo::leer(void){
	cout<<"\nIngrese un numero entero - ";
	cin>>dato;
}
void nodo::imprimir(void){
	cout<<"\nDato: "<<dato;
}
int nodo::obtenerDato(void){
	return dato;
}
nodo *nodo::obtenerAptSig(void){
	return aptSig;
}
void nodo::editarDato(int info){
	dato=info;
}
void nodo::editarAptSig(nodo *sigApt){
	aptSig=sigApt;
}
nodo &nodo::operator=(const nodo &node){
	if (this!=&node){
		this->dato=node.dato;
		this->aptSig=node.aptSig;
	}
	return *this;
}
nodo::~nodo(void){
	cout<<"\n\n~DESTRUCTOR DE nodo~";
}
//**********Fin de la implementacion de clase nodo**********
lse_int::lse_int(void){
	inicio=NULL;nuevoNodo=NULL;apt=NULL;
}
lse_int::lse_int(const lse_int &lista){
	inicio=lista.inicio;nuevoNodo=lista.nuevoNodo;apt=lista.apt;
}
void lse_int::insertarInicio(void){
	nuevoNodo=new nodo;
	if(new nodo!=NULL){
	    nuevoNodo->leer();
	    if(inicio==NULL){
		    inicio=nuevoNodo;
		    cout<<"\nSe inserto el dato";
	    }
	    else{
		    nuevoNodo->editarAptSig(inicio);
		    inicio=nuevoNodo;
		    cout<<"\nSe inserto el dato";
	    }
	    nuevoNodo=NULL;	
	}
	else{
		cout<<"\n\nLa memoria esta llena";
	}
}
void lse_int::insertarFinal(void){
	if(inicio==NULL){
		insertarInicio();
	}
	else{
		nuevoNodo=new nodo;
		if(nuevoNodo!=NULL){
			apt=inicio;
		    while(apt->obtenerAptSig()!=NULL){
			    apt=apt->obtenerAptSig();
		    }
		    nuevoNodo->leer();
		    apt->editarAptSig(nuevoNodo);
		}
		cout<<"\nSe inserto el dato";
	}
}
void lse_int::insertarDespues(void){
	int opcion;
	int datoBuscar;
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
		cout<<"\nDesea agregar el elemento a una nueva lista?";
		cout<<"\nSI-------1";
		cout<<"\nNO-------2";
		cout<<"\nopcion---";cin>>opcion;
		switch(opcion){
			case 1:
				insertarInicio();
				cout<<"\nSe inserto el dato";
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
		cout<<"\nIngrese el dato en la lista: ";cin>>datoBuscar;
		nuevoNodo=new nodo;
		if(new nodo!=NULL){
			apt=inicio;
			while(apt!=NULL&&apt->obtenerDato()!=datoBuscar){
				apt=apt->obtenerAptSig();
			}
			if(apt!=NULL){
				nuevoNodo->leer();
				nuevoNodo->editarAptSig(apt->obtenerAptSig());
				apt->editarAptSig(nuevoNodo);
				nuevoNodo=NULL;
				cout<<"\nSe inserto el dato despues";
			}
			else{
				cout<<"\nNo se encontro el dato indicado";
				delete nuevoNodo;
			}
		}
		else{
			cout<<"\nMemoria llena";
		}
	}
}
nodo *lse_int::obtenerNodo(int datoBuscar){
	nodo *nodoEncontrado;
	nodoEncontrado=NULL;
	for (apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		if(apt->obtenerDato()==datoBuscar){
			nodoEncontrado=apt;
		}
	} 
	return nodoEncontrado;
}
void lse_int::eliminarInicio(void){
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		apt=inicio;
		inicio=apt->obtenerAptSig();
		delete apt;
		apt=NULL;
		cout<<"\nSe elimino el dato";
	}
}
void lse_int::eliminarFinal(void){
	nodo *eliminando;
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
			cout<<"\nSe elimino el dato";
		}
	}
}
void lse_int::eliminarNodo(void){
	int datoEliminar,variable;
	nodo *eliminar;
	cout<<"\nIngrese el dato que quiere eliminar: ";cin>>datoEliminar;
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		if(inicio->obtenerDato()==datoEliminar){
			eliminarInicio();
		}
		else{
			for(apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		        if(apt->obtenerAptSig()->obtenerDato()==datoEliminar){
		        	if(apt->obtenerAptSig()->obtenerAptSig()==NULL){
		        		eliminarFinal();
					}
				    else{
				    	eliminar=apt->obtenerAptSig();
				    	apt->editarAptSig(eliminar->obtenerAptSig());
				    	eliminar->editarAptSig(NULL);
				    	delete eliminar;
				    	eliminar=NULL;
				    	cout<<"\nSe elimino el nodo";
				    	break;
				    }
		        }
	        }
		}
	}
}
void lse_int::editarNodo(void){
	int datoBuscar;
	int datoNuevo;
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		cout<<"\nIngrese el dato que quiere editar: ";cin>>datoBuscar;
		cout<<"\nIngrese el nuevo dato: ";cin>>datoNuevo;
		apt=inicio;
		while(apt!=NULL&&apt->obtenerDato()!=datoBuscar){
				apt=apt->obtenerAptSig();
			}
			if(apt!=NULL){
				apt->editarDato(datoNuevo);
				cout<<"\nSe edito el nodo";
			}
			else{
				cout<<"\nNo se encontro el dato";
			}
	}
}
void lse_int::imprimir(void){
	if(inicio==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		for(apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		    apt->imprimir();
	    }
	}
}
lse_int &lse_int::operator=(const lse_int &lista){
	if(this!=&lista){
		this->inicio=lista.inicio;
		this->nuevoNodo=lista.nuevoNodo;
		this->apt=lista.apt;
	}
	return *this;
}
lse_int::~lse_int(void){
	nodo *aux;
	apt=inicio;
	while(apt!=NULL){
		aux=apt;
		apt=apt->obtenerAptSig();
		delete aux;
	}
	cout<<"\n\n~DESTRUCTOR DE lse_int~";
}
//**********Fin de la implementacion de clase lse_int**********
void cola_int::poner(void){
	insertarInicio();
}
void cola_int::quitar(void){
	eliminarFinal();
}
void cola_int::estado(void){
	if(inicio==NULL){
		cout<<"\nLa pila esta vacia";
	}
	else{
		cout<<"\nLa pila tiene elementos";
	}
}
void cola_int::imprimirPila(void){
	imprimir();
}
//**********Fin de la implementacion de clase cola_int**********
int main(void){
	cola_int cola;
	int opcion,variable=0;
do{
		system("cls");
		cout<<"Menu principal\n";
		cout<<"\nPoner elemento ------- 1";
		cout<<"\nQuitar elemento ------ 2";
		cout<<"\nEstado --------------- 3";
		cout<<"\nImprimir ------------- 4";
		cout<<"\nSalir ---------------- 5";
		cout<<"\nSu opcion ------------ ";cin>>opcion;
		switch(opcion){
			case 1:
				cola.poner();
				cout<<"\n\n";
				system("pause");
			break;
			case 2:
				cola.quitar();
				cout<<"\n\n";
				system("pause");
			break;	
			case 3:
				cola.estado();
				cout<<"\n\n";
				system("pause");
			break;
			case 4:
				cola.imprimirPila();
				cout<<"\n\n";
				system("pause");
			break;
			case 5:
				variable=5;
			break;
			default:
				cout<<"\nIngrese una opcion dentro del menu";
				cout<<"\n\n";
				system("pause");
			break;
		}
	}while(variable!=5);
	cout<<"\n\n";
	system("pause");
	return 0;
}
