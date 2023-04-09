//Simulador de cajero automático
//Este programa requiere la librería "Final.h"

//Autor: Luis Pedroza
//Fecha: 2020

#include"Final.h"
int main()
{
	persona datospersona;
	cliente datoscliente;
	cuentas saldocuentas;
	retiro saldoretiro;
	pagos pagosCredito2;
	pagos pagosAhorro2;
    transferir tCredito3;
    transferir tAhorro3;

	int opcion,opcion2,opcion3;
	int i,clave,seleccionCuenta;
	unsigned char tecla;
	datospersona.inicializarPersona("John Connor","Masculino",24);
	datoscliente.inicializarCliente(123423,192837,1294);
	saldocuentas.inicializarAhorro(5000);
	saldocuentas.inicializarCredito(10000);
	
	    system("cls");
        cout<<"\t\t\t\tBIENVENIDO A DOGGE FINANCE"<<endl<<endl;
        cout<<"Cuenta con solo 3 intentos disponibles\n\n";
        for (i=1;i<4;i++)
		{
			cout<<"Escriba su clave de acceso (4 digitos): ";cin>>clave;
			if (clave == 1294)
			{
				i = i + 4;
			}
			else{
				cout<<"Clave incorrecta intentelo nuevamente\n\n";
			}
			if (i==3)
			{
				if (clave!=1294)
				{
					system("cls");
					cout << "\tUsuario incorrecto para mayores informes comunicarse a su Sucursal mas cercana\n";
					cout << "\t\tHorarios de atencion de lunes a viernes de 8:00 am a 4:00 pm\n";
					system("pause");
					exit(0);
				}
			}
		}
		do{
		system("cls");
		cout << "Bienvenido Jonhn Connor\n"
        <<"\nDatos del cliente ------------------- 1"
        <<"\nMis Cuentas ------------------------- 2"
        <<"\nTransferencia ----------------------- 3"
        <<"\nRetiro ------------------------------ 4"
        <<"\nPagos ------------------------------- 5"
        <<"\nSalir ------------------------------- 6"
		<<"\nSu opcion --------------------------- ";cin>>opcion;
		switch(opcion)
		{
			case 1:
				system("cls");
				cout<<"Datos del cliente\n";
				datospersona.imprimirPersona();
				datoscliente.imprimirCliente();
			    cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			    tecla=getch();
	      	break;
	      	case 2:
	      		do
			    {
	      	        system("cls");
	      	        cout<<"Mis Cuentas\n"
	      	        <<"\nSeleccione la cuenta"
	      	        <<"\nCuenta de Ahorro ----------------- 1"
	      	        <<"\nCuenta de Credito ---------------- 2"
	      	        <<"\nRegresar al menu principal ------- 3"
	      	        <<"\nSu opcion ------------------------ ";
	      	        cin>>opcion2;	      	        
	      		switch(opcion2)
	      		{
	      		case 1:
	      			system("cls");
	      		    saldocuentas.imprimirAhorro();
             	    cout<<"\n\nPresione cualquier tecla para regresar al menu.";
			        tecla=getch();
			    break;
			    case 2:
			    	system("cls");
	      		    saldocuentas.imprimirCredito();
	      	        cout<<"\n\nPresione cualquier tecla para regresar al menu.";
			        tecla=getch();
			    break;
			    case 3:
			        cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();
			    break;
			    default:
			    	cout<<"\n\nLa opcion no existe.\nPresione cualquier tecla para regresar al menu.";
				    tecla=getch();
		    	break; 	
		    	}
		        }
		        while(opcion2!=3);
			break;
			case 3:
	      		system("cls");
	      		cout<<"\t\t\t\tBienvenido al servicio de transferencia\n";
	      		cout<<"\nMis cuentas";
	      		saldocuentas.imprimirAhorro();
	      	    saldocuentas.imprimirCredito();
	      		cout<<"\n\nIngrese los ultimos cuatro digitos de la cuenta que desea utilizar - ";
	      	    cin>>seleccionCuenta;
	      	    	if(seleccionCuenta==3423)
	      		{
	      	       	tAhorro3.transferirAhorro3(&saldocuentas);
	      	       	saldocuentas.imprimirCredito();
	      	       	saldocuentas.imprimirAhorro();
	      	        cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			      else if(seleccionCuenta==2837)
			    {
	      			tCredito3.transferirCredito3(&saldocuentas);
	      			saldocuentas.imprimirAhorro();
	      			saldocuentas.imprimirCredito();
	      	        cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else
			    {
			    	cout<<"\nEl numero ingresado no coincide con ninguna de las cuentas";
			    	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
				}
				break;
			break;
			case 4:
	      		system("cls");
	      		cout<<"Retiro\n";
	      		cout<<"\nIngrese los ultimos cuatro digitos de la cuenta que desea utilizar - ";
	      		cin>>seleccionCuenta;
	      		if(seleccionCuenta==3423)
	      		{
	      	       	saldocuentas.imprimirAhorro();
	      	        saldoretiro.retiroAhorro(&saldocuentas);
	      		    cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else if(seleccionCuenta==2837)
			    {
			        saldocuentas.imprimirCredito();
	      	        saldoretiro.retiroCredito(&saldocuentas);
	      		    cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else
			    {
			    	cout<<"El numero ingresado no coincide con ninguna de las cuentas";
			    	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
				}
			break;
			case 5:
	      		    system("cls");
	      		    cout<<"\t\t\t\t\tPago de servicios\n";
	      		do{
	      			system("cls");
	      			cout<<"\t\t\tPaga tus servicios de manera rapida y sencilla\n"
	      			<<"Servicio que desea pagar\n"
					<<"\nTelefono------------------------ 1-"
	      	        <<"\nLuz----------------------------- 2-"
	      	        <<"\nAgua---------------------------- 3-"
	      	        <<"\nPredial--------------------------4-"
	      	        <<"\nSalir al menu principal ---------5-"
	      	        <<"\n\nSu opcion   ------------------";cin>>opcion3;
	      	        switch(opcion3)
	      	        {
	      	    case 1:
	      	        system("cls");
	      	        cout<<"\t\tServicio a pagar :  Telmex\n";
	      	        cout<<"\nCargo total del mes a pagar (IVA incluido) ";
	      	        cout<<"\nIngrese los ultimos cuatro digitos de la cuenta que desea utilizar - ";
	      		    cin>>seleccionCuenta;
	      		if(seleccionCuenta==3423)
	      		{   
	      			datospersona.imprimirPersona();
	      			cout<<"\n";
	      	       	saldocuentas.imprimirAhorro();
	      	       	pagosAhorro2.pagosAhorro2(&saldocuentas);
	      	       	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else if(seleccionCuenta==2837)
			    {
	      			datospersona.imprimirPersona();
			        saldocuentas.imprimirCredito();
			        pagosCredito2.pagosCredito2(&saldocuentas);
	      	        cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else
			    {
			    	cout<<"\nEl numero ingresado no coincide con ninguna de las cuentas";
			    	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
				}
				break;
		        case 2:
					system("cls");
				    cout<<"\t\tServicio a pagar : CFE \n";
				    cout<<"\nIngrese los ultimos cuatro digitos de la cuenta que desea utilizar - ";
	      		    cin>>seleccionCuenta;
	      		if(seleccionCuenta==3423)
	      		{   
	      			datospersona.imprimirPersona();
	      	       	saldocuentas.imprimirAhorro();
	      	       	pagosAhorro2.pagosAhorro2(&saldocuentas);
	      	       	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else if(seleccionCuenta==2837)
			    {
	      			datospersona.imprimirPersona();
			        saldocuentas.imprimirCredito();
			        pagosCredito2.pagosCredito2(&saldocuentas);
	      	        cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else
			    {
			    	cout<<"\nEl numero ingresado no coincide con ninguna de las cuentas";
			    	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
				}
				break;	    
				case 3:
					system("cls");
					cout<<"\t\tservicio a pagar : AGUA \n";
				    cout<<"\nIngrese los ultimos cuatro digitos de la cuenta que desea utilizar - ";
	      		    cin>>seleccionCuenta;
	      		if(seleccionCuenta==3423)
	      		{   
	      			datospersona.imprimirPersona();
	      	       	saldocuentas.imprimirAhorro();
	      	       	pagosAhorro2.pagosAhorro2(&saldocuentas);
	      	       	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else if(seleccionCuenta==2837)
			    {
	      			datospersona.imprimirPersona();
			        saldocuentas.imprimirCredito();
			        pagosCredito2.pagosCredito2(&saldocuentas);
	      	        cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else
			    {
			    	cout<<"\nEl numero ingresado no coincide con ninguna de las cuentas";
			    	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
				}
				break;     
				case 4:
					system("cls");
					cout<<"\t\tservicio a pagar : PREDIAL \n";
				    cout<<"\nIngrese los ultimos cuatro digitos de la cuenta que desea utilizar - ";
	      		    cin>>seleccionCuenta;
	      		if(seleccionCuenta==3423)
	      	    	{   
	      			datospersona.imprimirPersona();
	      	       	saldocuentas.imprimirAhorro();
	      	       	pagosAhorro2.pagosAhorro2(&saldocuentas);
	      	       	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else if(seleccionCuenta==2837)
			    {
	      			datospersona.imprimirPersona();
			        saldocuentas.imprimirCredito();
			        pagosCredito2.pagosCredito2(&saldocuentas);
	      	        cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
			    }
			    else
			    {
			    	cout<<"\nEl numero ingresado no coincide con ninguna de las cuentas";
			    	cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();	
				}
				break;
                case 5:
	      	        cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();
			    break;
				default:
				    cout<<"\nLa opcion no existe.\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			        tecla=getch();
		        break;
		            }
			        }
			        while(opcion3!=5);
			    break;
			case 6:
			    cout<<"\n\nPresione cualquier tecla para regresar al menu o Esc para salir.";
			    tecla=getch();
			    break;
			default:
				cout<<"\n\nLa opcion no existe.\nPresione cualquier tecla para regresar al menu o Esc para salir.";
				tecla=getch();
			break;				
	    }
    }
    while(tecla!=27);
}
