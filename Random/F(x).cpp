#include<iostream>
using namespace std;
class multi
{
	float x,f;
	public:
		void ini(float X);
		float fx();
};
void multi::ini(float X)
{
	x=X;
}
float multi::fx()
{
	if(x<0)
	{
		if(x==-2)
		{
			cout<<"Funcion discontinua";
		}
		else
		{
			f=1/(x+2); return(f);
		}
	}
	else if(x>=0&&x<4)
	{
		if(x==2)
		{
			cout<<"funcion discontinua";
		}
		else
		{
			f=1/(x-2);return(f);
		}
	}
	else if(x>=4)
	{
		if(x==10)
		{
			cout<<"Funcion discontinua";
		}
		else
		{
			f=1/(x-10);return(f);
		}
	}
}
int main()
{
	multi funcion;
	int y;
	cout<<"Da el valor de x --- ";
	cin>>y;
	funcion.ini(y);
	cout<<endl<<"El valor de f(x) es "<<funcion.fx();
}
