#include<iostream>
using namespace std;

template<class T>
class suma
{
	T a,b;
	public:
		suma(T A,T B){a=A;b=B;}
		void op();
		void imp(){cout<<"La suma es "<<a;}
};
template<class T>
void suma<T>::op()
{
	a+=b;
}
int main()
{
	suma<int>ob(7,23);
	ob.op();
	ob.imp();
}
