//Pedroza Moranchel Luis Fernando 3CV8
#include<iostream>
using namespace std;
class videoteca{
	private:
		string titulo;
		string director;
		string genero;
		int anio;
		int isbn;
	public:
		videoteca(void);
		videoteca(const videoteca &);
		void leer(void);
		void imprimir(void);
		string obtenerTitulo(void);
		string obtenerDirector(void);
		string obtenerGenero(void);
		int obtenerAnio(void);
		int obtenerISBN(void);
		void editarTitulo(string);
		void editarDirector(string);
		void editarGenero(string);
		void editarAnio(int);
		void editarISBN(int);
		videoteca &operator=(const videoteca &);
		~videoteca(void);
};
//**********Fin de class videoteca**********
class nodoVideoteca{
	private:
		videoteca nodo;
		nodoVideoteca *aptSig;
		nodoVideoteca *aptAnt;
	public:
		nodoVideoteca(void);
		nodoVideoteca(const nodoVideoteca &);
		void leer(void);
		void imprimir(void);
		videoteca &obtenerNodo(void);
		nodoVideoteca *obtenerAptSig(void);
		nodoVideoteca *obtenerAptAnt(void);
		void editarNodo(videoteca &);
		void editarAptSig(nodoVideoteca *);
		void editarAptAnt(nodoVideoteca *);
		nodoVideoteca &operator=(const nodoVideoteca &);
		~nodoVideoteca(void);
};
//**********Fin de class nodoVideoteca**********
class lde_videoteca{
	private:
		nodoVideoteca *nuevoVideo;
		nodoVideoteca *inicio;
		nodoVideoteca *final;
		nodoVideoteca *apt;
	public:
		lde_videoteca(void);
		lde_videoteca(const lde_videoteca &);
		void insertarInicio(void);
		void insertarFinal(void);
		void insertarDespues(void);
		void eliminarInicio(void);
		void eliminarFinal(void);
		void eliminarVideo(void);
		nodoVideoteca *obtenerVideo(int);
		void imprimir(void);
		void editarVideo(void);
		lde_videoteca &operator=(const lde_videoteca &);
		~lde_videoteca(void);
};
//**********Fin de class lde_videoteca**********
videoteca::videoteca(void){
	titulo=" ";director=" ";genero=" ";anio=0;isbn=0;
}
videoteca::videoteca(const videoteca &video){
	titulo=video.titulo;director=video.director;genero=video.genero;anio=video.anio;isbn=video.isbn;
}
void videoteca::leer(void){
	cout<<"\n\nIngrese el titulo del video: ";
	fflush(stdin);
	getline(cin,titulo);
	cout<<"\nIngrese el nombre del director: ";
	fflush(stdin);
	getline(cin,director);
	cout<<"\nIngrese el genero del video: ";
	fflush(stdin);
	getline(cin,genero);
	cout<<"\nIngrese el anio: ";cin>>anio;
	cout<<"\nIngrese los ultimos 4 digitos del isbn: ";cin>>isbn;
}
void videoteca::imprimir(void){
	cout<<"\nTitulo: "<<titulo;
	cout<<"\nDirector: "<<director;
	cout<<"\nGenero: "<<genero;
	cout<<"\nAnio: "<<anio;
	cout<<"\nISBN: "<<isbn;
}
string videoteca::obtenerTitulo(void){
	return titulo;
}
string videoteca::obtenerDirector(void){
	return director;
}
string videoteca::obtenerGenero(void){
	return genero;
}
int videoteca::obtenerAnio(void){
	return anio;
}
int videoteca::obtenerISBN(void){
	return isbn;
}
void videoteca::editarTitulo(string TITULO){
	titulo=TITULO;
}
void videoteca::editarDirector(string DIRECTOR){
	director=DIRECTOR;
}
void videoteca::editarGenero(string GENERO){
	genero=GENERO;
}
void videoteca::editarAnio(int ANIO){
	anio=ANIO;
}
void videoteca::editarISBN(int ISBN){
	isbn=ISBN;
}
videoteca &videoteca::operator=(const videoteca &video){
	if(this!=&video){
		this->titulo=video.titulo;
		this->director=video.director;
		this->genero=video.genero;
		this->anio=video.anio;
		this->isbn=video.isbn;
	}
	return *this;
}
videoteca::~videoteca(void){
	cout<<"\n\n~DESTRUCTOR DE videoteca~";
}
//**********Fin de la imlementacion de los metodos de class videoteca**********
nodoVideoteca::nodoVideoteca(void){
	aptSig=NULL;aptAnt=NULL;
}
nodoVideoteca::nodoVideoteca(const nodoVideoteca &nodoVideo){
	nodo=nodoVideo.nodo;aptSig=nodoVideo.aptSig;aptAnt=nodoVideo.aptAnt;
}
void nodoVideoteca::leer(void){
	nodo.leer();
}
void nodoVideoteca::imprimir(void){
	nodo.imprimir();
	cout<<"\n";
}
videoteca &nodoVideoteca::obtenerNodo(void){
	return nodo;
}
nodoVideoteca *nodoVideoteca::obtenerAptSig(void){
	return aptSig;
}
nodoVideoteca *nodoVideoteca::obtenerAptAnt(void){
	return aptAnt;
}
void nodoVideoteca::editarNodo(videoteca &video){
	nodo=video;
}
void nodoVideoteca::editarAptSig(nodoVideoteca *sigApt){
	aptSig=sigApt;
}
void nodoVideoteca::editarAptAnt(nodoVideoteca *antApt){
	aptAnt=antApt;
}
nodoVideoteca &nodoVideoteca::operator=(const nodoVideoteca &nodoVideo){
	if(this!=&nodoVideo){
		this->nodo=nodoVideo.nodo;
		this->aptSig=nodoVideo.aptSig;
		this->aptAnt=nodoVideo.aptAnt;
	}
	return *this;
}
nodoVideoteca::~nodoVideoteca(void){
	cout<<"\n\n~DESTRUCTOR DE nodoVideoteca~";
}
//**********Fin de la implementacion de los metodos de class nodoVideoteca**********
lde_videoteca::lde_videoteca(void){
	nuevoVideo=NULL;inicio=NULL;final=NULL;apt=NULL;
}
lde_videoteca::lde_videoteca(const lde_videoteca &lista){
	nuevoVideo=lista.nuevoVideo;inicio=lista.inicio;final=lista.final;apt=lista.apt;
}
void lde_videoteca::insertarInicio(void){
	nuevoVideo=new nodoVideoteca;
	if(nuevoVideo!=NULL){
		nuevoVideo->leer();
		if(inicio==NULL&&final==NULL){
			final=nuevoVideo;
			inicio=final;
			cout<<"\n***Se inerto el video***";
		}
		else{
		    nuevoVideo->editarAptSig(inicio->obtenerAptSig());
		    inicio->editarAptSig(nuevoVideo);
		    nuevoVideo->editarAptAnt(inicio);
		    inicio=nuevoVideo;
            cout<<"\n***Se inerto el video***";
		}
		nuevoVideo=NULL;
	}
	else{
		cout<<"\n\n***La memoria esta llena***";
		delete nuevoVideo;
	}
}
void lde_videoteca::insertarFinal(void){
	if(inicio==NULL&&final==NULL){
		insertarInicio();
	}
	else{
		nuevoVideo=new nodoVideoteca;
		nuevoVideo->leer();
		if(nuevoVideo!=NULL){
		    nuevoVideo->editarAptAnt(final->obtenerAptAnt());
		    final->editarAptAnt(nuevoVideo);
		    nuevoVideo->editarAptSig(final);
		    final=nuevoVideo;
		    cout<<"\n***Se inerto el video***";
		}
		else{
			cout<<"\n\n***La memoria esta llena***";
			delete nuevoVideo;
		}
		nuevoVideo=NULL;
	}
}
void lde_videoteca::insertarDespues(void){
	//revisar
	int opcion;
	int isbn;
	if(inicio==NULL&&final==NULL){
		cout<<"\n***La lista esta vacia***";
		cout<<"\nPresione 1 para agregar al inicio o 2 para no agregar: ";cin>>opcion;
		if(opcion==1){
		    insertarInicio();	
		}
		else if(opcion==2){
			cout<<"\n***No se agrego ningun elemento***";
		}
		else{
			cout<<"\nNo existe la opcion";
		}
	}
	else{
		nuevoVideo=new nodoVideoteca;
		if(nuevoVideo!=NULL){
			cout<<"\nIngrese los ultimos 4 digitos del isbn de la pelicula para ingresar despues: ";cin>>isbn;
			for(apt=inicio;apt!=NULL;apt=apt->obtenerAptAnt()){
			    if(apt->obtenerNodo().obtenerISBN()==isbn){
				    apt->imprimir();
				    cout<<endl;
			    }
	        }
	        apt=inicio;
			while(apt!=NULL&&apt->obtenerNodo().obtenerISBN()!=isbn){
				apt=apt->obtenerAptAnt();
			}
			if(apt!=NULL){
				nuevoVideo->leer();
				nuevoVideo->editarAptAnt(apt->obtenerAptAnt());
				apt->editarAptAnt(nuevoVideo);
				nuevoVideo->editarAptSig(apt);
				apt=nuevoVideo;
				cout<<"\n***Se inerto el video***";
			}
			else{
				cout<<"\n***No se encontro el video indicado***";
				delete nuevoVideo;
			}
			nuevoVideo=NULL;
		}
		else{
			cout<<"\n\n***La memoria esta llena***";
			delete nuevoVideo;
		}
	}
}
void lde_videoteca::eliminarInicio(void){
	if(inicio==NULL&&final==NULL){
		cout<<"\n***La lista esta vacia***";
	}
	else{
		apt=inicio;
		inicio=apt->obtenerAptAnt();
		delete apt;
		apt=NULL;
		cout<<"\n\n***Se elimino el video***";
	}
}
void lde_videoteca::eliminarFinal(void){
	if(inicio==NULL&&final==NULL){
		cout<<"\n***La lista esta vacia***";
	}
	else{
		apt=final;
		final=apt->obtenerAptSig();
	    delete apt;
		apt=NULL;
		final->editarAptAnt(NULL);
		cout<<"\n\n***Se elimino el video***";
	}
}
void lde_videoteca::eliminarVideo(void){
	int isbn;
	if(inicio==NULL&&final==NULL){
		cout<<"\n***La lista esta vacia***";
	}
	else{
		apt=inicio;
		cout<<"\nIngrese los ultimos 4 digitos del isbn de la pelicula que quiere eliminar: ";cin>>isbn;
		while(apt!=NULL&&apt->obtenerNodo().obtenerISBN()!=isbn){
				apt=apt->obtenerAptAnt();
			}
			if(apt!=NULL){
				apt->obtenerAptSig()->editarAptAnt(apt->obtenerAptAnt());
				apt->obtenerAptAnt()->editarAptSig(apt->obtenerAptSig());
				delete apt;
				apt=NULL;
				cout<<"\n\n***Se elimino el video***";
			}
			else{
				cout<<"\n***No se encontro el video indicado***";
			}
	}
}
nodoVideoteca *lde_videoteca::obtenerVideo(int isbn){
	nodoVideoteca *nodoEncontrado;
	nodoEncontrado=NULL;
	for(apt=inicio;apt!=NULL;apt=apt->obtenerAptAnt()){
		if(apt->obtenerNodo().obtenerISBN()==isbn){
			nodoEncontrado=apt;
		}
	} 
	return nodoEncontrado;
}
void lde_videoteca::imprimir(void){
	if(inicio==NULL&&final==NULL){
		cout<<"\n***La lista esta vacia***";
	}
	else{
		cout<<"\n\n";
		for(apt=inicio;apt!=NULL;apt=apt->obtenerAptAnt()){
		    apt->imprimir();
	    }
	}
}
void lde_videoteca::editarVideo(void){
	if(inicio==NULL&&final==NULL){
		cout<<"\n***La lista esta vacia***";
	}
	else{
		string titulo;
		string director;
		string genero;
		int anio;
		int isbn;
		int nuevoIsbn;
		cout<<"\nIngrese el isbn de la pelicula que quiere editar: ",cin>>isbn;
		apt=inicio;
		while(apt!=NULL&&apt->obtenerNodo().obtenerISBN()!=isbn){
			apt=apt->obtenerAptSig();
		}
		if(apt!=NULL){
			cout<<"\nIngrese el nuevo titulo: ";
			fflush(stdin);
			getline(cin,titulo);
			apt->obtenerNodo().editarTitulo(titulo);
			cout<<"\nIngrese el nuevo director: ";
			fflush(stdin);
			getline(cin,director);
			apt->obtenerNodo().editarDirector(director);
			cout<<"\nIngrese el nuevo genero: ";
			fflush(stdin);
			getline(cin,genero);
			apt->obtenerNodo().editarGenero(genero);
			cout<<"\nIngrese el nuevo anio: ";cin>>anio;
			apt->obtenerNodo().editarAnio(anio);
			cout<<"\nIngrese el nuevo isbn: ";cin>>nuevoIsbn;
			apt->obtenerNodo().editarISBN(nuevoIsbn);
			cout<<"\n\n***Se edito la pelicula***";
		}
		else{
			cout<<"\n***No se encontro la pelicula***";
		}
	}
}
lde_videoteca &lde_videoteca::operator=(const lde_videoteca &lista){
	if(this!=&lista){
		this->nuevoVideo=lista.nuevoVideo;
		this->inicio=lista.inicio;
		this->final=lista.final;
		this->apt=lista.apt;
	}
	return *this;
}
lde_videoteca::~lde_videoteca(void){
	nodoVideoteca *aux;
	apt=inicio;
	while(apt!=NULL){
		aux=apt;
		apt=apt->obtenerAptAnt();
		delete aux;
	}
	cout<<"\n\n~DESTRUCTOR DE lse_videoteca~";
}
//**********Fin de la implementacion de los metodos class lde_videoteca**********
int main(void){
	lde_videoteca lista;
	nodoVideoteca *buscarVideo;
	int opcion;
	int variable;
	do{
		system("cls");
		cout<<"\n*****LISTA DOBLEMENTE ENLASADA*****";
		cout<<"\nMenu principal";
		cout<<"\nInsertar una pelicula ------- 1";
		cout<<"\nImprimir -------------------- 2";
		cout<<"\nEliminar una pelicula ------- 3";
		cout<<"\nBuscar una pelicula --------- 4";
		cout<<"\nEditar una pelicula --------- 5";
		cout<<"\nSalir del programa ---------- 6";
		cout<<"\nSu opcion ------------------- ";cin>>opcion;
		switch(opcion){
			case 1:
				do{
					int opcion1;
					system("cls");
					cout<<"Insertar una pelicula\n";
					cout<<"\nAl inicio ---------------------- 1";
					cout<<"\nAl final ----------------------- 2";
					cout<<"\nDespues de --------------------- 3";
					cout<<"\nRegresar al menu anterior ------ 4";
					cout<<"\nSu opcion ---------------------- ";cin>>opcion1;
					switch(opcion1){
						case 1:
							cout<<"\nINSERTAR AL INICIO\n\n";
							lista.insertarInicio();
							cout<<"\n\n";
							system("pause");
						break;
						case 2:
							cout<<"\nINSERTAR AL FINAL\n\n";
							lista.insertarFinal();
							cout<<"\n\n";
							system("pause");
						break;
						case 3:
							cout<<"\nINSERTAR DESPUES\n\n";
							lista.insertarDespues();
							cout<<"\n\n";
							system("pause");
						break;
						case 4:
							variable=1;
						break;
						default:
							cout<<"\n***No existe la opcion***";
							cout<<"\n\n";
				            system("pause");
						break;
					}	
					
				}while(variable!=1);
			break;
			case 2:
				system("cls");
				cout<<"\nLISTA DE PELICULAS\n";
				lista.imprimir();
				cout<<"\n\n";
				system("pause");
			break;
			case 3:
				do{
					int opcion2;
					system("cls");
					cout<<"Eliminar una pelicula\n";
					cout<<"\nAl inicio ---------------------- 1";
					cout<<"\nAl final ----------------------- 2";
					cout<<"\nUna pelicula especifica -------- 3";
					cout<<"\nRegresar al menu anterior ------ 4";
					cout<<"\nSu opcion ---------------------- ";cin>>opcion2;
					switch(opcion2){
						case 1:
							cout<<"\nELIMINAR INICIO\n\n";
							lista.eliminarInicio();
							cout<<"\n\n";
							system("pause");
						break;
						case 2:
							cout<<"\nELIMINAR FINAL\n\n";
							lista.eliminarFinal();
							cout<<"\n\n";
							system("pause");
						break;
						case 3:
							cout<<"\nELIMINAR PELICULA\n\n";
							lista.eliminarVideo();
							cout<<"\n\n";
							system("pause");
						break;
						case 4:
							variable=3;
						break;
						default:
							cout<<"\n***No existe la opcion***";
							cout<<"\n\n";
				            system("pause");
						break;
					}
				}while(variable!=3);   	
			break;
			case 4:
				int isbn;
				system("cls");
				cout<<"\nBUSCAR PELICULA\n\n";
				cout<<"Ingrese el isbn de la pelicula que quiere buscar: ";cin>>isbn;
				buscarVideo=lista.obtenerVideo(isbn);
				if(buscarVideo!=NULL){
					cout<<"\nLa pelicula es: ";
					buscarVideo->obtenerNodo().imprimir();
					cout<<"\n\n";
				    system("pause");
				}
				else{
					cout<<"\n***No se encontro la pelicula***";
					cout<<"\n\n";
				    system("pause");
				}
			break;
			case 5:
				lista.editarVideo();
				cout<<"\n\n";
				system("pause");
			break;
			case 6:
				variable=6;
			break;
			default:
				cout<<"\n***No existe la opcion***";
				cout<<"\n\n";
				system("pause");
			break;
		}
		
	}while(variable!=6);
	cout<<"\n\n";
	system("pause");
	return 0;
}
