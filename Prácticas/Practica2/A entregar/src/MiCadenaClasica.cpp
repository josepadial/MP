#include "MiCadenaClasica.h"

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

void copiar_cadena(char cadena_1[], char cadena_2[]){
	int longitud;

	longitud = longitud_cadena(cadena_2);
	
	for(int i = 0; i <= longitud; i++)
		*(cadena_1+i) = *(cadena_2+i);
}

void encadenar_cadena(char cadena_1[], char cadena_2[]){
	int longitud_1, longitud_2;

	longitud_1 = longitud_cadena(cadena_1);
	longitud_2 = longitud_cadena(cadena_2);
	
	for(int i = 0; i <= longitud_1+longitud_2; i++)
		*(cadena_1+(longitud_1+i)) = *(cadena_2+i);
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