#include <iostream>
using namespace std;
class nodo{
	private:
		int dato;		
		nodo *aptSig;
	public:
		nodo ( void );
		nodo ( int, nodo * );
		nodo ( const nodo & );
		void leer ( void );
		void imprimir ( void );
		void editarDato ( int );
		void editarAptSig ( nodo * );
		int obtenerDato ( void );
		nodo *obtenerAptSig ( void );
		nodo & operator = ( const nodo & );
		~nodo ( void );
};
class lseInt{
	private:
		nodo *inicio;
		nodo *nuevoNodo;
		nodo *apt;
	public:
		lseInt();
		void insertarInicio(void);
		void imprimir(void);
		~lseInt(void);	
};
lseInt::lseInt(void){
	inicio=NULL;nuevoNodo=NULL;apt=NULL;
}
void lseInt::insertarInicio(void){
	nuevoNodo=new nodo;
	if(new nodo!=NULL){
	    nuevoNodo->leer();
	    if(inicio==NULL){
		    inicio=nuevoNodo;
	    }
	    else{
		    nuevoNodo->editarAptSig(inicio);
		    inicio=nuevoNodo;
	    }
	    nuevoNodo=NULL;	
	}
	else{
		cout<<"\n\nLa memoria esta llena";
	}
}
void lseInt::imprimir(void){
	if(inicio==NULL){
		cout<<"\n\nLa lista esta vacia";
	}
	else{
		for(apt=inicio;apt!=NULL;apt=apt->obtenerAptSig()){
		    apt->imprimir();
	    }
	}
}
lseInt::~lseInt(void){
	nodo *aux;
	apt=inicio;
	while(apt!=NULL){
		aux=apt;
		apt=apt->obtenerAptSig();
		delete aux;
	}
	cout<<"\n\nDestructor de lseInt";
}
nodo :: nodo ( void ){
	dato = 0;
	aptSig = NULL;
}
nodo :: nodo ( int datos, nodo *aptsig ){
	dato = datos;
	aptSig = aptsig;
} 
nodo :: nodo ( const nodo & node ){
	dato = node.dato;
	aptSig = node.aptSig;
}
void nodo :: leer ( void ){
	cout << "Introduce el Dato: ";
	cin >> dato;
}
void nodo :: imprimir ( void ){
	cout << "Dato: " << dato << endl;
	cout<<"AptSig: "<<aptSig<<endl;
}
int nodo :: obtenerDato ( void ){
	return dato;
}
nodo * nodo :: obtenerAptSig ( void ){
	return aptSig;
}
void nodo :: editarDato ( int datos ){
	dato = datos;
}
void nodo :: editarAptSig ( nodo *aptsig ){
	aptSig = aptsig;
}
nodo & nodo :: operator = ( const nodo &nodoe ){
	if ( this != &nodoe)
	{
		this->dato = nodoe.dato;
		this->aptSig = nodoe.aptSig;
	}
	return *this;
}
nodo :: ~nodo ( void ){
	cout << " Destructor de Nodo " << endl;
}
int main(){
	lseInt lista;
	lista.imprimir();
	lista.insertarInicio();
	lista.insertarInicio();
	lista.insertarInicio();
	lista.insertarInicio();
	lista.insertarInicio();
	lista.imprimir();
	


	cout<<"\n\n";
	system("pause");
	return 0;
}
