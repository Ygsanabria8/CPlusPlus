#include <iostream>
#include <windows.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *sig;
	Nodo *ant;
};
void Menu(Nodo *Cab);
Nodo* crearNodo(Nodo *Cab);
Nodo* insertar_Inicio(Nodo *Cab);
void insertar_Medio(Nodo *Cab,int);
Nodo* eliminar_Inicio(Nodo *Cab);
void eliminar_Medio(Nodo *Aux);
void eliminar_Final(Nodo *Aux);
Nodo* buscar(Nodo *Cab,int Opc);
void imprimir_Derecho(Nodo *Cab);
void imprimir_Reves(Nodo *Cab);
int main(){
	cout<<"Ingrese el primer dato de la lista"<<endl;
	Nodo *Cab=crearNodo(Cab);
	system("cls");
	Menu(Cab);
}
void Menu (Nodo *Cab){
	int Opc;
	do{
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"||||                  MENU                    ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"|||| 1.Insertar nodo al inicio de la lista    ||||"<<endl;
		cout<<"|||| 2.Insertar nodo intermedio               ||||"<<endl;
		cout<<"|||| 3.                                       ||||"<<endl;
		cout<<"|||| 4.                                       ||||"<<endl;
		cout<<"|||| 5.                                       ||||"<<endl;
		cout<<"|||| 9.Imprimir al derecho                    ||||"<<endl;
		cout<<"|||| 10.Imprimir al reves                     ||||"<<endl;
		cout<<"|||| 0.Salir                                  ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cin>>Opc;
		system("cls");
		switch (Opc){
			case 1:
				Cab=insertar_Inicio(Cab);
				system("PAUSE");
				system("cls");
			break;
			case 2:
				int Opc1;
				imprimir_Derecho(Cab);
				cout<<"Digite la posicion que procedera al otro nodo: "; cin>>Opc1;
				insertar_Medio(Cab,Opc1);
				system("PAUSE");
				system("cls");
			break;
			case 3:
				int Opc2;
				imprimir_Derecho(Cab);
				cout<<"Digite la posicion que procedera al otro nodo: "; cin>>Opc2;
				Nodo *Aux=buscar(Cab,Opc2);
				if(Opc1==1){
					Cab=eliminar_Inicio(Cab);	
				}else if(Aux->sig==NULL){
					eliminar_Final(Aux);
				}else{
					eliminar_Medio(Aux);
				}
			break;
			case 9:
				imprimir_Derecho(Cab);
				system("PAUSE");
				system("cls");
			break;
			case 10:
				imprimir_Reves(Cab);
				system("PAUSE");
				system("cls");
			break;
		}
	}while(Opc!=0);
}
Nodo* crearNodo(Nodo *Cab){
	Nodo *nuevoNodo=new Nodo;
	cout<<"Ingrese un numero: "; cin>>nuevoNodo->dato;
	nuevoNodo->ant=NULL;
	nuevoNodo->sig=NULL;
	Cab=nuevoNodo;
	return Cab;
}
Nodo* insertar_Inicio(Nodo *Cab){
	Nodo *nuevoNodo=crearNodo(nuevoNodo);
	nuevoNodo->sig=Cab;
	Cab->ant=nuevoNodo;
	Cab=nuevoNodo;
	return Cab;
}
void insertar_Medio(Nodo *Cab,int Opc){
	Nodo *Aux1=buscar(Cab,Opc);
	Nodo *nuevoNodo=crearNodo(nuevoNodo);
	Aux1->sig->ant=nuevoNodo;
	nuevoNodo->sig=Aux1->sig;
	Aux1->sig=nuevoNodo;
	nuevoNodo->ant=Aux1;
	cout<<"Nodo creado con exito."<<endl;
}
Nodo* eliminar_Inicio(Nodo *Cab){
	Nodo *Aux=Cab;
	Cab=Cab->sig;
	Cab->ant=NULL;
	delete Aux;
	return Cab;
}
void eliminar_Medio(Nodo *Aux){
	Aux->ant->sig=Aux->sig;
	Aux->sig->ant=Aux->ant;
	delete Aux;
}
void eliminar_Final(Nodo *Aux){
	Aux->ant->sig=NULL;
	delete Aux;
}
Nodo* buscar(Nodo *Cab,int Opc){
	Nodo *Aux=Cab;
	for(int i=1;i<Opc;i++){
		Aux=Aux->sig;
	}
	return Aux;
}
void imprimir_Derecho(Nodo *Cab){
	Nodo *Aux=Cab;
	int Cont=1;
	while(Aux!=NULL){
		cout<<"Posicion "<<Cont<<":"<<Aux->dato<<endl;
		Aux=Aux->sig;
		Cont++;
	}
}
void imprimir_Reves(Nodo *Cab){
	Nodo *Aux=Cab;
	while(Aux->sig!=NULL){
		Aux=Aux->sig;
	}
	while(Aux!=NULL){
		cout<<Aux->dato<<" ";
		Aux=Aux->ant;
	}
}
