#include<iostream>
#include<windows.h>
using namespace std;
template<class T>
T imprimir(T x[4][4],T a)
{
	int giro=1;
for(int i=0;i<4;i++)
{
	for(int j=0;j<4;j++)
	{
	x[i][j]=0;
	}
}
	for(int k=0;k<4;k++)
	{
		if(giro==1)
		{
			for(int j=0;j<4;j++)
			{
			if(x[k][j]==0)
			{
				x[k][j]=a++;
			}
		    }
		}
		giro++;
		if(giro==2)
		{
			for(int j=0;j<4;j++)
			{
			if(x[j][4-(k+1)]==0)
			{
				x[j][4-(k+1)]=a++;
			}
		    }
			
		}
		giro++;
		if(giro==3)
		{
			for(int j=3;j>=0;j--)
			{
			if(x[4-(k+1)][j]==0)
			{
				x[4-(k+1)][j]=a++;
			}
			}
		}
		giro++;
		if(giro==4)
		{
			for(int j=3;j>=0;j--)
			{
			if(x[j][k]==0)
			{
				x[j][k]=a++;
			}	
			}
			
		}
		giro=1;
	}
for(int l=0;l<4;l++)
{
for(int j=0;j<4;j++)
{
	cout<<"|";
	cout.width(5);
	cout<<x[l][j];
}
cout<<"|\n-------------------------\n";
}
}
int main()
{
	int matriz[4][4],a=1;
	float matriz1[4][4],b=1.1;
	imprimir(matriz,a);
	cout<<endl;
	imprimir(matriz1,b);
}
