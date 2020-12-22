#include <iostream>
using namespace std;
struct NB{
	int Dato;
	NB *Sig;
};
struct NA{
	int Dato;
	NA *Sig;
	NB *Sec;
};
NA* primerNA(NA *Cab);
void insertarNA(NA *Cab);
void imprimirNA(NA *Cab);
NA* Buscar(NA *Cab,int);
NB* primerNB(NB *Cab);
void insertarNB(NB *Cab);
void imprimirNB(NB *Cab);
int main(){
	NA *Cab=NULL;
	int Opc;
	do{
		cout<<"1.Crear lista principal."<<endl;
		cout<<"2.Crear Sub-lista."<<endl;
		cout<<"9.Imprimir lista primaria."<<endl;
		cout<<"\nDigite una opccion: "; cin>>Opc;
		system("cls");
		switch(Opc){
			case 1:
				char Des;
				do{
					if(Cab==NULL){
						Cab=primerNA(Cab);
						cout<<"Desea ingresar otro dato a la lista principal s=Si n=No: "; cin>>Des;
					}else{
						insertarNA(Cab);
						cout<<"Desea ingresar otro dato a la lista principal s=Si n=No: "; cin>>Des;
					}
				}while(Des=='s'or Des=='S');	
			break;
			case 2:
				int Num;
				NA *Aux;
				imprimirNA(Cab);
				cout<<"\nDigite el nodo en el cual creara la sub-lista. "; cin>>Num; 
				Aux=Buscar(Cab,Num);
				char Des1;
				do{
					if(Aux->Sec==NULL){
						Aux->Sec=primerNB(Aux->Sec);
						cout<<"\nDesea ingresar otro dato a la sub-lista s=Si n=No: "; cin>>Des1;
					}else{
						insertarNB(Aux->Sec);
						cout<<"\nDesea ingresar otro dato a la sub-lista s=Si n=No: "; cin>>Des1;
					}
				}while(Des1=='s' or Des1=='S');
				break;
			case 9:
				imprimirNA(Cab);
				system("PAUSE");
			break;
			case 10:
				NA *Aux1;
				imprimirNA(Cab);
				cout<<"\nDigite el nodo en el cual creara la sub-lista. "; cin>>Num; 
				Aux1=Buscar(Cab,Num);
				imprimirNB(Aux1->Sec);
				system("pasue");
			break;
		}
		system("cls");
	}while(Opc!=0);
}
//FUNCIONES PRIEMRA ESTRUCTURA
NA* primerNA(NA *Cab){
	NA *nuevoNodo=new NA;
	cout<<"Digite un numero: "; cin>>nuevoNodo->Dato;
	nuevoNodo->Sig=NULL;
	nuevoNodo->Sec=NULL;
	Cab=nuevoNodo;
	return Cab;
}
void insertarNA(NA *Cab){
	NA *Aux=Cab;
	NA *nuevoNodo=new NA;
	cout<<"Digite el dato del nodo: "; cin>>nuevoNodo->Dato;
	nuevoNodo->Sec=NULL;
	while(Aux->Sig!=NULL)
		Aux=Aux->Sig;
	Aux->Sig=nuevoNodo;
	nuevoNodo->Sig=NULL;	
}
NA* Buscar(NA *Cab,int Num){
	NA *Aux=Cab;
	while(Aux->Dato!=Num)
		Aux=Aux->Sig;
	return Aux;	
}
void imprimirNA(NA *Cab){
	NA *Aux=Cab;
	while(Aux!=NULL){
		cout<<"["<<Aux->Dato<<"] ";
		Aux=Aux->Sig;
	}
}
//FUNCIONES SEGUNDA ESTRUCTURA
NB* primerNB(NB *Cab){
	NB *nuevoNodo=new NB;
	cout<<"Digite un dato: "; cin>>nuevoNodo->Dato;
	nuevoNodo->Sig=NULL;
	Cab=nuevoNodo;
	return Cab;
}
void insertarNB(NB *Cab){
	NB *Aux=Cab;
	NB *nuevoNodo=new NB;
	cout<<"Digite un numero: "; cin>>nuevoNodo->Dato;
	while(Aux->Sig!=NULL)
		Aux=Aux->Sig;
	Aux->Sig=nuevoNodo;	
	nuevoNodo->Sig=NULL;
}
void imprimirNB(NB *Cab){
	NB *Aux=Cab;
	while(Aux!=NULL){
		cout<<"["<<Aux->Dato<<"] ";
		Aux=Aux->Sig;
	}
}
