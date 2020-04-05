#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

const int TAMANIO = 100;
const char TERMINADOR = '*';
const int NUM_NOTAS = 4;
const int TAM_NOMBRE = 80;

struct RegAlumno {
    double notas[NUM_NOTAS];
    char apellido_nombre[TAM_NOMBRE]; // Cadena "clásica"
};

void LeePesos (double ponderaciones[], int num_pesos){
    for(int i = 0; i < NUM_NOTAS; i++){
        cin >> ponderaciones[i];
    }
}

bool CorrectosPesos(double vec[], int longi){
    double total_porcentaje = 0;
    for(int i = 0; i < longi; i++){
        total_porcentaje += vec[i];
    }

    if(total_porcentaje == 100)
        return true;
    else
        return false;
}

void MuestraPesos (double ponderaciones[], int num_pesos){
    for(int i = 0; i < NUM_NOTAS; i++){
        cout << ponderaciones[i] << endl;
    }
}

void AnadirNotasAlumno(RegAlumno *alumnos, int num_alumnos){
    for(int i = 0; i < NUM_NOTAS; i++){
        cin >> alumnos[num_alumnos].notas[i];
    }
}

void AnadirAlunos(RegAlumno *alumnos, int &num_alumnos){
    bool he_finalizado = false;
    cin.getline(alumnos[num_alumnos].apellido_nombre, TAM_NOMBRE, '\n');
    
    while(*alumnos[num_alumnos].apellido_nombre != TERMINADOR){
        AnadirNotasAlumno(alumnos, num_alumnos);
        num_alumnos++;
        cin.getline(alumnos[num_alumnos].apellido_nombre, TAM_NOMBRE, '\n');
    }
}

void CalcularNota(RegAlumno *alumnos, int num_alumnos, double calificacion_media[], double pesos[]){
    for(int i = 0; i < num_alumnos; i++){
        double nota_final = 0;
        for(int j = 0; j < NUM_NOTAS; j++){
            nota_final += alumnos[i].notas[j] * (pesos[j]/100);
        }
        calificacion_media[i] = nota_final;
    }
}

void MuestraVectorAlumnos (RegAlumno datos[], double medias[], int num_alumnos){
    for(int i = 0; i < num_alumnos; i++){
        cout << datos[i].apellido_nombre << endl;
        MuestraPesos(datos[i].notas, NUM_NOTAS);
        cout << "Calificación media" << medias[i] << endl;
    }
}

void OrdenaVectorAlumnos (RegAlumno datos[],double medias[], int num_alumnos){
    int i,j; 
    for(i = 0; i < num_alumnos; i++){ 
        for(j = 0; j < i; j++){ 
            if(medias[i] < medias[j]){ 
                double temp = medias[i]; 
                medias[i] = medias[j]; 
                medias[j] = temp;
                RegAlumno alumTemp = datos[i];
                datos[i] = datos[j];
                datos[j] = alumTemp;
            } 
        } 
    } 
}

void MuestraVectorAlumnosConRango(RegAlumno datos[], double medias[], int num_alumnos, double min, double max){
    for(int i = 0; i < num_alumnos; i++){
        if(min <= medias[i] && medias[i] <= max){
            cout << datos[i].apellido_nombre << endl;
            MuestraPesos(datos[i].notas, NUM_NOTAS);
            cout << "Calificación media" << medias[i] << endl;
        }
    }
}

int main(int argc, char *argv[]){
    int num_alumnos = 0;
    double max, min;
    double pesos[NUM_NOTAS];
    double calificacion_media[TAMANIO];
    RegAlumno alumnos[TAMANIO];

    LeePesos(pesos, NUM_NOTAS);

    if(CorrectosPesos(pesos, NUM_NOTAS)){
        AnadirAlunos(alumnos, num_alumnos);

        CalcularNota(alumnos, num_alumnos, calificacion_media, pesos);

        if(argc == 1){
            OrdenaVectorAlumnos(alumnos, calificacion_media, num_alumnos);
            MuestraVectorAlumnos(alumnos, calificacion_media, num_alumnos);
        }
        else if(argc == 3){
            if(atof(argv[1]) < atof(argv[2])){
                min = atof(argv[1]);
                max =  atof(argv[2]);
            }
            else{
                max = atof(argv[1]);
                min =  atof(argv[2]);
            }
            OrdenaVectorAlumnos(alumnos, calificacion_media, num_alumnos);
            MuestraVectorAlumnosConRango(alumnos, calificacion_media, num_alumnos, min, max);
        }
        else{
            cerr << "Numero erroneo de argumentos" << endl;
        }
    }
    else{
        cerr << "Porcentajes incorrectos" << endl;
    }

    system ("pause");
}