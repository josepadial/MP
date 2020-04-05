/*
 Nombre: Jose Antonio Padial Molina
 DNI: 77391553A
 Curso: 2016/2017
 Grupo: 2ºB
 Fecha: 28/03/2017
 */

#include "Matriz2D_2.h"

void ReservarMatrizIndefinida(Matriz2D_2 &matriz2d){
	matriz2d.matriz = new int *[matriz2d.fil];
	matriz2d.matriz[0] = new int[matriz2d.fil*matriz2d.col];
	for(int i=1; i < matriz2d.fil; i++){
		matriz2d.matriz[i] = matriz2d.matriz[i-1]+matriz2d.col;
	}
}

void ReservarMatrizEntrada(Matriz2D_2 &matriz2d){
	matriz2d.matriz = new int *[matriz2d.fil];
	matriz2d.matriz[0] = new int[matriz2d.fil*matriz2d.col];
	for(int i=1; i < matriz2d.fil; i++){
		matriz2d.matriz[i] = matriz2d.matriz[i-1]+matriz2d.col;
	}
	for(int i=0; i < matriz2d.fil; i++)
		for(int j=0; j < matriz2d.col; j++)
			cin >> matriz2d.matriz[i][j];

}

void ReservarMatrizAleatorio(Matriz2D_2 &matriz2d){
	matriz2d.matriz = new int *[matriz2d.fil];
	matriz2d.matriz[0] = new int[matriz2d.fil*matriz2d.col];
	for(int i=1; i < matriz2d.fil; i++){
		matriz2d.matriz[i] = matriz2d.matriz[i-1]+matriz2d.col;
	}
	for(int i=0; i < matriz2d.fil; i++)
		for(int j=0; j < matriz2d.col; j++)
			matriz2d.matriz[i][j] = rand()%(matriz2d.fil*matriz2d.col);

}

Matriz2D_2 CopiarMatriz(const Matriz2D_2 &matriz2d){
	Matriz2D_2 copia(matriz2d.fil, matriz2d.col);
	ReservarMatrizIndefinida(copia);

	for(int i=0; i < matriz2d.fil; i++)
		for(int j=0; j < matriz2d.col; j++)
			copia.matriz[i][j] = matriz2d.matriz[i][j];

	return copia;
}

Matriz2D_2 SubMatriz(Matriz2D_2 &matriz2d, int f_ini, int f_fin, int c_ini, int c_fin){
	Matriz2D_2 submatriz(f_fin - f_ini+1, c_fin - c_ini+1);
	ReservarMatrizIndefinida(submatriz);
	int i_c=0, j_c=0;

	for(int i=f_ini; i <= f_fin; i++){
		for(int j=c_ini; j <= c_fin; j++){
			submatriz.matriz[i_c][j_c] = matriz2d.matriz[i][j];
			j_c++;
		}
		i_c++;
		j_c = 0;
	}

	return submatriz;
}

Matriz2D_2 EliminarFila(Matriz2D_2 &matriz2d, int fila){
	Matriz2D_2 matrizReducida(matriz2d.fil-1, matriz2d.col);
	ReservarMatrizIndefinida(matrizReducida);

	for(int i=0; i < matriz2d.fil; i++)
		for(int j=0; j < matriz2d.col; j++){
			if(i < fila)
				matrizReducida.matriz[i][j] = matriz2d.matriz[i][j];
			else if(i > fila)
				matrizReducida.matriz[i-1][j] = matriz2d.matriz[i][j];
		}

	return matrizReducida;
}

Matriz2D_2 EliminarColumna(Matriz2D_2 &matriz2d, int col){
	Matriz2D_2 matrizReducida(matriz2d.fil, matriz2d.col-1);
	ReservarMatrizIndefinida(matrizReducida);

	for(int i=0; i < matriz2d.fil; i++)
		for(int j=0; j < matriz2d.col; j++){
			if(j < col)
				matrizReducida.matriz[i][j] = matriz2d.matriz[i][j];
			else if(j > col)
				matrizReducida.matriz[i][j-1] = matriz2d.matriz[i][j];
		}

	return matrizReducida;
}

Matriz2D_2 Traspuesta(Matriz2D_2 &matriz2d){
	Matriz2D_2 traspuesta(matriz2d.fil, matriz2d.col);
	ReservarMatrizIndefinida(traspuesta);

	for(int i=0; i < matriz2d.fil; i++)
		for(int j=0; j < matriz2d.col; j++)
			traspuesta.matriz[i][j] = matriz2d.matriz[j][i];

	return traspuesta;
}

Matriz2D_2 CambiarFilas(Matriz2D_2 &matriz2d){
	Matriz2D_2 cambiada(matriz2d.fil, matriz2d.col);
	ReservarMatrizIndefinida(cambiada);

	for(int i=matriz2d.fil-1; i >= 0; i--)
		for(int j=0; j < matriz2d.col; j++)
			cambiada.matriz[i][j] = matriz2d.matriz[i][j];

	return cambiada;
}

void LiberarMatriz(Matriz2D_2 &matriz2d){
	delete [] matriz2d.matriz[0];
	delete [] matriz2d.matriz;
}

void Imprimir(Matriz2D_2 &matriz2d){
	for(int i=0; i < matriz2d.fil; i++){
		for(int j=0; j < matriz2d.col; j++)
			cout << matriz2d.matriz[i][j] << " ";
		cout << endl;
	}
}