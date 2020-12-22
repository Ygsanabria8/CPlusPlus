#include <iostream>
using namespace std;
struct nodo{
	int Dato;
	int Prioridad;
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
		cout<<"|||| 1.Insertar dato a la cola        ||||"<<endl;
		cout<<"|||| 2.Eliminar elemento de la cola   ||||"<<endl;
		cout<<"|||| 3.imprimir la cola               ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"\nDigite una opccion: "; cin>>Opc;
		switch(Opc){
			case 1:
				string Num1;
				int Prio;
				cout<<"Ingrese el dato para ingresar ID paciente: "; cin>>Num1;
				cout<<"Ingrese prioridad del paciente: "; cin>>Prio;
				system("cls");
				if(Cab!=NULL){
					if(Prio==1){
						insertarInicio;
					}else if(Prio==1){
						insertarMedio;
					}else{
						insertarFinal;
					}
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
		if(Cab->sig!=NULL){
			Cab=Cab->sig;
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
		cout<<"La cola esta vacia"<<endl;
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
		cout<<"La cola esta Vacia"<<endl;
	}
}
