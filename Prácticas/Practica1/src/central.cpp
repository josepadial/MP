#include <iostream>
#include <cstdlib>
#include "punto.h"
#include "circulo.h"

int main()
{
	double x, y, radio;

	// leer datos para circulo 1
	cout << "Introduzaca x1" << endl;
	cin >> x;
	cout << "Introduzaca y1" << endl;
	cin >> y;
	cout << "Introduzaca radio1" << endl;
	cin >> radio;
	Punto p1(x,y);
	Circulo c1(p1,radio);

	// leer datos para circulo 2
	cout << "Introduzaca x2" << endl;
	cin >> x;
	cout << "Introduzaca y2" << endl;
	cin >> y;
	cout << "Introduzaca radio2" << endl;
	cin >> radio;
	Punto p2(x,y);
	Circulo c2(p2,radio);
 
    
    // realizar los cálculos
	Punto puntomedio(0,0);
	double distacia, distacia_media;
	puntomedio = p1.puntoMedio(p2);
	distacia = p1.distancia(p2);
	distacia_media = distacia/2;

	Circulo c3(puntomedio, distacia_media);

	// mostrar resultados
        
    cout << "\nLos circulos son\n";
	cout << "Circulo 1 -> " << c1.toString() << ", area: " << c1.area() << endl;
	cout << "Circulo 2 -> " << c2.toString() << ", area: " << c2.area() << endl;
	cout << "Circulo 3 -> " << c3.toString() << ", area: " << c3.area() << endl;   
    
    cout << endl;

    system ("pause");
  	return 0;
}