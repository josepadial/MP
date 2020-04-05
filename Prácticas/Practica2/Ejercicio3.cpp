#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	const int MAX = 1000;
	int v[MAX];
	const int MY_MAX_RAND = 50;
	time_t t;

	srand((int) time(&t));

	for(int i=0; i<1000; i++){
		v[i] = (rand() % ((2+MY_MAX_RAND)+1)) - MY_MAX_RAND;
	}

	for(int i= 0; i < 1000; i++){
		if(*(v+i) < 0)
			*(v+i) = *(v+i) * -1;
	}

	for(int i=0; i<1000; i++){
		cout << *(v+i) << endl;
	}

	system ("pause");

}