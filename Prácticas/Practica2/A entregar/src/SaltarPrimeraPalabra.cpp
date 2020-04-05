#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

	const int MAX = 100;
	int pos = 0;
	char cadena[MAX];
	char *ptrCHAR_actual = cadena;

	cin.getline(cadena, MAX, '\n');

	while(*ptrCHAR_actual != ' ' && ptrCHAR_actual <= cadena+MAX){
		ptrCHAR_actual++;
	}

	if(*ptrCHAR_actual == ' '){
		cout << ptrCHAR_actual+1 << endl;
	}
	else{
		cout << "No se ha introducido ningun espacio" << endl;
	}

	system ("pause");

}