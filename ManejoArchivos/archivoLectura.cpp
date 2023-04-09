#include<iostream>
#include<fstream>
using namespace std;

int main(void){
	ifstream archivo("nuevo.txt");
	string linea;
	
	if(archivo.fail()){
		cout<<"\nerror  al abrir el archivo\n";
    }
	else{
		cout<<"\n1";
		while(archivo.eof()){
			cout<<"\n2";
			getline(archivo,linea);
			cout<<"que pedo, que pedo";
		}
	}
	cout<<"\n3";
	archivo.close();
	
	
	system("pause");
	return 0;
}
