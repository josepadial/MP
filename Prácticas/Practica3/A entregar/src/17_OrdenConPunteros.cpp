#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

int *PosMenor(int *pv, int izda, int dcha){
	int *menor = pv+izda;
	int *lectura = pv+izda;

	for(int i = izda; i <= dcha; i++, lectura++)
		if(*menor > *lectura)
			menor = lectura;

	return menor;
}

int *PosMayor(int *pv, int izda, int dcha){
	int *mayor = pv+izda;
	int *lectura = pv+izda;
	if(dcha >= 100 || izda < 0){
		exit(-1);
	}
	else{
		for(int i = izda; i <= dcha; i++, lectura++)
			if(*mayor < *lectura)
				mayor = lectura;
	}

	return mayor;
}

bool Esta(int *pos, int **ptr, int fin){

	for(int i = 0; i <= fin; i++){
		if(pos == *(ptr+i)){
			//cout << pos << " " << *(ptr+i) << endl;
			//cout << *pos << " " << **(ptr+i) << endl;
			return true;
		}
	}

	return false;
}

int *PosMenorConReferencia(int *vec, int izda, int dcha, int **ptr, int final){
	int *menor = PosMayor(vec, izda, dcha);
	int *lectura = vec+izda;
	bool esta_incluido;

	for(int i = izda; i <= dcha; i++, lectura++){
		if(*menor > *lectura){
			if(*lectura == **(ptr+final)){
				//cout << *lectura << " " << final << endl;
				esta_incluido = Esta(lectura, ptr, final);
				if(!esta_incluido){
					//cout << *lectura << " esta " << final << endl;
					menor = lectura;
				}
			}
			else if(*lectura > **(ptr+final)){
				menor = lectura;
			}
		}
	}
		

	return menor;
}

void Ordena(int *vec, int **ptr, int izda, int dcha){
	int fin = dcha - izda;
	int contador = 0;

	if(dcha >= 50 || izda < 0){
		exit(-1);
	}
	else{
		*(ptr+contador) = PosMenor(vec, izda, dcha);

		while(contador != fin){
			contador++;
			*(ptr+contador) = PosMenorConReferencia(vec, izda, dcha, ptr, contador-1);
		}
	}
}

int GenerarNumeroAleatorio(int min, int max){
	int num = (rand()%max)+min;
	return num;
}

int main(int argc, char **argv){
	const int TOPE = 50;
	int vector[TOPE];
	int *ptr[TOPE];
	int n, d;
	time_t t;
	srand((int) time(&t));

	if(argc == 1){
		for(int i = 0; i < TOPE; i++){
			 *(vector+i) = GenerarNumeroAleatorio(1, 100);
		}
		Ordena(vector, ptr, 0, TOPE-1);

		for(int i = 0; i < TOPE; i++){
			 cout<< i << ": " << *(vector+i) << endl;
		}

		for(int i = 0; i < TOPE; i++){
			 cout << i << ": "<< *ptr[i] << endl;
		}
	}
	else if(argc == 3){
		n = atoi(argv[1]);
		d = atoi(argv[2]);
		for(int i = 0; i < TOPE; i++){
			 *(vector+i) = GenerarNumeroAleatorio(1, 100);
		}

		Ordena(vector, ptr, n, d);

		for(int i = 0; i < TOPE; i++){
			 cout<< i << ": " << *(vector+i) << endl;
		}

		for(int i = 0, j = 0; i < TOPE; i++){
			if(i < n){
				cout << i << ": "<< vector[i] << endl;
			}

			if(i == n){
				cout << "Aquí empiezo a ordenar" << endl;
			}

			if(i >= n && i <= d){
				cout << i << ": "<< *ptr[j] << endl;
				j++;
			}
				
			if(i == d)
				cout << "Aquí acabo de ordenar" << endl;

			if(i > d){
				cout << i << ": "<< vector[i] << endl;
			}
		}
	}
	else{
		cout << "Numero de argumentos mal introducidos" << endl;
	}

	system ("pause");
}