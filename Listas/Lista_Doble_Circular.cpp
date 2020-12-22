#include <iostream>
using namespace std;
struct nodo{
	int Dato;
	nodo *sig;
	nodo *ant;
};
void Menu(nodo *Cab);
nodo* crearInicio(nodo *Cab,int,int);
nodo* insertarInicio(nodo *Cab,int);
void crearFinal(nodo *Cab, int,int);
void insertarFinal(nodo *Cab,int);
nodo* eliminarPrimero(nodo *Cab);
void eliminarUltimo(nodo *Cab);
void imprimir(nodo *Cab);
void imprimir2(nodo *Cab,int);
nodo* buscar(nodo *Cab,int);
int main(){
	nodo *Cab=NULL;
	Menu(Cab);
}
void Menu(nodo *Cab){
	int Opc;
	do{
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"||||                  MENU                    ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"|||| 1.Insertar al inicio de la lista         ||||"<<endl;
		cout<<"|||| 2.Insertar al final de la lista          ||||"<<endl;
		cout<<"|||| 3.Eliminar primer nodo                   ||||"<<endl;
		cout<<"|||| 4.Eliminar ultimo nodo                   ||||"<<endl;
		cout<<"|||| 8.Impresion desde punto especifico       ||||"<<endl;	
		cout<<"|||| 9.imprimir                               ||||"<<endl;
		cout<<"|||| 0.Salir                                  ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"\nIngrese una opccion: "; cin>>Opc;
		system("cls");
		switch (Opc){
			case 1:
				int Num1,Num;
				cout<<"Digite el inicio del rango de numeros: "; cin>>Num;
				cout<<"Digite el fin del rango de numeros: "; cin>>Num1;
				Cab=crearInicio(Cab,Num,Num1);
				system("PAUSE");
				system("cls");
				break;
			case 2:
				int Num3,Num4;
				cout<<"Digite el inicio del rango de numeros: "; cin>>Num3;
				cout<<"Digite el fin del rango de numeros: "; cin>>Num4;
				crearFinal(Cab,Num3,Num4);
				system("PAUSE");
				system("cls");
				break;	
			case 3:
				Cab=eliminarPrimero(Cab);
				system("PAUSE");
				system("cls");
				break;
			case 4:
				eliminarUltimo(Cab);
				system("PAUSE");
				system("cls");
				break;
			case 8:
				int Num2;
				imprimir(Cab);
				cout<<"\nDigite el numero desde desea imprimir la lista: ";cin>>Num2;
				system("cls");
				imprimir2(Cab,Num2);
				system("PAUSE");
				system("cls");
				break;
			case 9:
				imprimir(Cab);
				system("PAUSE");
				system("cls");
				break;	
		}
	}while(Opc!=0);
}
nodo* crearInicio(nodo *Cab,int Num,int Num1){
	for(int i=Num;i<=Num1;i++){
		if(Cab==NULL){
				Cab=new nodo;
				Cab->Dato=i;
				Cab->sig=Cab;
				Cab->ant=Cab;
		}else{
			Cab=insertarInicio(Cab,i);
		}
	}
	return Cab;
}
nodo* insertarInicio(nodo *Cab,int i){
	nodo *nuevoNodo=new nodo;
	nodo *Aux=Cab;
	nuevoNodo->Dato=i;
	Aux=Aux->ant;
	Cab->ant=nuevoNodo;
	nuevoNodo->sig=Cab;
	Aux->sig=nuevoNodo;
	nuevoNodo->ant=Aux;
	Cab=nuevoNodo;
	return Cab;
}
void crearFinal(nodo *Cab,int Num3,int Num4){
	nodo *Aux=Cab;
	for(int i=Num3;i<=Num4;i++){
		insertarFinal(Cab,i);
	}
}
void insertarFinal(nodo *Cab,int i){
	nodo *nuevoNodo=new nodo;
	nodo *Aux=Cab;
	nuevoNodo->Dato=i;
	Aux=Aux->ant;
	Aux->sig=nuevoNodo;
	nuevoNodo->ant=Aux;
	Cab->ant=nuevoNodo;
	nuevoNodo->sig=Cab;
}
nodo* eliminarPrimero(nodo *Cab){
	nodo *Aux=Cab;
	nodo *Aux1=Cab->ant;
	Cab=Cab->sig;
	Cab->ant=Aux1;
	Aux1->sig=Cab;
	delete Aux;
	cout<<"Nodo eliminado con exito"<<endl;
	return Cab;
}
void eliminarUltimo(nodo *Cab){
	nodo *Aux=Cab->ant;
	nodo *Aux2=Aux->ant;
	Aux2->sig=Cab;
	Cab->ant=Aux2;
	delete Aux;
	cout<<"Nodo eliminado con exito"<<endl;
}
void imprimir(nodo *Cab){
	nodo *Aux=Cab;
		do{
			cout<<Aux->Dato<<" ";
			Aux=Aux->sig;
		}while(Aux!=Cab);
}
void imprimir2(nodo *Cab,int Dato){
	nodo *Aux=buscar(Cab,Dato);
	nodo *Aux1=Aux;
	do{
		cout<<Aux1->Dato<<" ";
		Aux1=Aux1->sig;
	}while(Aux1!=Aux);
}
nodo* buscar(nodo *Cab,int Dato){
	nodo *Aux=Cab;
	while(Aux->Dato!=Dato){
		Aux=Aux->sig;
	}
	return Aux;
}

