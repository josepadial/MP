/*
 Nombre: Jose Antonio Padial Molina
 DNI: 77391553A
 Curso: 2016/2017
 Grupo: 2ºB
 Fecha: 28/03/2017
 */

#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <string>

using namespace std;

struct RegAlumnos{
    char *DNI;
    char *apellido;
    char *nombre;
    double *notas;
};

//////////////////////////////////////////
void resize(double *&vec, int &cap){
    double *nuevo = new double[cap+1];
    
    for(int i = 0; i < cap; i++){
        nuevo[i] = vec[i];
    }
    cap++;
    delete [] vec;
    vec = nuevo;
}

void add(double *&vec, int &cap, double valor){
    vec[cap-1] = valor;
    resize(vec, cap);
}

void resize(char *&vec, int &cap){
    char *nuevo = new char[cap+1];
    
    for(int i = 0; i < cap; i++){
        nuevo[i] = vec[i];
    }
    cap++;
    delete [] vec;
    vec = nuevo;
}

void add(char *&vec, int &cap, char valor){
    vec[cap-1] = valor;
    resize(vec, cap);
}
//////////////////////////////////////////

void Imprime(double *vec, int cap){
    for(int i = 0; i < cap; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

double *LeerNumeros(string texto, int &pos, int &contador){
    string aux;
    double numero;
    bool continuar = true;
    int cap = 1;
    double *vec = new double[cap];
    contador = 0;
    for(int i = pos; i < texto.size() && continuar; i++){
        if(isdigit(texto[i]) || texto[i] == '.'){
            aux += texto[i];
            
        }
        else{
            numero = atof(aux.c_str());
            if(numero != 0){
                add(vec, cap, numero);
                contador++;
            }
            aux = "";
            if(isalpha(texto[i]))
                continuar = false;
        }
        pos = i;
    }
    return vec;
}

char *LeerLineaTexto(int &pos, string texto){
    int cap = 1;
    char *linea = new char[cap];
    bool continuar = true;
    char c;
    for(int i = pos; i < texto.size() && continuar; i++){
        c = texto[i];
        if(c != '\n')
            add(linea, cap, c);
        else
            continuar = false;
        pos++;
    }
    linea[cap-1] = '\0';
    return linea;
}

//////////////////////////////////

int ContarLineas(string texto){
    int lineas = 0;
    
    for(int i = 0; i < texto.size(); i++){
        if(texto[i] == '\n'){
            lineas++;
        }
    }
    
    return lineas;
}

void CalcularNota(RegAlumnos *alumnos, int num_alumnos, double calificacion_media[], double pesos[], int num_pesos){
    for(int i = 0; i < num_alumnos; i++){
        double nota_final = 0;
        for(int j = 0; j < num_pesos; j++){
            nota_final += alumnos[i].notas[j] * (pesos[j]/100);
        }
        calificacion_media[i] = nota_final;
    }
}

void MuestraVectorAlumnos(RegAlumnos datos[], double medias[], int num_alumnos){
    for(int i = 0; i < num_alumnos; i++){
        cout << datos[i].apellido << endl;
        cout << datos[i].nombre << endl;
        cout << datos[i].DNI << endl;
        cout << "Calificación media" << medias[i] << endl;
    }
}

void OrdenaVectorAlumnos (RegAlumnos datos[],double medias[], int num_alumnos){
    int i,j;
    for(i = 0; i < num_alumnos; i++){
        for(j = 0; j < i; j++){
            if(medias[i] < medias[j]){
                double temp = medias[i];
                medias[i] = medias[j];
                medias[j] = temp;
                RegAlumnos alumTemp = datos[i];
                datos[i] = datos[j];
                datos[j] = alumTemp;
            }
        }
    }
}

void MuestraVectorAlumnosConRango(RegAlumnos datos[], double medias[], int num_alumnos, double min, double max){
    for(int i = 0; i < num_alumnos; i++){
        if(min <= medias[i] && medias[i] <= max){
            cout << datos[i].apellido << endl;
            cout << datos[i].nombre << endl;
            cout << datos[i].DNI << endl;
            cout << "Calificación media" << medias[i] << endl;
        }
    }
}

int main(int argc, char **argv){
    string texto;
    getline(cin, texto, '*');
    int lineas = ContarLineas(texto);
    
    int lectura = 0;
    int num_pesos;
    int num_alumnos;
    
    LeerNumeros(texto, lectura, num_pesos);
    num_alumnos = (lineas-1) / (3+num_pesos);
    cout << "ALUMNOS: " << num_alumnos << endl;
    
    RegAlumnos *alumnos = new RegAlumnos[num_alumnos];
    
    for(int i = 0; i < num_alumnos; i++){
        alumnos[i].apellido = LeerLineaTexto(lectura, texto);
        alumnos[i].nombre = LeerLineaTexto(lectura, texto);
        alumnos[i].DNI = LeerLineaTexto(lectura, texto);
        alumnos[i].notas = LeerNumeros(texto, lectura, num_pesos);
    }
    
    /////////////////////////////////////
    int min;
    int max;
    
    double *calificacion_media = new double[num_alumnos];
    lectura = 0;
    
    CalcularNota(alumnos, num_alumnos, calificacion_media, LeerNumeros(texto, lectura, num_pesos), num_pesos);
    
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
    
    /////////////////////////////////////
    
    for(int i = 0; i < num_alumnos; i++){
        delete [] alumnos[i].apellido;
        delete [] alumnos[i].nombre;
        delete [] alumnos[i].DNI;
        delete [] alumnos[i].notas;
    }
    delete [] alumnos;
    
    return 0;
}
