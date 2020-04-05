#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	const int TOPE = 20;
	double v [TOPE];
	const int MY_MAX_RAND = 50;
	time_t t;
	double valor;
	double aux;

	double *v_fin = v+TOPE;
	double *ptrINI = v;
	double *ptrFIN = v_fin;

	srand((int) time(&t));

	for(int i=0; i<TOPE; i++){
		v[i] = (rand() % ((2+MY_MAX_RAND)+1)) - MY_MAX_RAND;
	}

	for(int i= 0; i < TOPE; i++){
		if(*(v+i) < 0)
			*(v+i) = *(v+i) * -1;
	}

	valor = v[0];
	cout << valor << endl;

	while(ptrINI < ptrFIN){
		while(*(ptrINI)<=valor){
			ptrINI++;
		}
		while(*(ptrFIN)>=valor){
			ptrFIN--;
		}
		if(ptrINI < ptrFIN){
			aux = *(ptrFIN);
			*ptrFIN = *ptrINI;
			*ptrINI = aux;

			ptrINI = v;
			ptrFIN = v_fin;
		}
	}


	for(int i=0; i<TOPE; i++){
		cout << *(v+i) << endl;
	}

	system ("pause");

}