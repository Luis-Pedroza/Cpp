#include<iostream>
using namespace std;
class dos
{
	int m,n,r;
	public:
		void iniP(){m=2;n=6;}
		//void op(uno obu){r=m+n+obu.x+obu.y;}
		void imp(){cout<<" m="<<m<<" n="<<n;cout<<"\nla suma es "<<r;}
		friend class uno;
};
class uno
{
	int x,y,R;
	public:
		void ini(){x=2;y=7;}
		void op(dos obd){R=obd.m+obd.n+x+y;}
		void impU(){cout<<"X="<<x<<" Y="<<y;cout<<"\nla suma es "<<R;}
		friend class dos;	
};

int main()
{
	uno obuno;
	dos obdos;
	obuno.ini();
	obdos.iniP();
	//obdos.op(obuno);
	obuno.op(obdos);
	obuno.impU();
	obdos.imp();
}
