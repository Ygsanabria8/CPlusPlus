#include <iostream>
using namespace std;
struct nodo{
	int Dato;
	nodo *sig;
};
void Menu(nodo *Cab);
nodo* primerNodo(nodo *Cab,int);
void insertarFinal(nodo *Cab,int);
nodo* eliminarDato(nodo *Cab);
void imprimir(nodo *Cab);
int main(){
	nodo *Cab=NULL;
	Menu(Cab);	
}
void Menu(nodo *Cab){
	int Opc;
	do{
		cout<<"||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"|||| 1.Insertar dato a la pila        ||||"<<endl;
		cout<<"|||| 2.Eliminar elemento de la pila   ||||"<<endl;
		cout<<"|||| 3.imprimir la pila               ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"\nDigite una opccion: "; cin>>Opc;
		switch(Opc){
			case 1:
				int Num1;
				cout<<"Ingrese el dato para ingresar a la pila: "; cin>>Num1;
				system("cls");
				if(Cab!=NULL){
					insertarFinal(Cab,Num1);
				}else{
					Cab=primerNodo(Cab,Num1);
				}
				system("PAUSE");
				system("cls");
				break;
			case 2:
				Cab=eliminarDato(Cab);
				system("PAUSE");
				system("cls");
				break;	
			case 3:
				imprimir(Cab);
				system("PAUSE");
				system("cls");
				break;	
		}
	}while(Opc!=-1);
}
nodo* primerNodo(nodo *Cab, int Num1){
	nodo *nuevoNodo=new nodo;
	nuevoNodo->Dato=Num1;
	nuevoNodo->sig=NULL;
	Cab=nuevoNodo;
	return Cab;
}
void insertarFinal(nodo *Cab,int Num1){
	nodo *Aux=Cab;
	nodo *nuevoNodo=new nodo;
	nuevoNodo->Dato=Num1;
	while(Aux->sig!=NULL){
		Aux=Aux->sig;
	}
	Aux->sig=nuevoNodo;
	nuevoNodo->sig=NULL;
}
nodo* eliminarDato(nodo *Cab){
	if(Cab!=NULL){
		nodo *Aux=Cab;
		nodo *Aux2=NULL;
		while(Aux->sig!=NULL){
			Aux2=Aux;
			Aux=Aux->sig;
		}
	if(Aux!=Cab){
		Aux2->sig=NULL;
		cout<<"["<<Aux->Dato<<"] ";
		delete Aux;
		return Cab;
	}else{
		cout<<"["<<Aux->Dato<<"] ";
		delete Aux;
		Cab=NULL;
		return Cab;
	}
	}else{
		cout<<"La pila esta Vacia"<<endl;
		return Cab;
	}
}
void imprimir(nodo *Cab){
	if(Cab){
		nodo *Aux=Cab;
		while(Aux!=NULL){
			cout<<"["<<Aux->Dato<<"] ";
			Aux=Aux->sig;
		}
	}else{
		cout<<"La pila esta Vacia"<<endl;
	}
}
