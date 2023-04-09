#include"funciones.h"
using namespace std;
int P[5],n;
int PA[5],nA;
float Evaluar(float v)
{	float vf=0;
	int f=0;
	do
	{	vf+=P[f]*pow(v,n-f);
		f++;
	}while(f!=n+1);
	return vf;
}
float EvaluarA(float vA)
{	float vfA=0;
	int fA=0;
	do
	{	vfA+=PA[fA]*pow(vA,nA-fA);
		fA++;
	}while(fA!=nA+1);
	return vfA;
}
float EvaluarFA(float vA)
{	float	vfA=0;
	int fA=nA,conA=0;
	do
	{	vfA+=fA*PA[conA]*pow(vA,fA-1);
		conA++;
		fA--;
	}while(conA!=nA);
	return vfA;
}
int main(){
	initwindow(800,600);
	float xi1,xi,xu,xr,fxi,fxu,fxr;
	int cA=0,fA,vfA;
	float xi1A,xiA,fxiA,fdxiA;
	int c=0,f,vf;
	int OPmenu;
	int OPsubmenu;
	marco();
	eje();
	portada();
	cout<<"\n\n";
	system("pause");
	do{
		system("cls");
		menu();
		cin>>OPmenu;
		switch(OPmenu){
			case 1:
				do{
				    system("cls");
	                cout<<"BISECCION";
			        submenu();
				    cin>>OPsubmenu;
				    switch(OPsubmenu){
				    	case 1:
				    		system("cls");
						    cout<<"EXPONENCIAL";
						    cout<<"\n\nCONSTRUCCION";
						    cout<<"\n\n";
				    		system("pause");
					    break;
					    case 2:
						    system("cls");
						    cout<<"POLINOMIAL";
						    cout<<"\nIngrese el grado del polinomio: "; cin>>n;
	                        for(int i=0;i<=n;i++)
                            {	cout<<"Ingresa el coeficiente de x^"<<n-i<<": "; cin>>P[i];
	                        }
 	                        cout<<"Cuantas iteraciones desea: "; cin>>c;
	                        cout<<"Ingrese el valor de xi: "; cin>>xi;
	                        cout<<"Ingrese el valor de xu: "; cin>>xu;
               	            do
	                        {	fxi=Evaluar(xi);
		                        fxu=Evaluar(xu);
		                        xr=(xi+xu)/2;
		                        fxr=Evaluar(xr);
		                        cout<<fixed<<setprecision(6)<<xi<<"   "<<xu<<"   "<<xr<<
		                        "   "<<fxi<<"   "<<fxu<<"   "<<fxr<<endl;
		                        if((fxr*fxi)<0)	xu=xr;
		                        else if((fxr*fxi)>0)	xi=xr;	
		                        c--;
	                            }while(c!=0);
						    cout<<"\n\n";
				    		system("pause");
					    break;
					    case 3:
					    	cout<<"\nSaliendo\n";
				            system("pause");
					    break;
					    default:
						    cout<<"\n\nOpcion no valida";
				            cout<<"\n\n";
				    		system("pause");
					    break;
				    }
			    }while(OPsubmenu!=3);
			break;
			case 2:
				do{
					system("cls");
				    cout<<"NEWTON RAPHSON";
				    submenu();
				    cin>>OPsubmenu;
				    switch(OPsubmenu){
				    	case 1:
				    		system("cls");
						    cout<<"EXPOENCIAL";
						    cout<<"\n\nCONSTRUCCION";
						    cout<<"\n\n";
				    		system("pause");
				    	break;
				    	case 2:
				    		system("cls");
						    cout<<"POLINOMIAL";
						    cout<<"\nIngrese el grado del polinomio: "; cin>>nA;
	                        for(int i=0;i<=nA;i++)
	                        {	cout<<"Ingresa el coeficiente de x^"<<nA-i<<": "; cin>>PA[i];
	                        }
	                        cout<<"Cuantas iteraciones desea: "; cin>>cA;
	                        cout<<"Ingrese el valor de xi: "; cin>>xiA;
	                        do
	                        {	fxiA=EvaluarA(xiA);
		                    fdxiA=EvaluarFA(xiA);
		                    xi1A=xiA-fxiA/fdxiA;
	                        cout<<fixed<<setprecision(6)<<xiA<<"		"<<fxiA<<"	"<<fdxiA<<"	"<<xi1A<<endl;
		                    xiA=xi1A;
		                    cA--;
	                        }while(cA!=0);
						    cout<<"\n\n";
				    		system("pause");
				    	break;
				    	case 3:
				    		cout<<"\nSaliendo\n";
				            system("pause");
				    	break;
				    	default:
				    		cout<<"\n\nOpcion no valida";
				    		cout<<"\n\n";
				    		system("pause");
				    	break;
					}
				}while(OPsubmenu!=3);
			break;
			case 3:
				cout<<"\nSaliendo\n";
				system("pause");
			break;
			default:
				cout<<"\n\nOpcion no valida";
				cout<<"\n\n";
				system("pause");
			break;
		}
	}while(OPmenu!=3);
}
