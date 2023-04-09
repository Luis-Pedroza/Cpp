#include<iostream>
#include<math.h>
#include<iomanip>
#include<time.h>
#include <vector>
using namespace std;
int n;
float matriz[10][10];
int cofactor(float matriz[][10], int orden, int fila, int columna);
void Fecha()
{	time_t now = time(0);
	tm * time = localtime(&now);
	vector<string> dia_semana;
	dia_semana.push_back("Domingo");
	dia_semana.push_back("Lunes");
	dia_semana.push_back("Martes");
	dia_semana.push_back("Miercoles");
	dia_semana.push_back("Jueves");
	dia_semana.push_back("Viernes");
	dia_semana.push_back("Sabado");
	vector<string> mes;
	mes.push_back("Enero");
	mes.push_back("Febrero");
	mes.push_back("Marzo");
	mes.push_back("Abril");
	mes.push_back("Mayo");
	mes.push_back("Junio");
	mes.push_back("Julio");
	mes.push_back("Agosto");
	mes.push_back("Septiembre");
	mes.push_back("Octubre");
	mes.push_back("Noviembre");
	mes.push_back("Diciembre");
	int year = 1900 + time->tm_year;
	cout<< "               Hoy " << dia_semana[time->tm_wday] << ", ";
	cout<< time->tm_mday << " de " << mes[time->tm_mon] << " del "<< year;
	cout<<" Hora: "<< time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec<<"             |";
}
void Portada()
{	cout<<"|------------------------------------------------------------------------------|"
	    "\n|                       Instituto Politecnico Nacional                         |"
	    "\n|                                                                              |"
		"\n|                         Materia: Analisis numerico                           |" 
		"\n|                                                                              |"
		"\n|                                                                              |"
		"\n|                               Unidad III y IV                                |"
		"\n|";Fecha();
  cout<<"\n|                            Alumno: Luis Pedroza                              |"
		"\n|------------------------------------------------------------------------------|\n";
	system("pause"); system("cls");
}
void LeerG(float Mat[][10])
{	cout<<"Ingrese el Orden M*M de la matriz: "; cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
		{	if(j==n)	cout<<"Ingrese Resultado De renglon "<<i+1<<": ";
			else		cout<<"Ingrese ["<<i<<"]["<<j<<"]: "; 
			cin>>Mat[i][j];
		}
}
void LeerI(float Mat[][10])
{	cout<<"Ingrese el Orden M*M de la matriz: "; cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{	cout<<"Ingrese ["<<i<<"]["<<j<<"]: "; cin>>Mat[i][j];
			
		}
}
int determinante(float matriz[10][10], int orden)
{  int det=0;
   if (orden == 1)      det = matriz[0][0];
   else    for(int j = 0; j < orden; j++)	det=det+matriz[0][j]*cofactor(matriz,orden,0,j);
   return det;
}
int cofactor(float matriz[][10], int orden, int fila, int columna)
{  float submatriz[10][10];
   int c=orden-1;
   int x=0;
   int y=0;
   for (int i=0;i<orden;i++)
      for (int j=0; j < orden; j++) 
         if (i!=fila && j!=columna) 
		 {  submatriz[x][y]=matriz[i][j];
            y++;
            if (y>=c) 
			{  x++;
               y=0;
            }
         }
   return pow(-1.0,fila+columna)*determinante(submatriz,c);
}
void ImprimirG(float Mat[][10])
{	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
		{	cout<<"|  "<<Mat[i][j]<<"  |";
		}
		cout<<" = "<<Mat[i][n]<<endl;
	} cout<<endl;
}
void GaussJordan(float Mat[][10])
{	float Sol[10][10],Piv,C;
	int r=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)	Sol[i][j]=Mat[i][j];
	do
	{	
		Piv=Sol[r][r];
		cout<<endl<<"Division del renglon "<<r+1<<" entre "<<Piv<<endl;
		for(int i=0;i<=n;i++)	Sol[r][i]=Sol[r][i]/Piv;
		ImprimirG(Sol);
		for(int i=0;i<n;i++)
		{	if(r!=i)
			{	C=Sol[i][r];
				cout<<endl<<"Renglon "<<i+1<<" -"<<C<<"* Renglon "<<r+1<<endl;
				for(int j=0;j<=n;j++)	Sol[i][j]-=C*Sol[r][j];
				cout<<endl;
				ImprimirG(Sol);
			}
		}
		r++;	
	}while(r!=n);
	for(int i=0;i<n;i++)		cout<<"La Solucion es x"<<i+1<<" = "<<Sol[i][n]<<endl<<endl;
}
void ImprimirI(float Mat[][10])
{	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
		{	cout<<setprecision(4)<<"|"<<Mat[i][j]<<"";
		}
		cout<<endl;
	}
}
void InversaGJ(float Mat[][10])
{	float Sol[10][10],Piv,C;
	int r=0;
	for(int i=0;i<n;i++)	for(int j=0;j<=n;j++)	Sol[i][j]=Mat[i][j];
	for(int i=0;i<n;i++)
		for(int j=n;j<n+3;j++)
		{	if((i+n)==j)			Sol[i][j]=1;
			else		Sol[i][j]=0;
		}
	do
	{	
		Piv=Sol[r][r];
		for(int i=0;i<n+3;i++)	Sol[r][i]=Sol[r][i]/Piv;
		for(int i=0;i<n;i++)
		{	if(r!=i)
			{	C=Sol[i][r];
				for(int j=0;j<n+3;j++)	Sol[i][j]-=C*Sol[r][j];
			}
		}		
		r++;	
	}while(r!=n);
	cout<<"La matriz inversa es: "<<endl;
	for(int i=0;i<n;i++)	
 	{	for(int j=n;j<n+n;j++)	cout<<setprecision(4)<<"|"<<Sol[i][j]<<"|";
		cout<<endl;
	}
}
void Jacobi(float Mat[][10])
{	float t[10],x[10],s=0;
	for(int i=0;i<9;i++) 
	{	x[i]=0;
		t[i]=0;
	}
	int iter,con=0,d;
	cout<<"Ingrese numero de iteraciones: "; cin>>iter;	
	cout<<"Ingrese numero de decimales deseados: "; cin>>d;
	cout<<"Iter\t";
	for(int i=0;i<n;i++) cout<<"X"<<i+1<<"\t";
	cout<<"\t\t\tEra"<<endl;
	do
	{	cout<<con+1;
		for(int i=0;i<n;i++)
		{	for(int j=0;j<n;j++)
			{	if(i!=j)	s+=(t[j]*Mat[i][j]);
			}
			x[i]=(Mat[i][n]-s)/Mat[i][i];
			cout<<fixed<<setprecision(d)<<"   "<<x[i];
			s=0;
		}
		if(con>=1)
		{	for(int i=0;i<n;i++)
			{	if(((x[i]-t[i])/x[i]*100)<0) cout<<fixed<<setprecision(d)<<"\t\t"<<-1*(x[i]-t[i])/x[i]*100;
				else cout<<fixed<<setprecision(d)<<"\t\t"<<(x[i]-t[i])/x[i]*100;
			}
		}
		else for(int i=0;i<n;i++) cout<<"\t\t-";
		cout<<endl;
		for(int i=0;i<n;i++) t[i]=x[i];
		con++;
	}while(con!=iter);
}
void GausSeidel(float Mat[][10])
{	float t[10],x=0,Era[n];
	for(int i=0;i<9;i++) t[i]=0;
	int iter,con=0,d;
	cout<<"Ingrese numero de iteraciones: "; cin>>iter;
	cout<<"Ingrese numero de decimales deseados: "; cin>>d;
	cout<<"Iter\t";
	for(int i=0;i<n;i++) cout<<"X"<<i+1<<"\t";
	cout<<"\t\t\t\tEra"<<endl;
	do
	{	cout<<con+1;
		for(int i=0;i<n;i++)
		{	for(int j=0;j<n;j++)
				if(i!=j)	x+=(t[j]*Mat[i][j]);	
			Era[i]=t[i];
			t[i]=(Mat[i][n]-x)/Mat[i][i];
			cout<<fixed<<setprecision(d)<<"    "<<t[i];
			x=0;
		}
		if(con>=1)
		{	for(int i=0;i<n;i++)
			{	if(((t[i]-Era[i])/t[i]*100)<0) cout<<fixed<<setprecision(d)<<"\t\t"<<-1*(t[i]-Era[i])/t[i]*100;
				else cout<<fixed<<setprecision(d)<<"\t\t"<<(t[i]-Era[i])/t[i]*100;
			}
		}
		else for(int i=0;i<n;i++) cout<<"\t\t\t-";
		cout<<endl;
		con++;
	}while(con!=iter);
}
void MinimosCuadrados()
{	float mat[n][2],xx,xy,Sx=0,Sy=0,Sxy=0,Sx2=0,m,b;
	int d,op,v;
	for(int i=0,j=0;i<n;i++)
	{	cout<<i+1<<" Ingrese x: "; cin>>mat[i][j];
		cout<<i+1<<" Ingrese y: "; cin>>mat[i][j+1];
	}
	system("cls");
	cout<<"\tx\ty\t\txy\t\tx^2"<<endl;
	for(int i=0,j=0;i<n;i++)
	{	xy=mat[i][j]*mat[i][j+1];
		xx=mat[i][j]*mat[i][j];
		cout<<i+1<<"\t"<<mat[i][j]<<"\t"<<mat[i][j+1]<<"\t\t"<<xy<<"\t\t"<<xx<<endl;
		Sxy+=xy;
		Sx+=mat[i][j];
		Sy+=mat[i][j+1];
		Sx2+=xx;
	}
	m=(Sxy-(Sx*Sy)/n)/(Sx2-(Sx*Sx)/n);
	b=(Sy/n)-m*(Sx/n);
	cout<<"Ajuste de Curva"<<endl;
	cout<<"\t\tx\t\ty"<<endl;
	for(int i=0,j=0;i<n;i++)
	{	cout<<i+1<<"\t\t"<<mat[i][j]<<"\t\t"<<m*mat[i][j]+b<<endl;
	}
	system("pause"); system("cls");
	do
	{	cout<<"Desea calcular un nuevo valor de Y"<<endl;
		cout<<"1=Si\n2=No\nSeleccionaste: "; cin>>op;
		switch(op)
		{	case 1:	cout<<"\ny="<<m<<"x+("<<b<<")"<<endl;
					cout<<"Ingrese valor a calcular: "; cin>>v;
					cout<<"Y="<<m*v+b<<endl;
					break;
			case 2: cout<<"Adios"<<endl; break;
			default: cout<<"Opcion Invalida"<<endl; break;
		}
		system("pause");		system("cls");
	}while(op!=2);	
}
void InterpolacionLagrange(float x[],float y[],int v)
{	float l=0,t=0;
	for(int i=0;i<n;i++)
	{  	l=y[i];
   		for(int j=0;j<n;j++)
   			if(i!=j)    l=(l*(v-x[j]))/(x[i]-x[j]);
    	t+=l;
	}
	cout<<"Y="<<t<<endl;
}
void InicioGJ()
{	float matriz[10][10];
	LeerG(matriz);
	if(n>1)
	{	ImprimirG(matriz);
		int  d=determinante(matriz,n);
		if(d!=0)	GaussJordan(matriz);
		else	cout << "\nComo el determinante es: "<<d<<" No tiene solucion"<<endl;
		system("pause");
	}
	else
	{	ImprimirG(matriz);
		cout<<"\nNo es una matriz, es una igualdad cuyo valor de ";
		cout<<"x="<<matriz[0][1]/matriz[0][0]<<endl;
		system("pause");
	}
}
void InicioMI()
{	LeerI(matriz);	
	ImprimirI(matriz);
	int  d=determinante(matriz,n);
	if(d!=0)	InversaGJ(matriz);
	else	cout << "\nComo el determinante es: "<<d<<"No tiene solucion"<<endl;
}
void InicioJac()
{	LeerG(matriz);
	Jacobi(matriz);
}
void InicioGS()
{	LeerG(matriz);
	GausSeidel(matriz);
}
void InicioIL()
{	cout<<"Ingrese Numero de datos a ingresar: "; cin>>n;
	float x[n],y[n];
	int op,v,g;
	for(int i=0;i<n;i++)
	{	cout<<i+1<<" Ingrese x: "; cin>>x[i];
		cout<<i+1<<" Ingrese y: "; cin>>y[i];
	}
	system("pause"); system("cls");
	do
	{	cout<<"Desea calcular un nuevo valor de Y"<<endl;
		cout<<"1=Si\n2=No\nSeleccionaste: "; cin>>op;
		switch(op)
		{	case 1:	cout<<"Ingrese valor a calcular: "; cin>>v;
					InterpolacionLagrange(x,y,v);
					break;
			case 2: cout<<"Adios"<<endl; break;
			default: cout<<"Opcion Invalida"<<endl; break;
		}
		system("pause");		system("cls");
	}while(op!=2);	
}
void InicioMC()
{	cout<<"Ingrese Numero de datos a ingresar: "; cin>>n;
	MinimosCuadrados();
}
