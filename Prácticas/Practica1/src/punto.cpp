#include <iostream>
#include "punto.h"

Punto::Punto():x(0),y(0) {
}

Punto::Punto(double px, double py):x(px),y(py) {
}

double Punto::getX() {
	return x;
}

double Punto::getY() {
	return y;
}

void Punto::setX(double px) {
	x = px;
}

void Punto::setY(double py) {
	y = py;
}

string Punto::toString() {
	string String = "(" + to_string(x) + ", " + to_string(y) + ")";

	return String;
}

double Punto::distancia(Punto p2){
	double distancia;

	distancia = sqrt(pow(p2.getX()-x,2)+pow(p2.getY()-y,2));

	return distancia;
}


Punto Punto::puntoMedio(Punto p2){
	double x_nueva, y_nueva;

	x_nueva = (p2.getX()+x)/2;
	y_nueva = (p2.getY()+y)/2;

	Punto medio(x_nueva,y_nueva);

	return medio;
}
