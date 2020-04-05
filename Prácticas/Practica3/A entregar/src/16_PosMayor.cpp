#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

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

int GenerarNumeroAleatorio(int min, int max){
	int num = (rand()%max)+min;
	return num;
}

int main(int argc, char **argv){
	const int TOPE = 100;
	int vector[TOPE];
	int *mayor;
	int n, d, j;
	time_t t;
	srand((int) time(&t));

	if(argc == 1){
		for(int i = 0; i < TOPE; i++){
			 *(vector+i) = GenerarNumeroAleatorio(1, 100);
		}
		mayor = PosMayor(vector, 0, TOPE-1);
		cout << *mayor << endl;
	}
	else if(argc == 2){
		n = atoi(argv[1]);
		for(int i = 0; i < n; i++){
			 *(vector+i) = GenerarNumeroAleatorio(1, 100);
		}
		mayor = PosMayor(vector, 0, n-1);
		cout << *mayor << endl;
	}
	else if(argc == 3){
		n = atoi(argv[1]);
		d = atoi(argv[2]);
		for(int i = 0; i < n; i++){
			 *(vector+i) = GenerarNumeroAleatorio(1, 100);
		}
		mayor = PosMayor(vector, 0, d);
		cout << *mayor << endl;
	}
	else if(argc == 4){
		n = atoi(argv[1]);
		d = atoi(argv[2]);
		j = atoi(argv[3]);
		for(int i = 0; i < n; i++){
			 *(vector+i) = GenerarNumeroAleatorio(1, 100);
		}
		mayor = PosMayor(vector, j, d);
		cout << *mayor << endl;
	}
	else{
		cout << "Numero de argumentos mal introducidos" << endl;
	}

	system ("pause");
}