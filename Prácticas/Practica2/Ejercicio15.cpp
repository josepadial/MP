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

char *invertir (char *cadena){ 
	char *resultado; 
	int totalCadena = longitud_cadena(cadena); 
	int fin = totalCadena-1;

	resultado = new char [totalCadena + 1]; 
	for (int i = 0; i < totalCadena; ++i, fin--) 
		*(resultado+i) = *(cadena+fin); 

	*(resultado+totalCadena) = '\0'; 

	return resultado; 
} 


int main(){

	const int MAX = 100;
	char cadena_1[MAX];
	char *cadena_2;

	cin.getline(cadena_1, MAX, '\n');

	cadena_2 = invertir(cadena_1);

	cout << cadena_2 << endl;

	system ("pause");

}