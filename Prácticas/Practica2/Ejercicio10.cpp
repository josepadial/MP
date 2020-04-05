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

bool es_palindromo(char cadena_ori[]){
	bool rta = true;
	int longitud;

	longitud = longitud_cadena(cadena_ori);

	char *ptrCHAR_ini = cadena_ori;
	char *ptrCHAR_fin = cadena_ori+longitud-1;


	while(ptrCHAR_ini <= ptrCHAR_fin){
		if(*ptrCHAR_ini != *ptrCHAR_fin){
			rta = false;
			return rta;
		}

		ptrCHAR_ini++;
		ptrCHAR_fin--;
	}

	return rta;
}

int main(){

	const int MAX = 100;
	int pos = 0;
	char cadena[MAX];
	bool es_palin;

	cin.getline(cadena, MAX, '\n');

	es_palin = es_palindromo(cadena);

	if(es_palin)
		cout << "Es palindromo" << endl;
	else
		cout << "No es palindromo" << endl;


	system ("pause");

}