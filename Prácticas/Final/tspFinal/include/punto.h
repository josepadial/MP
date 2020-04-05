#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <string>
#include <cmath>

using namespace std;

class Punto {
private:
	double x;
	double y;
public:
	Punto(); //constructor. Pone a 0 las dos coordenadas
    Punto(double px, double py); // constructor. Inicializa un punto con dos valores x y
    double getX(); 
    double getY(); 
    void setX(double newXValue); 
    void setY(double newYValue); 
    string toString(); ///<  devuelve el contenido del punto como un string
    int distanciaPuntos(Punto p2); // calcula la distancia a otro punto
    Punto puntoMedio(Punto p2); //devuelve el punto medio entre el objeto implicito y p2
};

#endif
