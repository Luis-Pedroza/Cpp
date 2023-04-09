#include <iostream>
using namespace std;
class Nodo{
	private:
		int Dato;	
		Nodo *AptSig;	
	public:
		Nodo ( void );
		Nodo ( int, Nodo * );
		Nodo ( const Nodo & );
		void Leer ( void );
		void Imprimir ( void );
		void EditarDato ( int );
		void EditarAptSig ( Nodo * );
		int ObtenerDato ( void );
		Nodo *ObtenerAptSig ( void );
		Nodo & operator = ( const Nodo & );
		~Nodo ( void );
};
Nodo :: Nodo ( void ){
	Dato = 0;
	AptSig = NULL;
}
Nodo :: Nodo ( int dato, Nodo *aptsig ){
	Dato = dato;
	AptSig = aptsig;
} 
Nodo :: Nodo ( const Nodo & nodo ){
	Dato = nodo.Dato;
	AptSig = nodo.AptSig;
}
void Nodo :: Leer ( void ){
	cout << "Introduce el Dato: ";
	cin >> Dato;
}
void Nodo :: Imprimir ( void ){
	cout << "Dato: " << Dato << endl;
	cout<<"AptSig: "<<AptSig<<endl;
}
int Nodo :: ObtenerDato ( void ){
	return Dato;
}
Nodo * Nodo :: ObtenerAptSig ( void ){
	return AptSig;
}
void Nodo :: EditarDato ( int dato ){
	Dato = dato;
}
void Nodo :: EditarAptSig ( Nodo *aptsig ){
	AptSig = aptsig;
}
Nodo & Nodo :: operator = ( const Nodo &nodo ){
	if ( this != &nodo)
	{
		this->Dato = nodo.Dato;
		this->AptSig = nodo.AptSig;
	}
	return *this;
}
Nodo :: ~Nodo ( void ){
	cout << "*** Destructor de Nodo ***" << endl;
}
int main(){
	/*Nodo A(25,NULL);
	cout<<"El nodo A es: ";
	A.Imprimir();
	cout<<"La direccion de A es: "<<&A;
	cout<<"\n\n";
	Nodo B(30,&A);
	cout<<"\n\n";
	cout<<"El nodo B es: ";
	B.Imprimir();
	cout<<"La direccion de B es: "<<&B;
	Nodo c(50,&B);
	cout<<"\n\n";
	cout<<"El nodo c es: ";
	c.Imprimir();
	cout<<"La direccion de c es: "<<&c;
	cout<<"\n\n";
	Nodo *inicio;
	inicio=&c;
	cout<<"primer nodo\n";
	inicio->Imprimir();
	cout<<"Segundo nodo\n";
	inicio->ObtenerAptSig()->Imprimir();
	cout<<"Tercer nodo\n";
	inicio->ObtenerAptSig()->ObtenerAptSig()->Imprimir();
	*/
	
	Nodo *nuevoNodo;
	Nodo *inicio;
	nuevoNodo=new Nodo;
	nuevoNodo->Leer();
	inicio=nuevoNodo;
	nuevoNodo=NULL;
	
	nuevoNodo=new Nodo;
	nuevoNodo->Leer();
	nuevoNodo->EditarAptSig(inicio);
	inicio=nuevoNodo;
	nuevoNodo=NULL;
	
	nuevoNodo=new Nodo;
	nuevoNodo->Leer();
	nuevoNodo->EditarAptSig(inicio);
	inicio=nuevoNodo;
	
	nuevoNodo=NULL;
	nuevoNodo=new Nodo;
	nuevoNodo->Leer();
	nuevoNodo->EditarAptSig(inicio);
	inicio=nuevoNodo;
	
	Nodo *apt;
	cout<<"\n\nfor";
	for(apt=inicio;apt!=NULL;apt=apt->ObtenerAptSig()){
		apt->Imprimir();
	}
	
	
	
	
	cout<<"\n\n";
	system("pause");
	delete nuevoNodo;
	return 0;
}
