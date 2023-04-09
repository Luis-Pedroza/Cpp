#include<iostream>
#include<fstream>
//librería para acentos y ene
using namespace std;

int main(void){
	//generary abrir un archivo de texto ***pruebaArchivo.txt***
	//se crea un objeto de tipo ofstream(salida)
	ofstream archivo;
	//se crea el archivo pruebaArchivo.txt 
	archivo.open("pruebaArchivo.txt");

	//modifica el archivo especificado
	archivo<<"Hola mundo en texto, a perro";

	//creación de archivo2 con constructor por parámetros extension .doc
	ofstream archivo2("pruebaArchivo2.doc");

	//edita el archivo 2
	archivo2<<"IPN\nESIME\nBASE DE DATOS\nPRUEBA DE LA ENE Y ACENTO";

	//creación de archivo3 extension .xls;
	ofstream archivo3("pruebaArchivo3.xls");

	//edita el archivo 3
	archivo3<<"1\t2\t3\t4\t5\t=SUMA(A1:E1)\n2\n3\n4\n5\n=SUMA(A1:A5)";

	//creación de archivo 4 extension pdf
	ofstream archivo4("pruebaArchivo4.pdf");

	//edita el archivo 4
	archivo4<<"prueba del archivo pdf";
	
	//cierra el archivo abierto
	archivo.close();
	archivo2.close();
	archivo3.close();
	archivo4.close();
	
	cout<<"\n\n";
	cout<<"Termino el programa\n\n";
	return 0;
}
