#include <iostream>
#include "circulo.h"

Circulo::Circulo():centro(0,0), radio(0) {
}

Circulo::Circulo(Punto p, double rradio):centro(p),radio(rradio) {
}

void Circulo::set(Punto p, double rradio) {
	radio = rradio;
	centro = p;
}


Punto Circulo::getCentro()  {
	return centro;
}

double Circulo::getRadio()  {
	return radio;
}

string Circulo::toString() {
	string String = centro.toString() + " radio: " + to_string(radio);

	return String;
}

double Circulo::area() {
    return PI * radio * radio;
}

// devuelve la distancia entre sus centros
double Circulo::distancia (Circulo c2){
	double distancia;
	Punto p2(c2.getCentro());

	distancia = p2.distancia(centro);

	return distancia;
}

//Comprueba si un punto es interior al círculo
bool Circulo::interior (Punto p){
	bool esta = false;

	if(p.distancia(centro) < radio)
		esta = true;

	return esta;
}
