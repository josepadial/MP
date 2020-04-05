#ifndef _MICADENACLASICA_H_
#define _MICADENACLASICA_H_

#include <iostream>
#include <cstdlib>

using namespace std;

int longitud_cadena(char cadena_ori[]);
bool es_palindromo(char cadena_ori[]);
int comparar_cadenas(char cadena_1[], char cadena_2[]);
void copiar_cadena(char cadena_1[], char cadena_2[]);
void encadenar_cadena(char cadena_1[], char cadena_2[]);
char *subcadena (char *cadena, int inicio, int longitud);
char *invertir (char *cadena);

#endif