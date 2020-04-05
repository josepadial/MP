#include "MiCadenaClasica.h"

int main(){
	const int MAX = 100;
	int pos = 0, longi, rta, lon;
	char cadena_1[MAX];
	char cadena_2[MAX];
	char *cadena_3;
	bool es_palin;

	cout << "Introduzca la primera cadena: " << endl;
	cin.getline(cadena_1, MAX, '\n');
	cout << "Introduzca la segunda cadena: " << endl;
	cin.getline(cadena_2, MAX, '\n');

	longi = longitud_cadena(cadena_1);

	cout << "La longitud de la cadena primera es: " << longi << endl;

	longi = longitud_cadena(cadena_2);

	cout << "La longitud de la cadena segunda es: " << longi << endl;

	es_palin = es_palindromo(cadena_1);

	if(es_palin)
		cout << "Es palindromo la cadena primera" << endl;
	else
		cout << "No es palindromo la cadena primera" << endl;

	es_palin = es_palindromo(cadena_2);

	if(es_palin)
		cout << "Es palindromo la cadena segunda" << endl;
	else
		cout << "No es palindromo la cadena segunda" << endl;

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

	copiar_cadena(cadena_1,cadena_2);

	cout << "La cadena segunda a sido copiado a la primera" << endl;
	cout << "La cadena primera es: " << cadena_1 << endl;
	cout << "La cadena segunda es: " << cadena_2 << endl;

	cout << "Introduzca la primera cadena: " << endl;
	cin.getline(cadena_1, MAX, '\n');
	cout << "Introduzca la segunda cadena: " << endl;
	cin.getline(cadena_2, MAX, '\n');

	encadenar_cadena(cadena_1,cadena_2);

	cout << "La cadena segunda a sido concatenada a la primera" << endl;
	cout << "La cadena primera es: " << cadena_1 << endl;
	cout << "La cadena segunda es: " << cadena_2 << endl;

	cout << "Introduzca la posicion para crear la subcadena" << endl;
	cin >> pos;
	cout << "Introduzca la longitud para crear la subcadena" << endl;
	cin >> lon;

	cadena_3 = subcadena(cadena_1,pos,lon);

	cout << "La subcadena es: " << cadena_3 << endl;

	cadena_3 = invertir(cadena_1);

	cout << "La cadena primera invertida es: " << cadena_3 << endl;

	system ("pause");
}