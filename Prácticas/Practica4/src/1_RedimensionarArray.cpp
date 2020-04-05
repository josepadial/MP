 /*
 Nombre: Jose Antonio Padial Molina
 DNI: 77391553A
 Curso: 2016/2017
 Grupo: 2ºB
 Fecha: 28/03/2017
 */

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

enum TipoRedimension{DeUnoEnUno = 1, EnBloques, Duplicando};

void resize(int *&p, TipoRedimension tipo, int &cap){
    const int TAM_BLOQUE = 10;
    
    int minimo = cap;
    int *nuevo = NULL;
    
    switch (tipo) {
        case DeUnoEnUno:
            cap += 1;
            break;
        case EnBloques:
            cap += TAM_BLOQUE;
            break;
        case Duplicando:
            cap *= 2;
            break;
        default:
            cerr << "No se pudo redimensionar el vector" << endl;
            break;
    }
    
    nuevo = new int[cap];
    for(int i = 0; i < minimo; i++){
        nuevo[i] = p[i];
    }
    delete [] p;
    p = nuevo;
}

void add(int *&vec, int valor, TipoRedimension tipo, int &indice, int &tam){
    if(indice < tam){
        vec[indice] = valor;
    }
    else{
        resize(vec, tipo, tam);
        vec[indice] = valor;
    }
    indice++;
}

void Imprime(int *vec, int lon){
    for(int i = 0; i < lon; i++){
        cout << vec[i] << endl;
    }
}

int main(int argc, char *argv[]){
    int TAM = 5;
    
    int *vector = new int[TAM];
    int indice = 0;
    
    int argumento_dos;
    TipoRedimension tipo;
    string lectura;
    
    bool bien = false;
    
    if(argc == 1){
        //De uno en uno
        tipo = DeUnoEnUno;
        bien = true;
    }
    else if(argc == 2){
        //EnBloques o Duplicando
        argumento_dos = atoi(argv[1]);
        bien = true;
        switch (argumento_dos) {
            case 1:
                tipo = DeUnoEnUno;
                break;
            case 2:
                tipo = EnBloques;
                break;
            case 3:
                tipo = Duplicando;
                break;
            default:
                cerr << "Ese numero no es valido" << endl;
                bien = false;
                break;
        }
    }   
    else{
    	 cerr << "Numero erroneo de argumentos" << endl;
    }

    if(bien){
        cout << "Introduce numeros y pulsa enter. 'fin' y enter para salir" << endl;
        getline(cin, lectura);
        while(lectura != "fin"){
            add(vector, atoi(lectura.c_str()), tipo, indice, TAM);
            getline(cin, lectura);
        }
        Imprime(vector, indice);
    	cout << "TAMANIO USADO " << indice << endl;
    	cout << "TAMANIO RESERVADO " << TAM << endl;
    }


    return 0;
}