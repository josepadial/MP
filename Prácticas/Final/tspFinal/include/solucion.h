#ifndef _SOLUCION_H_
#define _SOLUCION_H_

#include <string>
using namespace std;

class Solucion{
private:
	int numCiudades;
	int *vectorSolucion;
	int longitudRecorrido;
	void ReservarMemoria();
	void LiberarMemoria();
	void copiar(const Solucion &sol);
public:
	Solucion();
	Solucion(int v[], int n); //construye una solucion a partir del vector v
	Solucion(int n); // construye una solucion de manera aleatoria
	Solucion(const Solucion &otra); // construye una solucion como copia de otra
	~Solucion(); // Destructor
	bool esCorrecta(); // verifica si los valores almacenados representan una permutacion
	int ciudad(int pos); // devuelve la ciudad que ocupa la posicion pos
	int posicion(int c); // devuelve la posicion de la ciudad c en el recorrido
	int longitud(); // devuelve la longitud del recorrido
	string toString(); // devuelve el recorrido como un string separando los datos por comas
	void mezclar();
	int getNCiudades();
	void aniadirLong(int longi);
	void set(int valor, int pos);
	Solucion& operator =(const Solucion &sol);
	int getNCiudades() const;
	int ciudad(int pos) const; 
	int longitud() const;
	string toString() const;
};

#endif