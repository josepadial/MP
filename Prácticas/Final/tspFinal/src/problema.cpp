#include "problema.h"
#include <fstream>
#include <iostream>

void Problema::ReservarMemoria(){
	secuencia = new Punto[numCiudades];
	matrizDistancia = new int *[numCiudades];
	for(int i=0; i<numCiudades; i++){
		matrizDistancia[i] = new int[numCiudades];
	}
}

void Problema::LiberarMemoria(){
	if(numCiudades > 0){
		delete []secuencia;
		for(int i=0; i<numCiudades; i++)
			delete [] matrizDistancia[i];
		delete []matrizDistancia;
	}
}

void Problema::copiar(const Problema &pro){
	for(int i=0; i<numCiudades; i++)
		secuencia[i] = pro.secuencia[i];

	for(int i=0; i<numCiudades; i++)
		for(int j=0; j<numCiudades; j++)
			matrizDistancia[i][j] = pro.matrizDistancia[i][j];	
}

Problema::Problema(char* nombreFichero){
	string cabecera;
	ifstream archi;
	double x, y;

	archi.open(nombreFichero);

	if (!archi) {
		cerr << "No se pudo abrir el archivo " << nombreFichero;
	}

	else{
		// Leer la palabra DIMENSION:
		archi >> cabecera;
		// Leer numero de ciudades
		archi >> numCiudades;

		ReservarMemoria();
		for(int i=0; i<numCiudades; i++){
			Punto p(0,0);
			secuencia[i] = p;
		}

		// Leer coordenadas con un bucle.
		// Son 2 valores en cada fila
		for(int i = 0; i < numCiudades; i++){
			archi >> x;
			secuencia[i].setX(x);
			archi >> y;
			secuencia[i].setY(y);
			cout << "Ciudad: " << i << "\tX:" << secuencia[i].getX() << "\tY:" << secuencia[i].getY() << endl;
		}

		for(int i=0; i<numCiudades; i++)
			for(int j=0; j<numCiudades; j++)
				matrizDistancia[i][j] = 0;

		actualizarMatriz();
	}
}

int Problema::distancia(int c1, int c2){
	int distan;

	distan = matrizDistancia[c1][c2];

	return distan;
}

int Problema::distancia(int c1, int c2) const{
	int distan;

	distan = matrizDistancia[c1][c2];

	return distan;
}

Punto Problema::coordenadas(int c){
	Punto p = secuencia[c];

	return p;
}

Punto Problema::coordenadas(int c) const{
	Punto p = secuencia[c];

	return p;
}

int Problema::tamanio(){
	return numCiudades;
}

int Problema::tamanio() const{
	return numCiudades;
}

int Problema::longitudRecorrido(int solucion[], int nciudades){
	double longitud = 0;

	for(int i=0; i<nciudades-1; i++){
		longitud += secuencia[solucion[i]].distanciaPuntos(secuencia[solucion[i+1]]);
	}

	longitud += secuencia[solucion[nciudades-1]].distanciaPuntos(secuencia[solucion[0]]);

	return round(longitud);
}

Problema::~Problema(){
	LiberarMemoria();
}

void Problema::actualizarMatriz(){
	for(int i=0; i<numCiudades; i++){
		for(int j=0; j<numCiudades; j++){
			matrizDistancia[i][j] = secuencia[i].distanciaPuntos(secuencia[j]);
			matrizDistancia[j][i] = matrizDistancia[i][j];
		}
	}
}

int Problema::consultaMatriz(int i, int j){
	return matrizDistancia[i][j];
}

int Problema::consultaMatriz(int i, int j) const{
	return matrizDistancia[i][j];
}

void Problema::longitudRecorrido(Solucion & s){
	int longitud = 0;

	for(int i=0; i<numCiudades-1; i++){
		longitud += consultaMatriz(s.ciudad(i),s.ciudad(i+1));
	}

	longitud += consultaMatriz(s.ciudad(numCiudades-1),s.ciudad(0));
	s.aniadirLong(longitud);
}

void Problema::longitudRecorrido(Solucion & s) const{
	int longitud = 0;

	for(int i=0; i<numCiudades-1; i++){
		longitud += consultaMatriz(s.ciudad(i),s.ciudad(i+1));
	}

	longitud += consultaMatriz(s.ciudad(numCiudades-1),s.ciudad(0));
	s.aniadirLong(longitud);
}

Problema::Problema(const Problema &otro){
	numCiudades = otro.numCiudades;
	ReservarMemoria();

	copiar(otro);
}

Problema& Problema::operator =(const Problema &pro){
	if(&pro != this){
		delete [] this -> secuencia;
		for(int i=0; i<numCiudades; i++)
			delete [] this -> matrizDistancia[i];
		delete [] this -> matrizDistancia;

		numCiudades = pro.numCiudades;

		ReservarMemoria();

		copiar(pro);
	}

	return *this;
}

Problema::Problema(){
	numCiudades = 0;
	secuencia = 0;
	matrizDistancia=0;
}

bool Problema::leer(const char* nombreFichero){
	string cabecera;
	ifstream archi;
	double x, y;
	bool correcto = false;

	if(numCiudades != 0){
		LiberarMemoria();
		numCiudades = 0;
	}

	archi.open(nombreFichero);

	if (!archi) {
		cerr << "No se pudo abrir el archivo " << nombreFichero;
	}

	else{
		// Leer la palabra DIMENSION:
		archi >> cabecera;
		// Leer numero de ciudades
		archi >> numCiudades;

		ReservarMemoria();
		for(int i=0; i<numCiudades; i++){
			Punto p(0,0);
			secuencia[i] = p;
		}

		// Leer coordenadas con un bucle.
		// Son 2 valores en cada fila
		for(int i = 0; i < numCiudades; i++){
			archi >> x;
			secuencia[i].setX(x);
			archi >> y;
			secuencia[i].setY(y);
			cout << "Ciudad: " << i << "\tX:" << secuencia[i].getX() << "\tY:" << secuencia[i].getY() << endl;
		}

		for(int i=0; i<numCiudades; i++)
			for(int j=0; j<numCiudades; j++)
				matrizDistancia[i][j] = 0;

		actualizarMatriz();

		correcto = true;
	}

	return correcto;
}