#include<iostream>
using namespace std;
class uno
{int x;
public:
	void iniuno(){x=2;}
	void impuno(){cout<<"x="<<x;}
	friend class dos;
};
class dos
{
	int nx;
	public:
	void pedir(){cout<<"\nDa  new x ";cin>>nx;}
	void cambio(uno *ob);
	friend class uno;
};
void dos::cambio(uno *ob)
{
	ob->x=nx;
}
int main()
{
	uno obuno;
	dos obdos;
	obuno.iniuno();
	obuno.impuno();
	obdos.pedir();
	obdos.cambio(&obuno);
	obuno.impuno();
}
