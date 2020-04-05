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

int comparar_cadenas(char cadena_1[], char cadena_2[]){
	int rta;
	int longitud_c1, longitud_c2;

	longitud_c1 = longitud_cadena(cadena_1);
	longitud_c2 = longitud_cadena(cadena_2);

	if(longitud_c1 < longitud_c2){
		rta = -1;
	}
	else if(longitud_c1 > longitud_c2){
		rta = 1;
	}
	else{
		rta = 0;
	}
	
	return rta;
}

int main(){

	const int MAX = 100;
	char cadena_1[MAX];
	char cadena_2[MAX];
	int rta;

	cin.getline(cadena_1, MAX, '\n');
	cin.getline(cadena_2, MAX, '\n');

	rta = comparar_cadenas(cadena_1,cadena_2);

	if(rta == -1){
		cout << "cadena uno es menor que cadena dos" << endl;
	}
	else if(rta == 1){
		cout << "cadena uno es mayor que cadena dos" << endl;
	}
	else{
		cout << "cadena uno es igual que cadena dos" << endl;
	}


	system ("pause");

}