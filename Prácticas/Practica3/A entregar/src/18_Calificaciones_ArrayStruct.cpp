#include <iostream>
#include <cstdlib>
using namespace std;

const int TAMANIO = 100;
const char TERMINADOR = '*';
const int NUM_NOTAS = 4;
const int TAM_NOMBRE = 80;

struct RegAlumno {
	double notas[NUM_NOTAS];
	char apellido_nombre[TAM_NOMBRE]; // Cadena "clásica"
};

double Suma100(double *vec, int longi){
	double total_porcentaje = 0;
	for(int i = 0; i < longi; i++){
		total_porcentaje += *(vec+i);
	}
	return total_porcentaje;
}

void AnadirNotasAlumno(RegAlumno *alumnos, int num_alumnos){
	for(int i = 0; i < NUM_NOTAS; i++){
		cin >> alumnos[num_alumnos].notas[i];
	}
}

void AnadirAlunos(RegAlumno *alumnos, int *num_alumnos){
	bool he_finalizado = false;
	cin.getline(alumnos[*num_alumnos].apellido_nombre, TAM_NOMBRE, '\n');
	AnadirNotasAlumno(alumnos, *num_alumnos);
	*num_alumnos = *num_alumnos +1;
	
	while(!he_finalizado){
		cin.getline(alumnos[*num_alumnos].apellido_nombre, TAM_NOMBRE, '\n');
		if(*alumnos[*num_alumnos].apellido_nombre == TERMINADOR){
			he_finalizado = true;
		}
		if(!he_finalizado){
			AnadirNotasAlumno(alumnos, *num_alumnos);
			*num_alumnos = *num_alumnos +1;
		}
	}
}

void CalcularNota(RegAlumno *alumnos, int num_alumnos, double *calificacion_media){
	for(int i = 0; i < num_alumnos; i++){
		double nota_final = 0;
		for(int j = 0; j < NUM_NOTAS; j++){
			nota_final += alumnos[i].notas[j];
		}
		nota_final = nota_final/4;
		*(calificacion_media+i) = nota_final;
	}
}

int main(){
	int num_alumnos = 0;
	int *ptrINT = &num_alumnos;
	double pesos[NUM_NOTAS];
	double calificacion_media[TAMANIO];
	RegAlumno alumnos[TAMANIO];

	for(int i = 0; i < NUM_NOTAS; i++){
		cin >> pesos[i];
	}

	if(Suma100(pesos, NUM_NOTAS) != 100)
		exit(-1);

	AnadirAlunos(alumnos, ptrINT);

	cout << num_alumnos << endl;

	CalcularNota(alumnos, num_alumnos, calificacion_media);

	for(int i = 0; i < num_alumnos; i++){
		cout << alumnos[i].apellido_nombre << " " << calificacion_media[i] << endl;
	}

	system ("pause");
}