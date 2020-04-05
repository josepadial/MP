#include "solucion.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>

void Solucion::ReservarMemoria(){
	vectorSolucion = new int[numCiudades];
}

void Solucion::LiberarMemoria(){
	delete []vectorSolucion;
}

void Solucion::copiar(const Solucion &sol){
	for(int i=0; i<numCiudades;i++){
		vectorSolucion[i]=sol.vectorSolucion[i];
	}	
}

Solucion::Solucion(int v[], int n){
	numCiudades = n;
	ReservarMemoria();

	for(int i=0; i<n;i++){
		vectorSolucion[i]=v[i];
	}
}

Solucion::Solucion(int n){
	numCiudades = n;
	ReservarMemoria();

	for(int i=0; i<n; i++){
		vectorSolucion[i]=i;
	}

	mezclar();
}

Solucion::Solucion(const Solucion &otra){
	numCiudades = otra.numCiudades;
	ReservarMemoria();
	longitudRecorrido = otra.longitudRecorrido;

	copiar(otra);
}

Solucion::~Solucion(){
	if(numCiudades > 0)
		LiberarMemoria();
}

bool Solucion::esCorrecta(){
	bool *esta;
	bool loEs = true;
	esta = new bool[numCiudades];

	for(int i=0; i<numCiudades;i++){
		esta[vectorSolucion[i]] = true;
	}

	for(int i=0; i<numCiudades; i++){
		if(esta[i] == false)
			loEs = false;
	}

	delete []esta;

	return loEs;
}

int Solucion::ciudad(int pos){
	return vectorSolucion[pos];
}

int Solucion::ciudad(int pos) const{
	return vectorSolucion[pos];
}

int Solucion::posicion(int c){
	bool ciudadEncontrada = false;
	int pos = 0;

	while(!ciudadEncontrada && pos<numCiudades){
		if(vectorSolucion[pos] == c)
			ciudadEncontrada = true;
		else
			pos++;
	}

	return pos;
}

int Solucion::longitud(){
	return longitudRecorrido;
}

int Solucion::longitud() const{
	return longitudRecorrido;
}

string Solucion::toString(){
	string resultado;

	for(int i=0; i<numCiudades; i++){
		resultado += to_string(vectorSolucion[i]);
		resultado += ", ";
	}

	return resultado;
}

string Solucion::toString() const{
	string resultado;

	for(int i=0; i<numCiudades; i++){
		resultado += to_string(vectorSolucion[i]);
		resultado += ", ";
	}

	return resultado;
}

void Solucion::mezclar(){
	int posAMover = rand() % (numCiudades);
	int posAGuardar = rand() % (numCiudades);
	int aux;

	for(int i=0; i<numCiudades/2; i++){
		aux = vectorSolucion[posAGuardar];
		vectorSolucion[posAGuardar] = vectorSolucion[posAMover];
		vectorSolucion[posAMover] = aux;

		posAMover = rand() % (numCiudades);
		posAGuardar = rand() % (numCiudades);
	}
}

int Solucion::getNCiudades(){
	return numCiudades;
}

int Solucion::getNCiudades() const{
	return numCiudades;
}

void Solucion::aniadirLong(int longi){
	longitudRecorrido = longi;
}

void Solucion::set(int valor, int pos){
	if(pos < numCiudades && pos >= 0){
		vectorSolucion[pos] = valor;
	}
}

Solucion& Solucion::operator= (const Solucion &sol){
	if(this != &sol){
		LiberarMemoria();

		numCiudades = sol.numCiudades;

		ReservarMemoria();

		copiar(sol);

		longitudRecorrido = sol.longitudRecorrido;
	}

	return *this;
}

Solucion::Solucion(){
	numCiudades = 0;
	longitudRecorrido = 0;
	vectorSolucion = 0;
}