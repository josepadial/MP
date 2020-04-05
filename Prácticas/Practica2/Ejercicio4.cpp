#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	const int MAX = 1000;
	int v[MAX];
	const int MY_MAX_RAND = 50;
	time_t t;
	int *ptrINT;

	srand((int) time(&t));

	for(int i=0; i<1000; i++){
		v[i] = (rand() % ((2+MY_MAX_RAND)+1)) - MY_MAX_RAND;
	}

	ptrINT = v;

	while(ptrINT < (v+MAX)){
		if(*(ptrINT) < 0)
			*(ptrINT) = *(ptrINT) * -1;
		ptrINT++;
	}

	for(int i=0; i<1000; i++){
		cout << *(v+i) << endl;
	}

	system ("pause");

}