/*
 Nombre: Jose Antonio Padial Molina
 DNI: 77391553A
 Curso: 2016/2017
 Grupo: 2ºB
 Fecha: 28/03/2017
 */

#ifndef _MATRIZ2D_H_
#define _MATRIZ2D_H_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

struct Matriz2D_1{
	int **matriz;
	int fil, col;

	Matriz2D_1(int x,int y):fil(x), col(y){};
};

void ReservarMatrizIndefinida(Matriz2D_1 &matriz2d);

void ReservarMatrizEntrada(Matriz2D_1 &matriz2d);

void ReservarMatrizAleatorio(Matriz2D_1 &matriz2d);

Matriz2D_1 CopiarMatriz(const Matriz2D_1 &matriz2d);

Matriz2D_1 SubMatriz(Matriz2D_1 &matriz2d, int f_ini, int f_fin, int c_ini, int c_fin);

Matriz2D_1 EliminarFila(Matriz2D_1 &matriz2d, int fila);

Matriz2D_1 EliminarColumna(Matriz2D_1 &matriz2d, int col);

Matriz2D_1 Traspuesta(Matriz2D_1 &matriz2d);

Matriz2D_1 CambiarFilas(Matriz2D_1 &matriz2d);

void LiberarMatriz(Matriz2D_1 &matriz2d);

void Imprimir(Matriz2D_1 &matriz2d);

#endif