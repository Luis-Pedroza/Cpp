#include<iostream>	
#include<string.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class persona
{   protected:
		string nombre,genero;
		int edad;
	public:
		void inicializarPersona(string,string,int);
		void imprimirPersona();
};
class cliente:public persona
{   float cntaAhorro,cntaCredito,nip;
	public:
		void inicializarCliente(long int,long int,int);
		void imprimirCliente();
};
class cuentas
{   float ahorro,credito;
	public:
	void inicializarAhorro(float);
	void inicializarCredito(float);
	void imprimirAhorro();
	void imprimirCredito();
	friend class retiro;
	friend class pagos;
	friend class transferir;
};
class transferir
{   float dinero,dinerotran1,dinerotran2;
    public:
	void transferirAhorro3(cuentas *saldo);
	void transferirCredito3(cuentas *saldo);
	friend class cuentas;
};
class retiro
{   float cantidadRetiro,NBalance;
	public:
	void retiroAhorro(cuentas *saldo);
	void retiroCredito(cuentas *saldo);
	friend class cuentas;
};
class pagos
{   float monto,pagofinal;
	public:
	void pagosAhorro2(cuentas *saldo);
	void pagosCredito2(cuentas *saldo);
	friend class cuentas;	
};
void persona::inicializarPersona(string Nombre,string Genero,int Edad)
{
	nombre=Nombre;genero=Genero;edad=Edad;
}
void persona::imprimirPersona()
{
	cout<<"\nNombre "<<nombre<<"\nGenero "<<genero<<"\nEdad "<<edad;
}
void cliente::inicializarCliente(long int cuentaAhorro,long int cuentaCredito,int NIP)
{
	cntaAhorro=cuentaAhorro;cntaCredito=cuentaCredito;nip=NIP;
}
void cliente::imprimirCliente()
{
	cout<<"\nCuenta de Ahorro "<<cntaAhorro<<"\nCuenta de Credito "<<cntaCredito<<"\nNip "<<nip;
}
void cuentas::inicializarAhorro(float Ahorro)
{
	ahorro=Ahorro;
}
void cuentas::inicializarCredito(float Credito)
{
	credito=Credito;
}
void cuentas::imprimirAhorro()
{
	cout<<"\nSaldo actual de su cuenta de ahorro $"<<ahorro;
}
void cuentas::imprimirCredito()
{
	cout<<"\nSaldo actual de su cuenta de credito $"<<credito;
}
void retiro::retiroAhorro(cuentas *saldo)
{
	cout<<"\nIngrese la cantidad a retirar ";cin>>cantidadRetiro;
	NBalance=saldo->ahorro;
	if(cantidadRetiro>0)
	{
	    if(NBalance>=cantidadRetiro)	
		{
	        saldo->ahorro=NBalance-cantidadRetiro;
	        cout<<"nuevo balance "<<saldo->ahorro;
        }
        else
        {
            cout<<"no puede retirar esa cantidad\nsu saldo actual "<<saldo->ahorro;
	    }
    }
    else
    {
	    cout<<"ingrese una cantidad correcta";
    }
}
void retiro::retiroCredito(cuentas *saldo)
{
	cout<<"\nIngrese la cantidad a retirar ";cin>>cantidadRetiro;
	NBalance=saldo->credito;
	if(cantidadRetiro>0)
	{
	    if(NBalance>=cantidadRetiro)
	    {
		    saldo->credito=NBalance-cantidadRetiro;
	        cout<<"nuevo balance "<<saldo->credito;
        }
        else
        {
    	cout<<"no puede retirar esa cantidad\nsu saldo actual "<<saldo->credito;
	    }
    }
    else
    {
	    cout<<"ingrese una cantidad correcta";
    }
}
void pagos::pagosAhorro2(cuentas *saldo)
{
   cout<<"\nIngrese la cantidad a pagar: ";cin>>pagofinal;
   monto=saldo->ahorro;
 if(pagofinal>0)
 {
   if(monto>=pagofinal)
   {
   saldo->ahorro=monto-pagofinal;
   cout<<"Nuevo saldo: "<<saldo->ahorro;
   cout<<"\nRecibo pagado exitosamente";
   cout<<"\nOperacion finalizada";
}
else
{
    cout<<"\nSaldo insuficiente, cantidad disponible: "<<saldo->ahorro; 
	 cout<<"\nOperacion rechazada\n";           
    }
}
else
{
	cout<<"\nCantidad ingresada erronea ";
	cout<<"\nOperacion rechazada\n";
}
}
void pagos::pagosCredito2(cuentas *saldo)
{
   cout<<"\nIngrese la cantidad a pagar ";cin>>pagofinal;
   monto=saldo->credito;
 if(pagofinal>0)
 {
   if(monto>=pagofinal)
   {
   saldo->credito=monto-pagofinal;
   cout<<"Nuevo saldo: "<<saldo->credito;
   cout<<"\nRecibo pagado exitosamente";
   cout<<"\nOperacion Finalizada";
}
else
{
    cout<<"\nSaldo insuficiente, cantidad disponible: "<<saldo->credito; 
	cout<<"\nOperación rechazada";             
}
}
else
{
    cout<<"\nCantidad ingresada erronea ";
	cout<<"\nOperacion rechazada\n";
}
}
void transferir::transferirAhorro3(cuentas *saldo)
{
	cout<<"\nIngrese la cantidad a transferir: ";cin>>dinero;
	dinerotran1=saldo->ahorro;
	dinerotran2=saldo->credito;
 if(dinero>0)
 {
    if(dinerotran1>=dinero)
    {
    	saldo->credito=dinerotran2+dinero;
    	saldo->ahorro=dinerotran1-dinero;
    	cout<<"\nOperacion Exitosa";	
    }
else
{
    cout<<"\nSaldo insuficiente, cantidad disponible: "<<saldo->ahorro; 
    cout<<"\nOperacion rechazada";
	             }
}
else
{       
        cout<<"\nCantidad ingresada errónea";
		cout<<"\nOperacion rechazada";
}
}
void transferir::transferirCredito3(cuentas *saldo)
{
	cout<<"\nIngrese la cantidad a transferir: ";cin>>dinero;
	dinerotran1=saldo->credito;
	dinerotran2=saldo->ahorro;
 if(dinero>0)
 {
   if(dinerotran1>=dinero)
   {
   saldo->ahorro=dinerotran2+dinero;
   saldo->credito=dinerotran1-dinero;
   cout<<"\nOperacion exitosa";
}
else
{
    cout<<"\nSaldo insuficiente, cantidad disponible: "<<saldo->credito; 
    cout<<"\nOperacion rechazada";
}
}
else
{       
    cout<<"\nCantidad ingresada errónea"<<"\nOperacion rechazada";
}
}
