#include<iostream>
using namespace std;
template<class T>
T llenar(T x[4][4],int f, int c)
{
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Dato ["<<i<<"]"<<"["<<j<<"]";
			cin>>x[i][j];
		}
	}
}
template<class T>
T imprimir(T x[4][4],int f, int c)
{
	cout<<"Matriz capturada\n\n";
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"|"<<x[i][j];
		}
		cout<<"|\n";
	}
}
int main()
{
	int matriz[4][4],filas,columnas;
	int matriz1[4][4],fil,col;
	cout<<"Matriz int\n";
	cout<<"Da el numero de filas ";cin>>filas;
	cout<<"Da el numero de columnas ";cin>>columnas;
	if(filas<5&&columnas<5)
	{
	llenar(matriz,filas,columnas);
	imprimir(matriz,filas,columnas);
    }
    else
    {
    	cout<<"El numero de filas y columnas debe ser menor a 5";
	}
	cout<<"Matriz float\n";
	cout<<"Da el numero de filas ";cin>>fil;
	cout<<"Da el numero de columnas ";cin>>col;
	if(fil<5&&col<5)
	{
	llenar(matriz1,fil,col);
	imprimir(matriz1,filas,col);
    }
    else
    {
    	cout<<"El numero de filas y columnas debe ser menor a 5";
	}
}
