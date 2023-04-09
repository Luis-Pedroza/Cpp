#include<iostream>
using namespace std;
template<class T1,class T2>
class ejemplo
{
	T1 variante1;
	T2 variante2;
	public:
		ejemplo(T1 v1,T2 v2){variante1=v1;variante2=v2;}
		void imp(){cout<<"\nLa variante 1 es "<<variante1<<"\nLa variante 2 es "<<variante2;}
};
void usaplantilla()
{
	ejemplo<int,int>objeto(6,14);
	ejemplo<char,float>objeto2('z',16.8);
	objeto.imp();
	objeto2.imp();
}
int main()
{
	usaplantilla();
}


