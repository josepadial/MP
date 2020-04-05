#include <iostream>
#include <cstdlib>

using namespace std;

int longitud_cadena(char cadena_ori[]){
	const int MAX = 100;
	int longitud;
	char *ptrCHAR_funcion = cadena_ori;

	while(*ptrCHAR_funcion != '\0' && ptrCHAR_funcion <= cadena_ori+MAX){
		ptrCHAR_funcion++;
	}

	longitud = ptrCHAR_funcion - cadena_ori;

	return longitud;
}

void copiar_cadena(char cadena_1[], char cadena_2[]){
	int longitud;

	longitud = longitud_cadena(cadena_2);
	
	for(int i = 0; i <= longitud; i++)
		*(cadena_1+i) = *(cadena_2+i);
}

int main(){

	const int MAX = 100;
	char cadena_1[MAX];
	char cadena_2[MAX];
	int rta;

	//cin.getline(cadena_1, MAX, '\n');
	cin.getline(cadena_2, MAX, '\n');

	copiar_cadena(cadena_1,cadena_2);

	cout << cadena_1 << endl;

	system ("pause");

}