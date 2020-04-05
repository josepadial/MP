/**
   @file circulomedio.cpp
   @brief Calcula c�rculo con centro en medio de dos c�rculos y radio la mitad de la distancia
   @warning M�dulo no definitivo (creado para ser modificado)

// si quieres utilizar la funcion to_string(), recuerde agregar -std=c++0x a las opciones del compilador

**/

#include <iostream>
#include <cmath> 
#include <string>

using namespace std;

const double PI = 3.14159265;
class Punto {
private:
    double x; // coordenada x del punto
    double y; // coordenada y del punto

public:
    Punto(); //constructor. Pone a 0 las dos coordenadas
    Punto(double px, double py); // constructor. Inicializa un punto con dos valores x y
    double getX(); 
    double getY(); 
    void setX(double newXValue); 
    void setY(double newYValue); 
    string toString(); ///<  devuelve el contenido del punto como un string
    double distancia(Punto p2); // calcula la distancia a otro punto
    Punto puntoMedio(Punto p2); //devuelve el punto medio entre el objeto implicito y p2
};

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
 // devuelve un string con el formato (x,y)
}

double Punto::distancia(Punto p2){
}


Punto Punto::puntoMedio(Punto p2){
}


class Circulo {
private:
    Punto centro; // Centro del c�rculo
    double radio; // radio del c�rculo

public:
    Circulo(); // Constructor: Pone a 0 el punto y el radio
    Circulo(Punto centro, double rradio); // Constructor: Inicializa el c�rculo con un centro y un radio
    void set(Punto centro, double rradio); // Asigna el centro y el radio a un circulo
    Punto getCentro(); 
    double getRadio(); 
    string toString(); // devuelve el contenido del circulo como un string
    double area(); // Devuelve el �rea de un c�rculo
    double distancia (Circulo c2);
    bool interior (Punto p); // true si p est� contenido en el c�rculo
};

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
}

double Circulo::area() {
    return PI * radio * radio;
}

// devuelve la distancia entre sus centros
double Circulo::distancia (Circulo c2){
	
}

//Comprueba si un punto es interior al c�rculo
bool Circulo::interior (Punto p){
}


int main()
{


	// leer datos para circulo 1
	
	// leer datos para circulo 2
	
 
    
    // realizar los c�lculos


	// mostrar resultados
    
/*    
    cout << "\nLos circulos son\n";
	cout << "Circulo 1 -> " << c1.toString() << ", area: " << c1.area() << endl;
	cout << "Circulo 2 -> " << c2.toString() << ", area: " << c2.area() << endl;
	cout << "Circulo 3 -> " << c3.toString() << ", area: " << c3.area() << endl;
 */   
    
    cout << endl;
}

/* Fin: circulomedio.cpp */
 
