#include<iostream>
using namespace std;
template <class T>
class vector
{
	T vec[20];
	int i,n;
	public:
		void llenar();
		void imp();
};
template <class T>
void vector<T>::llenar()
{
	cout<<"Da el limite del vector ";
	cin>>n;
	if(n<21)
	{
	for(i=0;i<n;i++)
	{
		cout<<"Da el valor ["<<(i+1)<<"] ";
	    cin>>vec[i];
	}
    }
    else
    {
    	cout<<"El vector debe ser menor a 21";
	}
}
template<class T>
void vector<T>::imp()
{
	if(n<21)
	{
	cout<<"Vector ";
	for(i=0;i<n;i++)
	{
		cout<<"["<<vec[i]<<"]";
	}
    }
}
int main()
{
	vector<float>ob;
	ob.llenar();
	ob.imp();
}
