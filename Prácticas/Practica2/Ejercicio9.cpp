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

int main(){

	const int MAX = 100;
	int pos = 0;
	char cadena[MAX];
	int longi;

	cin.getline(cadena, MAX, '\n');

	longi = longitud_cadena(cadena);

	cout << "La longitud de la cadena es: " << longi << endl;

	system ("pause");

}