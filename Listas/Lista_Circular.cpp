#include <iostream>
using namespace std;
struct nodo{
	int Dato;
	nodo *sig;
};
void Menu(nodo *Cab);
nodo* primerNodo(nodo *Cab,int);
nodo* crearListaInicio(nodo *Cab,int,int);
nodo* insertarInicio(nodo *Cab,int);
void crearListaFinal(nodo *Cab,int,int);
void insertarFinal(nodo *Cab,int);
nodo *eliminarPrimero(nodo *Cab);
void eliminarUltimo(nodo *Cab);
nodo* Buscar(nodo *Cab,int);
void imprimirLista(nodo *Cab);
void imprimir(nodo *Auxi);
int main(){
	nodo *Cab=NULL;
	Menu(Cab);
}
void Menu(nodo *Cab){
	int Opc;
	nodo *Auxi=NULL;
	do{
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"||||                  MENU                    ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"|||| 1.Insertar numeros al inicio             ||||"<<endl;
		cout<<"|||| 2.Insertar numeros al final              ||||"<<endl;
		cout<<"|||| 3.imprimir desde un nodo especifico      ||||"<<endl;
		cout<<"|||| 4.Eliminar primero                       ||||"<<endl;
		cout<<"|||| 5.Eliminar ultimo                        ||||"<<endl;
		cout<<"|||| 9.Imprimir lista circular                ||||"<<endl;
		cout<<"|||| 0.Salir                                  ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"\nDigite una opcion:"; cin>>Opc;
		system("cls");
		switch(Opc){
			case 1:
				int Num1,Num2;
				cout<<"Digite el inicio del ragon de numeros: "; cin>>Num1;
				cout<<"Digite el fin del rango de numeros: "; cin>>Num2;
				Cab=crearListaInicio(Cab,Num1,Num2);
				system("PAUSE");
				system("cls");
				break;
			case 2:
				int Num3,Num4;
				cout<<"Digite el inicio del rango de numeros: "; cin>>Num3;
				cout<<"Digite el fin del rango de numeros: "; cin>>Num4;
				crearListaFinal(Cab,Num3,Num4);
				system("PAUSE");
				system("cls");
				break;
			case 3:
				int Dato;
				imprimirLista(Cab);
				cout<<"\nDigite el numero desde donde desea imprimir la lista: "; cin>>Dato;
				Auxi=Buscar(Cab,Dato);
				imprimirLista(Auxi);
				system("PAUSE");
				system("cls");
				break;	
			case 4:
				Cab=eliminarPrimero(Cab);
				system("PAUSE");
				system("cls");
				break;
			case 5:
				eliminarUltimo(Cab);
				system("PAUSE");
				system("cls");
				break;
			case 9:
				imprimirLista(Cab);
				system("PAUSE");
				system("cls");
				break;
		}
	}while(Opc!=0);
}
nodo* crearListaInicio(nodo *Cab,int Num1,int Num2){
	for(int i=Num1;i<=Num2;i++){
		if(Cab==NULL){
			Cab=primerNodo(Cab,i);
		}else{
			Cab=insertarInicio(Cab,i);
		}
	}
	cout<<"Lista creada exitosamente."<<endl;
	return Cab;
}
nodo* primerNodo(nodo *Cab,int i){
	nodo *nuevoNodo=new nodo;
	nuevoNodo->Dato=i;
	Cab=nuevoNodo;
	nuevoNodo->sig=Cab;
	return Cab;
}
nodo* insertarInicio(nodo *Cab,int i){
	nodo *nuevoNodo=new nodo;
	nodo *Aux=Cab;
	nuevoNodo->Dato=i;
	nuevoNodo->sig=Cab;
	while(Aux->sig!=Cab){
		Aux=Aux->sig;
	}
	Cab=nuevoNodo;
	Aux->sig=nuevoNodo;
	return Cab;
}
void crearListaFinal(nodo *Cab,int Num3,int Num4){
	for(int i=Num3;i<=Num4;i++){
		insertarFinal(Cab,i);
	}
}
void insertarFinal(nodo *Cab,int i){
	nodo* nuevoNodo= new nodo;
	nodo *Aux=Cab;
	while(Aux->sig!=Cab){
		Aux=Aux->sig;
	}
	nuevoNodo->Dato=i;
	Aux->sig=nuevoNodo;
	nuevoNodo->sig=Cab;
}
nodo* eliminarPrimero(nodo *Cab){
	nodo *Aux=Cab;
	nodo *Elim=Cab;
	Cab=Cab->sig;
	while(Aux->sig!=Elim){
		Aux=Aux->sig;
	}
	Aux->sig=Cab;
	delete Elim;
	cout<<"Nodo eliminado con exito"<<endl;
	return Cab;
}
void eliminarUltimo(nodo *Cab){
	nodo *Aux=Cab;
	nodo *Aux1=NULL;
	while(Aux->sig!=Cab){
		Aux1=Aux;
		Aux=Aux->sig;
	}
	Aux1->sig=Cab;
	delete Aux;
}
nodo* Buscar(nodo *Cab,int Dato){
	nodo *Aux=Cab;
	while(Aux->Dato!=Dato){
		Aux=Aux->sig;
	}
	return Aux;
}
void imprimirLista(nodo *Cab){
	nodo *Aux=Cab;
	do{
		cout<<Aux->Dato<<" ";
		Aux=Aux->sig;
	}while(Aux!=Cab);
}
