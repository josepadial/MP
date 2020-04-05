#ifndef _PROBLEMA_H_
#define _PROBLEMA_H_

#include "punto.h"
#include "solucion.h"
using namespace std;

class Problema{
private:
	int numCiudades;
	Punto *secuencia;
	int **matrizDistancia;
	void ReservarMemoria();
	void LiberarMemoria();
	void copiar(const Problema &pro);
public:
	Problema(char* nombreFichero); // Lee los datos del fichero
	int distancia(int c1, int c2); // Distancia entre dos ciudades
	Punto coordenadas(int c); // Coordenadas de la ciudad C
	int tamanio(); // Numero de ciudades
	int longitudRecorrido(int solucion[], int nciudades); // Calcular recorrido
	~Problema(); // Destructor
	void actualizarMatriz();
	int consultaMatriz(int i, int j);
	int consultaMatriz(int i, int j) const;
	void longitudRecorrido(Solucion & s);
	Problema(const Problema &otro);
	Problema& operator =(const Problema &pro);
	int tamanio() const;
	Punto coordenadas(int c) const;
	Problema();
	bool leer(const char* nombreFichero);
	int distancia(int c1, int c2) const;
	void longitudRecorrido(Solucion & s) const;
};

#endif