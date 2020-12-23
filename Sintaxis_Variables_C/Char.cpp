#include <iostream>
#include <string.h>
using namespace std;
int ValidarChar(char CHAR[]);
int verificarC(char letra);
int main(){
	char CHAR[300];
	int valida2;
	cout<<"Ingrese tipo de variable: "; cin>>CHAR;
	valida2=ValidarChar(CHAR);	
	if(valida2 == 1){
		cout<<"tipo de variable valido";
	}else{
		cout<<"Tipo de variable invalido";
	}
}
int ValidarChar(char CHAR[]){
	int q=0;//Estado actual del automata
	int s;//Lenguaje Sigma
	int EA[6]={ 0, 0, 0, 0, 1, 0};//Estados del automata
	int Delta [6] [62] ={
		     /*  a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9*/
		/*q0*/  { 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		/*q1*/  { 5, 5, 5, 5, 5, 5, 5, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		/*q2*/  { 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		/*q3*/  { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		/*q4*/  { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		/*q5*/  { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
	};
	for(int i=0;i<strlen(CHAR);i++){//lee la cadena completa
		s=verificarC(CHAR[i]);//valida letra por letra
		q=Delta [q] [s];//cambio de estado
	}	
	return EA[q];
}
int verificarC(char letra){
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
