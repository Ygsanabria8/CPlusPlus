#include <iostream>
#include <windows.h>
using namespace std;
struct pro{
	string nombre;
	string marca;
	int numero;
	pro *sig;
};
struct shoes{
	string referencia;
	int talla;
	bool genero;
	double precio;
	int cant_dispo;
	shoes *sig;
};
struct type{
	string marca;
	shoes *lista;
	type *sig;
};
//prototipos de funciones
void menu (type *cab,pro *prove);
type* crearPrimaria(type *cab);
void insertarMarca(type *cab);
void primerMarca(type *cab);
shoes* primerProducto(shoes *cab);
void insertarProducto (shoes *cab);
void imprimir(type *cab);
void imprimir2(shoes *cab);
type* buscar(type *cab,string);
shoes* buscar2(shoes *cab,string);
void consulta(shoes *cab);
bool marcaRepetida(type *cab,string);
bool referenciaRepetida(shoes *cab,string);
void actualizarZapato(shoes *cab);
shoes* eliminarPrimero(shoes *cab);
void eliminar(shoes *cab,shoes *elim);
pro *Crear_prov(pro *cab);
void Registropro(pro *cab);
bool validar_Prov(pro* cab,string);
void imprimir3(pro *cab);
pro* buscar3(pro *cab,string);
void consulta2(pro *cab);
void actualizarProve(pro *cab);
pro *elimPro1(pro *cab);
void elimPro2(pro *cab, pro *elim);
int main(){
	type *cab=NULL;
	pro *prove=NULL;
	cab=crearPrimaria(cab);
	system("cls");
	menu(cab,prove);
}
//Funciones
void menu (type *cab,pro *prove){
	int Opc;
	string marca,refe, provedor,nume;
	type *Aux;
	shoes *Aux2;
	pro *Aux3;
	do{
		cout<<"\t|||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"\t||||||||||||||   MENU    ||||||||||||||"<<endl;
		cout<<"\t|||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"\t||| 1) Registrar marca.             |||"<<endl;
		cout<<"\t||| 2) Registrar producto.          |||"<<endl;
		cout<<"\t||| 3) Consultar producto.          |||"<<endl;
		cout<<"\t||| 4) Actualizar Producto.         |||"<<endl;
		cout<<"\t||| 5) Eliminar Producto.           |||"<<endl;
		cout<<"\t||| 6) Registar proveedor.          |||"<<endl;
		cout<<"\t||| 7) Consultar proveedor.         |||"<<endl;
		cout<<"\t||| 8) Actualizar proveedor.        |||"<<endl;
		cout<<"\t||| 9) Eliminar proveedor.          |||"<<endl;
		cout<<"\t||| 10)Salir.                       |||"<<endl;
		cout<<"\t|||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"\t|||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"\n\tDigite una opcion: "; cin>>Opc;
		system("cls");
		switch(Opc){
			case 1:	//inserta marca			
				insertarMarca(cab);
				system("pause");
				break;
			case 2://inserta zapatos
				imprimir(cab);
				cout<<"Escriba la marca donde desea ingresar el zapato: "; cin>>marca;
				Aux=buscar(cab,marca);//buscando marca
				if(Aux!=NULL){//validando existencia de marca
					if(Aux->lista==NULL){
						Aux->lista=primerProducto(Aux->lista);//insertando siendo la cabeza nula
					}else{
						insertarProducto(Aux->lista);//insertando siendo la cabeza no nula
					}
				}else{//si no existe la marca
					cout<<"Marca inexistente"<<endl;
				}
				system("pause");
				break;
			case 3://consulta producto elegido
				imprimir(cab);
				cout<<"Escriba la marca del zapato: "; cin>>marca;	
				Aux=buscar(cab,marca);//buscando marca
				if(Aux!=NULL){//validando existencia de marca
					imprimir2(Aux->lista);
					cout<<"\nIngrese la referencia del zapato: "; cin>>refe;
					Aux2=buscar2(Aux->lista,refe);//buscando referencia
					system("cls");
					if(Aux2!=NULL){//validando existencia de la referencia
						consulta(Aux2);	//consultando datos de una referencia dada
					}else{//si no existe la referencia
						cout<<"Referencia inexistente"<<endl;
					}	
				}else{//si no existe la marca
					cout<<"marca inexistente"<<endl;
				}
				system("pause");
				break;		
			case 4://actualiza producto elegido
				imprimir(cab);
				cout<<"Ingrese la marca del zapato donde va actualizar: "; cin>>marca;
				Aux=buscar(cab,marca);//buscando marca
				if(Aux!=NULL){//validadno existencia marca
					imprimir2(Aux->lista);
					cout<<"\nIngrese la referencia del zapato a actualizar: "; cin>>refe;
					Aux2=buscar2(Aux->lista,refe);//buscando referencia
					if(Aux2!=NULL){//validando existencia referencia
						actualizarZapato(Aux2);	//actualizar datos
					}else{//si no existe referencia
						cout<<"Referencia inexistente"<<endl;
					}
				}else{//si no existe la marca
					cout<<"Marca inexistente"<<endl;
				}
				system("pause");
				break;
			case 5://elimina zapato elegido
				imprimir(cab);
				cout<<"Ingrese la marca del zapato donde eliminara el zapato: "; cin>>marca;
				Aux=buscar(cab,marca);
				if(Aux!=NULL){
					imprimir2(Aux->lista);
					cout<<"\nIngrese la referencia del zapato a eliminar: "; cin>>refe;
					Aux2=buscar2(Aux->lista,refe);
					if(Aux2!=NULL){
						if(Aux2==Aux->lista){
							Aux->lista=eliminarPrimero(Aux->lista);
							cout<<"Referencia eliminada con exito."<<endl;
						}else{
							eliminar(Aux->lista,Aux2);
							cout<<"Referencia eliminada con exito."<<endl;
						}
					}else{
						cout<<"Producto inexistente"<<endl;
					}
				}else{
					cout<<"Marca inexistente"<<endl;
				}
				system("pause");
				break;		
			case 6://insertar proveedor
				if(prove==NULL){
					prove=Crear_prov(prove);
				}else{
					Registropro(prove);
				}
				system("pause");
				break;
			case 7://consulta de provedor
				imprimir3(prove);
				cout<<"Ingrese la marcar para colsuntar el proveedor: "; cin>>marca;
				Aux3=buscar3(prove,marca);
				if(Aux3==NULL){
					cout<<"Proveedor no registrado."<<endl;
				}else{
					consulta2(prove);
				}
				system("pause");
				break;
			case 8:
				if (prove==NULL){
					cout<<"No ha cargado ningun proveedor. "<<endl;
				}else{
					imprimir3(prove);
					cout<<"Ingrese el proveedor que desea actualizar: "; cin>>provedor;
					Aux3=buscar3(prove, provedor);//buscando marca
					if(Aux!=NULL){//validando existencia marca
						actualizarProve(prove);				
					}else{//si no existe la marca
						cout<<"Proveedor inexistente"<<endl;
					}
				}				
				system("pause");
				break;
			case 9:
				imprimir3(prove);
				cout<<"Ingrese la marca del zapato donde eliminara el zapato: "; cin>>marca;
				Aux3=buscar3(prove,marca);				
					if(Aux3==prove){
							prove=elimPro1(Aux3);
							cout<<"Proveedor eliminado con exito."<<endl;
						}else{
							elimPro2(prove, Aux3);
							cout<<"Referencia eliminada con exito."<<endl;
						}		
				break;
			case 10:
				cout<<"Gracias por utilizar nuestro servicios"<<endl;
				system("pause");
				break;		
			default:
				cout<<"Opcion invalida"<<endl;
				system("pause");
				break;	
		}
		system("cls");
	}while(Opc!=10);
}
type* crearPrimaria(type *cab){//crea lista primaria hasta que el usuario desee al iniciar programa
	int Opc;
	bool validar;
	type *nuevo=new type;
	cout<<"Ingrese la marca a registrar: "; cin>>nuevo->marca;
	nuevo->lista=NULL;
	nuevo->sig=NULL;
	cab=nuevo;
	fflush(stdin);//limpiando buffer
	cout<<"Desea ingresar otra marca, 1[si] o 2[no]: "; cin>>Opc;
	system("cls");
	while(Opc==1){
		type *temp=nuevo;
		nuevo=new type;
		do{//REPITE HASTA QUE NO SEA REPETIDA
			cout<<"Ingrese la marca a registrar: "; cin>>nuevo->marca;
			validar=marcaRepetida(cab,nuevo->marca);//VALIDANDO MARCAS NO REPETIDAS
			if(validar==true){
				cout<<"Marca repetida"<<endl;
				system("pause");
				system("cls");
			}	
		}while(validar!=false);
		nuevo->lista=NULL;
		nuevo->sig=NULL;
		temp->sig=nuevo;
		fflush(stdin);//limpiando buffer
		cout<<"Desea ingresar otra marca, 1[si] o 2[no]: "; cin>>Opc;
		system("cls");
	}
	return cab;
}
void insertarMarca(type *cab){//insertar marcas hasta que el ususario desee
	bool validar;
	int Opc;
	type *Aux=cab;
	type *nuevo=new type;
	do{//REPITE HASTA QUE NO SEA REPETIDA
		cout<<"Ingrese la marca a registrar: "; cin>>nuevo->marca;
		validar=marcaRepetida(cab,nuevo->marca);//VALIDANDO MARCAS NO REPETIDAS
		if(validar==true){
			cout<<"Marca repetida"<<endl;
			system("pause");
			system("cls");
		}	
	}while(validar!=false);
	while(Aux->sig!=NULL)
	Aux=Aux->sig;
	nuevo->lista=NULL;
	nuevo->sig=NULL;
	Aux->sig=nuevo;
	fflush(stdin);//limpiando buffer
	cout<<"Desea ingresar otra marca, 1[si] o 2[no]: "; cin>>Opc;
	system("cls");
	while(Opc==1){//se repite tantas veces desee el usuario
		validar==true;
		type *temp=nuevo;
		nuevo=new type;
		do{//REPITE HASTA QUE NO SEA REPETIDA
			cout<<"Ingrese la marca a registrar: "; cin>>nuevo->marca;
			validar=marcaRepetida(cab,nuevo->marca);//VALIDANDO MARCAS NO REPETIDAS
			if(validar==true){
				cout<<"Marca repetida"<<endl;
				system("pause");
				system("cls");
			}		
		}while(validar!=false);
		nuevo->lista=NULL;
		nuevo->sig=NULL;
		temp->sig=nuevo;
		fflush(stdin);//limpiando buffer
		cout<<"Desea ingresar otra marca, 1[si] o 2[no]: "; cin>>Opc;
	}

}
shoes* primerProducto(shoes *cab){//insertar producto hasta que el usuario desee en marca seleccionada
	int Opc;
	bool Val;
	shoes *Temp;
	shoes *Aux=new shoes;
	cout<<"Ingrese referencia del zapato: "; cin>>Aux->referencia;
	fflush(stdin);//limpiando buffer
	cout<<"Ingrese la talla del zapato: "; cin>>Aux->talla;
	cout<<"Si es de dama digite[1] de caballero digite[0]: "; cin>>Aux->genero;
	fflush(stdin); 
	cout<<"Digite el precio del zapato: "; cin>>Aux->precio;
	cout<<"Digite cantidad de zapatos disponibles: "; cin>>Aux->cant_dispo;
	Aux->sig=NULL;
	cab=Aux;
	cout<<"\nDesea ingresar mas zapatos si[1] no[2]: "; cin>>Opc;
	system("cls");
	while(Opc==1){
		Temp=Aux;
		Aux=new shoes;
		do{//se hara hasta que no se repita la referencia
			cout<<"Ingrese referencia del zapato: "; cin>>Aux->referencia;
			Val=referenciaRepetida(cab,Aux->referencia);
			if(Val==true){
				cout<<"Referencia repetida."<<endl;
				system("pause");
				system("cls");
			}
		}while(Val==true);
		fflush(stdin);//limpiando buffer
		cout<<"Ingrese la talla del zapato: "; cin>>Aux->talla;
		cout<<"Si es de dama digite[1] de caballero digite[0]: "; cin>>Aux->genero; 
		cout<<"Digite el precio del zapato: "; cin>>Aux->precio;
		cout<<"Digite cantidad de zapatos disponibles: "; cin>>Aux->cant_dispo;
		Aux->sig=NULL;
		Temp->sig=Aux;
		fflush(stdin);//limpiando buffer
		cout<<"\nDesea ingresar mas zapatos si[1] no[2]: "; cin>>Opc;
		system("cls");
	}
	return cab;
}
void insertarProducto (shoes *cab){
	int Opc;
	bool Val;
	shoes *Aux=cab;
	shoes *Temp;
	shoes *nuevo=new shoes;
	do{//se hara hasta que no se repita la referencia
		cout<<"Ingrese referencia del zapato: "; cin>>nuevo->referencia;
		Val=referenciaRepetida(cab,nuevo->referencia);
		if(Val==true){
			cout<<"Referencia repetida."<<endl;
			system("pause");
			system("cls");
		}
	}while(Val==true);
	cout<<"Ingrese la talla del zapato: "; cin>>nuevo->talla;
	cout<<"Si es de dama digite[1] de caballero digite[0]: "; cin>>nuevo->genero; 
	fflush(stdin);//limpiando biffer
	cout<<"Digite el precio del zapato: "; cin>>nuevo->precio;
	cout<<"Digite cantidad de zapatos disponibles: "; cin>>nuevo->cant_dispo;
	nuevo->sig=NULL;
	while(Aux->sig!=NULL)
		Aux=Aux->sig;
	Aux->sig=nuevo;
	cout<<"\nDesea ingresar otro zapato si[1] no[2]: "; cin>>Opc;
	system("cls");
	do{//se hara tantas veces desee el usuario
		Val=-1;
		Temp=nuevo;
		nuevo=new shoes;
		do{//se hara hasta que no se repita la referencia
			cout<<"Ingrese referencia del zapato: "; cin>>nuevo->referencia;
			Val=referenciaRepetida(cab,nuevo->referencia);
			if(Val==1){
				cout<<"Referencia repetida."<<endl;
				system("pause");
				system("cls");
			}
		}while(Val==1);
		cout<<"Ingrese la talla del zapato: "; cin>>nuevo->talla;
		cout<<"Si es de dama digite[1] de caballero digite[0]: "; cin>>nuevo->genero; 
		fflush(stdin);//limpiando buffer
		cout<<"Digite el precio del zapato: "; cin>>nuevo->precio;
		cout<<"Digite cantidad de zapatos disponibles: "; cin>>nuevo->cant_dispo;	
		nuevo->sig=NULL;
		Temp->sig=nuevo;
		cout<<"\nDesea ingresar otro zapato si[1] no[2]: "; cin>>Opc;
	}while(Opc==1);
}
void imprimir(type *cab){//imprimir lista primaria
	type *Aux=cab;
	while(Aux!=NULL){
		cout<<Aux->marca<<endl;
		Aux=Aux->sig;
	}
}
void imprimir2(shoes *cab){//imprimir lista secundaria dada
	shoes *Aux=cab;
	while(Aux!=NULL){
		cout<<Aux->referencia<<" ";
		Aux=Aux->sig;
	}
}
type* buscar(type *cab,string marca){//busqueda marca
	type *Aux=cab;
	while(Aux!=NULL){
		if(Aux->marca==marca)
			return  Aux;
		Aux=Aux->sig;	
	}
	return NULL;	
}
shoes* buscar2(shoes *cab,string refe){//busqueda referencia
	shoes *Aux=cab;
	while(Aux!=NULL){
		if(Aux->referencia==refe)
			return Aux;
		Aux=Aux->sig;
	}
	return NULL;
}
void consulta(shoes *cab){//consulta de zapatos dada una referencia
	cout<<"La referencia es: "<<cab->referencia<<endl;
	cout<<"La talla del zapato es: "<<cab->talla<<endl;
	if(cab->genero==true){
		cout<<"El zapato es para: Dama"<<endl;
	}else{
		cout<<"El zapato es para: Caballero"<<endl;
	}
	cout<<"El precio del zapato es: "<<cab->precio<<endl;
	cout<<"La cantidad disponible son: "<<cab->cant_dispo<<endl;
}
bool marcaRepetida(type *cab,string marca){//buscador marca repetida
	type *Aux=cab;
	while(Aux!=NULL){
		if(Aux->marca==marca){
			return true;
		}
		Aux=Aux->sig;
	}
	return false;
}
bool referenciaRepetida(shoes *cab,string ref){//busca referencia repetida
	shoes *Aux=cab;
	while(Aux!=NULL){
		if(Aux->referencia==ref){
			return true;
		}
		Aux=Aux->sig;
	}
	return false;
}
void actualizarZapato(shoes *cab){//actualiza datos
	int Opc;
	do{
		cout<<"Produto a actualizar: "<<cab->referencia<<endl;
		cout<<"||||||||||||||||||||||||||||||"<<endl;
		cout<<"|| 1)Actualizar precio      ||"<<endl;
		cout<<"|| 2)Actualizar cantidad    ||"<<endl;
		cout<<"|| 3)No actualizar          ||"<<endl;
		cout<<"||||||||||||||||||||||||||||||"<<endl;
		cout<<"\nDigite una opcion: "; cin>>Opc;
		switch(Opc){
			case 1://actualiza precio
				cout<<"Inserte el nuevo precio del zapato: "; cin>>cab->precio;
				cout<<"Precio actualizado a "<<cab->precio<<endl;
				system("pause");
				break;
			case 2://actualiza cantidad
				cout<<"Ingrese la nueva cantidad de zapatos disponible: "; cin>>cab->cant_dispo;
				cout<<"La nueva cantidad disponible de zapatos es: "<<cab->cant_dispo<<endl;
				system("pause");
				break;
			case 3://sale del menu actualizacion
				cout<<"No se ha realizado ningun cambio."<<endl;
				system("pause");
				break;
			default://se repite hasta tener opcion valida
				cout<<"Opcion no disponible"<<endl;
				system("pause");
				break;			
		}
		system("cls");
	}while(Opc!=3);
}
shoes* eliminarPrimero(shoes *cab){//elimina primer nodo del la sub-lista
	shoes *Aux=cab;
	cab=cab->sig;
	delete Aux;
	return cab;
}
void eliminar(shoes *cab,shoes *elim){//elimina nodo intermedio o final de una sub-lista
	shoes *Aux=cab;
	while(Aux->sig!=elim)
		Aux=Aux->sig;
	Aux->sig=elim->sig;
	delete elim;		
}
pro *Crear_prov(pro *cab){//regisytrando proveedor con lista vacia
	pro *Aux =cab;
	int Opc;
	bool val;
	pro *nuevo= new pro;
	nuevo->sig=NULL;
	cout<<"Ingrese nombre del proveedor: "<<endl; cin>>nuevo->nombre;
	cout<<"Ingrese la marca a la que provee: "<<endl; cin>>nuevo->marca;
	cout<<"Ingrese el numero de contacto: "<<endl; cin>>nuevo->numero;
	nuevo->sig=NULL;
	fflush(stdin);//limpiando buffer
	cab=nuevo;
	cout<<"Desea ingresar otro proveedor 1[si] , 2[no] :"; cin>>Opc;
	system("cls");
	while(Opc!=2){
		pro *temp=nuevo;
		nuevo=new pro;
		cout<<"Ingrese nombre del proveedor: "<<endl; cin>>nuevo->nombre;
		do{//repite hasta que el no exista un provedor de una marca dada
			cout<<"Ingrese la marca a la que provee: "<<endl; cin>>nuevo->marca;
			val=validar_Prov(cab,nuevo->marca);
			if(val==true){
				cout<<"Provedoor existente."<<endl;
				system("pause");
				system("cls");
			}
			fflush(stdin);//limpiando buffer
		}while(val==true);
		fflush(stdin);//limpiando buffer
		cout<<"Ingrese el numero de contacto: "<<endl; cin>>nuevo->numero;	
		nuevo->sig=NULL;
		temp->sig=nuevo;
		cout<<"Desea ingresar otro proveedor 1[si] , 2[no] :"; cin>>Opc;
		system("cls");
	}
	return cab;	
}
void Registropro(pro *cab)//registrando provedoor con lista ya cargada
{
	pro *Aux =cab;
	int Opc;
	bool val;
	pro *nuevo= new pro;
	while(Aux->sig!=NULL)
		Aux=Aux->sig;			
	nuevo->sig=NULL;
	cout<<"Ingrese nombre del proveedor: "<<endl; cin>>nuevo->nombre;
	do{//repite hasta que el no exista un provedor de una marca dada
			cout<<"Ingrese la marca a la que provee: "<<endl; cin>>nuevo->marca;
			val=validar_Prov(cab,nuevo->marca);
			if(val==true){
				cout<<"Provedoor existente."<<endl;
				system("pause");
				system("cls");
			}
	}while(val==true);
	fflush(stdin);//limpiando buffer
	cout<<"Ingrese el numero de contacto: "<<endl; cin>>nuevo->numero;
	Aux->sig=nuevo;
	nuevo->sig=NULL;
	cout<<"Desea ingresar otro proveedor 1[si] , 2[no] :"; cin>>Opc;
	system("cls");
	while(Opc!=2){
		pro *temp=nuevo;
		nuevo=new pro;
		cout<<"Ingrese nombre del proveedor: "<<endl; cin>>nuevo->nombre;
		do{//repite hasta que el no exista un provedor de una marca dada
			cout<<"Ingrese la marca a la que provee: "<<endl; cin>>nuevo->marca;
			val=validar_Prov(cab,nuevo->marca);
			if(val==true){
				cout<<"Provedoor existente."<<endl;
				system("pause");
				system("cls");
			}
		}while(val==true);
		fflush(stdin);//limpiando buffer
		cout<<"Ingrese el numero de contacto: "<<endl; cin>>nuevo->numero;	
		nuevo->sig=NULL;
		temp->sig=nuevo;
		cout<<"Desea ingresar otro proveedor 1[si] , 2[no] :"; cin>>Opc; 
		system("cls");
	}
}
bool validar_Prov(pro* cab, string idProv){//revisa provedores para no ingresar proveedores no repetida
	pro *Aux = cab;
	while(Aux!=NULL){
		if(Aux->marca==idProv)
			return true;
		Aux=Aux->sig;
	}
	return false;
}
void imprimir3(pro *cab){//imprime lista proveedores
	pro *Aux=cab;
	while(Aux!=NULL){
		cout<<Aux->marca<<" ";
		Aux=Aux->sig;
	}
}
pro* buscar3(pro *cab,string marca){//busca nodo en lista proveedores
	pro *Aux=cab;
	while(Aux!=NULL){
		if(Aux->marca==marca)
			return Aux;
		Aux=Aux->sig;	
	}
	return NULL;
}
void consulta2(pro *cab){//imprime datos del nodo provedoor seleccionado
	cout<<"Nombre: "<<cab->nombre<<endl;
	cout<<"Marca que provee: "<<cab->marca<<endl;
	cout<<"Numero: "<<cab->numero<<endl;
}
void actualizarProve(pro *cab){
	int Opc;
	do{
		cout<<"Actualice proveedor: "<<cab->nombre<<endl;
		cout<<"||||||||||||||||||||||||||||||"<<endl;
		cout<<"|| 1)Actualizar nombre      ||"<<endl;
		cout<<"|| 2)Actualizar numero      ||"<<endl;
		cout<<"|| 3)No actualizar          ||"<<endl;
		cout<<"||||||||||||||||||||||||||||||"<<endl;
		cout<<"\nDigite una opcion: "; cin>>Opc;
		switch(Opc){
			case 1://actualiza proveedor
				cout<<"Inserte el nuevo nombre del proveedor: "; cin>>cab->nombre;
				system("pause");
				break;
			case 2://actualiza cantidad
				cout<<"Ingrese el nuevo numero del proveedor: "; cin>>cab->numero;
				system("pause");
				break;
			case 3://sale del menu actualizacion
				cout<<"No se ha realizado ningun cambio."<<endl;
				system("pause");
				break;
			default://se repite hasta tener opcion valida
				cout<<"Opcion no disponible. "<<endl;
				system("pause");
				break;			
		}
		system("cls");
	}while(Opc!=3);
}
pro* elimPro1(pro *cab){//primer nodo
	pro *Aux=cab;
	cab=cab->sig;
	delete Aux;
	return cab;
}
void elimPro2(pro *cab, pro *elim){//elimina nodo intermedio o final de una sub-lista
	pro *Aux=cab;
	while(Aux->sig!=elim)
		Aux=Aux->sig;
	Aux->sig=elim->sig;
	delete elim;		
}
