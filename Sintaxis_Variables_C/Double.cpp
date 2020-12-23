#include <iostream>
#include <string.h>
using namespace std;
int ValidaDouble (char []);
int verificarD (char);
int main(){
	char DOUBLE[300];//Donde se almacena la cadena
	int valida5;//T o F se es tipo valido de variable
	cout<<"Tipo de variable: "; cin>>DOUBLE;
	valida5=ValidaDouble(DOUBLE);
	if(valida5 == 1){
		cout<<"tipo de variable valido";
	}else{
		cout<<"Tipo de variable invalido";
	}
}
int ValidaDouble(char DOUBLE[]){
	int q=0;//Estado actual del automata
	int s;//Lenguaje Sigma
	int EA[8]={ 0, 0, 0, 0, 0, 0, 1, 0};//Estados del automata
	int Delta [8] [62] ={
		     /*  a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9*/
		/*q0*/  { 7, 7, 7, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
		/*q1*/  { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
		/*q2*/  { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
		/*q3*/  { 7, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
		/*q4*/  { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
		/*q7*/  { 7, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
		/*q6*/  { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
		/*q7*/  { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	};
	for(int i=0;i<strlen(DOUBLE);i++){//lee la cadena completa
		s=verificarD(DOUBLE[i]);//valiaa caracter por caracter
		q=Delta [q] [s];//cambia de estado
	}	
	return EA[q];
}
int verificarD(char letra){
	if(letra == 'a') return 0;
	if(letra == 'b') return 1;
	if(letra == 'c') return 2;
	if(letra == 'd') return 3;
	if(letra == 'e') return 4;
	if(letra == 'f') return 5;
	if(letra == 'g') return 6;
	if(letra == 'h') return 7;
	if(letra == 'i') return 8;
	if(letra == 'j') return 9;
	if(letra == 'k') return 10;
	if(letra == 'l') return 11;
	if(letra == 'm') return 12;
	if(letra == 'n') return 13;
	if(letra == 'o') return 14;
	if(letra == 'p') return 15;
	if(letra == 'q') return 16;
	if(letra == 'r') return 17;
	if(letra == 's') return 18;
	if(letra == 't') return 19;
	if(letra == 'u') return 20;
	if(letra == 'v') return 21;
	if(letra == 'w') return 22;
	if(letra == 'x') return 23;
	if(letra == 'y') return 24;
	if(letra == 'z') return 25;
	if(letra == 'A') return 26;
	if(letra == 'B') return 27;
	if(letra == 'C') return 28;
	if(letra == 'D') return 29;
	if(letra == 'E') return 30;
	if(letra == 'F') return 31;
	if(letra == 'G') return 32;
	if(letra == 'H') return 33;
	if(letra == 'I') return 34;
	if(letra == 'J') return 35;
	if(letra == 'K') return 36;
	if(letra == 'L') return 37;
	if(letra == 'M') return 38;
	if(letra == 'N') return 39;
	if(letra == 'O') return 40;
	if(letra == 'P') return 41;
	if(letra == 'Q') return 42;
	if(letra == 'R') return 43;
	if(letra == 'S') return 44;
	if(letra == 'T') return 45;
	if(letra == 'U') return 46;
	if(letra == 'V') return 47;
	if(letra == 'W') return 48;
	if(letra == 'X') return 49;
	if(letra == 'Y') return 50;
	if(letra == 'Z') return 51;
	if(letra == '0') return 52;
	if(letra == '1') return 53;
	if(letra == '2') return 54;
	if(letra == '3') return 55;
	if(letra == '4') return 56;
	if(letra == '5') return 57;
	if(letra == '6') return 58;
	if(letra == '7') return 59;
	if(letra == '8') return 60;
	if(letra == '9') return 61;
	else{
		cout<<"Caracter invalido"<<endl;
	}
}
