//Yesid Sanabria - 67000088 Laura Basto - 67000196
#include <iostream>
using namespace std;
int buscar(char A[], char X);
void Menu(int I[],int C[],int D[],char A[]);
void imprimirVector (char Z[]);
int main(){
	int I[]={1, 4, -1, -1 , -1, 8, -1, -1, -1, -1, -1, -1};
	int C[] = {2, -1, 6, 7, -1, 9, -1, 11, -1, -1, -1, -1};
	int D[]= {3, 5, -1, -1, -1, 10, -1, -1, -1, -1, -1, -1};
	char A[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
	Menu(I, C, D, A);
}
void Menu(int I[],int C[],int D[], char A[]){
	int Opc, num,num3,num2;
	char X, Y;
	do{
	cout<<"Menu"<<endl;
	cout<<"1. Ingresar un nodo y mostrar sus hijos. "<<endl;
	cout<<"2. Listar los nodos hoja. "<<endl;
	cout<<"3. Ingresar 2 nodos y determinar si son hermanos. "<<endl;
	cout<<"4. Salir. "<<endl;
	cin>>Opc;
	system("cls");
	switch (Opc)
		{
			case 1:
			imprimirVector(A);	
			cout<<"Ingrese nodo en maayuscula: "<<endl;
			cin>>X;
			system("cls");
			num=buscar(A, X);
			if(num==-1)
			{
				cout<<"No se encuentra "<<endl;
			}else{
				if(I[num]==-1 && C[num]==-1 && D[num]==-1)
				{
					cout<<"No tiene hijos "<<endl;
				}else if(I[num]!=-1 && C[num]==-1 && D[num]==-1){
					cout<<"El hijo es: "<<I[num];
				}else if(I[num]==-1 && C[num]!=-1 && D[num]==-1){
					cout<<"El hijo es: "<<C[num];
				}else if(I[num]==-1 && C[num]==-1 && D[num]!=-1){
					cout<<"El hijo es: "<<D[num];
				}else if(I[num]!=-1 && C[num]!=-1 && D[num]==-1){
					cout<<"Los hijos son: "<<I[num]<<" y "<<C[num];
				}else if(I[num]==-1 && C[num]!=-1 && D[num]!=-1){
					cout<<"Los hijos son: "<<D[num]<<" y "<<C[num];
				}else if(I[num]!=-1 && C[num]==-1 && D[num]!=-1){
					cout<<"Los hijos son: "<<D[num]<<" y "<<I[num];
				}else{
					cout<<"Los hijos son: "<<D[num]<<" y "<<I[num]<<" y "<<C[num];
				}
			}
			system("pause");
			break;
			
			case 2: 
				for(int i=0; i<12; i++){
					if(I[i]==-1 && C[i]==-1 && D[i]==-1)
					{
						cout<<A[i]<<endl;
					}
				}
				system("pause");
				break;
				
			case 3:
				imprimirVector(A);	
				cout<<"Ingrese 2 nodos en mayuscula: "<<endl;
				cin>>X;
				cin>>Y;
				num = buscar(A, X);
				for(int i=0;i<12; i++)
				{
					if(D[i]==num || C[i]==num || I[i]==num){
						num2=i;
					}
				}
					num3 = buscar(A, Y);
					if(	D[num2]==num3 || C[num2]==num3 || I[num2]==num3){
						cout<<"Son hermanos "<<endl;
					}else{
						cout<<"No son hermanos "<<endl;
					}
					system("pause");
				break;
			case 4:
				cout<<"Adios."<<endl;
				system("pause");
				break;
			default:
				cout<<"Opcion no valida. "<<endl;
				system("pause");
				break;
		}
		system("cls");
	}while(Opc!=4);
}
void imprimirVector (char Z[]){
	for(int i=0; i<12; i++){
		cout<<"["<<Z[i]<<"]";
	}
}

int buscar(char A[], char X)
{
	for(int i=0; i<12; i++){
		if (A[i]==X)
		{
			return i;
		}
	}
	return -1;
}


