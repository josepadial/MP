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

char *subcadena (char *cadena, int inicio, int longitud){ 
	char *resultado; 
	int totalCadena = longitud_cadena(cadena); 

	if (inicio >= totalCadena){ 
		resultado = new char [1]; 
		resultado [0] = '\0'; 
		return resultado; 
	} 

	int totalSubcadena = (inicio + longitud > totalCadena) ? totalCadena - inicio : longitud;

	resultado = new char [totalSubcadena + 1]; 
	for (int i = 0; i < totalSubcadena; ++i) 
		*(resultado+i) = *(cadena+i+inicio); 

	*(resultado+totalSubcadena) = '\0'; 

	return resultado; 
} 


int main(){

	const int MAX = 100;
	char cadena_1[MAX];
	char *cadena_2;
	int pos, lon;

	cin.getline(cadena_1, MAX, '\n');
	cout << "Introduzca la posicion" << endl;
	cin >> pos;
	cout << "Introduzca la longitud" << endl;
	cin >> lon;

	cadena_2 = subcadena(cadena_1,pos,lon);

	cout << cadena_2 << endl;

	system ("pause");

}