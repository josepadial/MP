/*
 Nombre: Jose Antonio Padial Molina
 DNI: 77391553A
 Curso: 2016/2017
 Grupo: 2ºB
 Fecha: 28/03/2017
 */

#include "Matriz2D_2.h"

int main(){
	int fil, col;
	int fil_ini, fil_fin;
	int col_ini, col_fin;
	int fil_eli, col_eli;
	time_t t;
	srand((int) time(&t));

	cout << "Introduzca el numero de filas: " << endl;
	cin >> fil;
	cout << "Introduzca el numero de columnas: " << endl;
	cin >> col;

	Matriz2D_2 matriz(fil,col);
	Matriz2D_2 matriz2(fil,col);

	ReservarMatrizIndefinida(matriz);
	cout << "Matriz indefinida" << endl;
	Imprimir(matriz);
	LiberarMatriz(matriz);

	ReservarMatrizEntrada(matriz);
	cout << "Matriz de entradas" << endl;
	Imprimir(matriz);
	LiberarMatriz(matriz);

	ReservarMatrizAleatorio(matriz);
	cout << "Matriz aleatoria" << endl;
	Imprimir(matriz);
	matriz2 = CopiarMatriz(matriz);
	cout << "Matriz copiada" << endl;
	Imprimir(matriz2);
	cout << "Introduzca la fila de inicio: " << endl;
	cin >> fil_ini;
	cout << "Introduzca la fila de fin: " << endl;
	cin >> fil_fin;
	cout << "Introduzca la columna de inicio: " << endl;
	cin >> col_ini;
	cout << "Introduzca la columna de fin: " << endl;
	cin >> col_fin;
	matriz2 = SubMatriz(matriz, fil_ini, fil_fin, col_ini, col_fin);
	cout << "Submatriz" << endl;
	Imprimir(matriz2);
	cout << "Introduzca la fila a eliminar: " << endl;
	cin >> fil_eli;
	matriz2 = EliminarFila(matriz, fil_eli);
	cout << "Fila eliminada" << endl;
	Imprimir(matriz2);
	cout << "Introduzca la columna a eliminar: " << endl;
	cin >> col_eli;
	matriz2 = EliminarColumna(matriz, col_eli);
	cout << "Columna eliminada" << endl;
	Imprimir(matriz2);
	matriz2 = Traspuesta(matriz);
	cout << "Matriz traspuesta" << endl;
	Imprimir(matriz2);
	matriz2 = CambiarFilas(matriz);
	cout << "Matriz Cambiada" << endl;
	Imprimir(matriz2);
	LiberarMatriz(matriz);
	LiberarMatriz(matriz2);

	return 0;
}