#include "problema.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <cstring>

void VecinoMasCercano(Problema problema, Solucion& a, int numero){
	int ciudad = numero;
	int numeroCiudades = problema.tamanio();
	int contador = 1;
	int proxciudad = 0;
	int longi = 0;

	Solucion sol(numeroCiudades);

	bool *esta = new bool[numeroCiudades];
	for(int i=0; i<numeroCiudades; i++){
		esta[i] = false;
	}

	sol.set(ciudad, 0);
	esta[ciudad] = true;

	while(numeroCiudades != contador){
		int distan = 2147483640;
		for(int i=0; i<numeroCiudades; i++){
			if(esta[i] == false){
				if(problema.distancia(ciudad,i) < distan){
					proxciudad = i;
					distan = problema.distancia(ciudad,i);
				}
			}
		}
		ciudad = proxciudad;
		sol.set(ciudad, contador);
		contador ++;
		esta[ciudad] = true;
	}

	problema.longitudRecorrido(sol);

	a = sol;

	delete [] esta;
}

bool guardarSolucion(const char * nombre, const char * cxx, const Problema & p, const Solucion & s){
	ofstream archivo (nombre,ios::app);

	archivo << "NOMBRE DE LA INSTANCIA: " << cxx << endl;
	archivo << "TAMANIO: " << s.getNCiudades() << endl;
	archivo << "LONGITUD: " << s.longitud() << endl;
	archivo << "ORDEN" << endl;

	archivo << s.ciudad(0);
	for(int i=1; i<s.getNCiudades(); i++){
		archivo << ", " << s.ciudad(i);
	}
	archivo << "\nCOORDENADAS" << endl;
	for(int i=0; i<s.getNCiudades(); i++){
		Punto punto = p.coordenadas(s.ciudad(i));
		archivo << "(" << punto.getX() << ", " << punto.getY() << ")" << endl;
	}


    bool res= archivo.good();
    archivo.close();
    return res;
}

void buuscarMejorSol(const Problema &problema, Solucion &mejor_sol, int &mejor){
	string res;
	Solucion sol;
	VecinoMasCercano(problema, sol, 0);
	cout << "Para la ciudad " << 0 << endl;
	res = sol.toString();
	cout << res << endl;
	cout << sol.longitud() << endl;

	mejor_sol = sol;

	for(int i=1; i<problema.tamanio(); i++){
		VecinoMasCercano(problema, sol, i);
		cout << "Para la ciudad " << i << endl;
		res = sol.toString();
		cout << res << endl;
		cout << sol.longitud() << endl;

		if(sol.longitud() < mejor_sol.longitud()){
			mejor_sol = sol;
			mejor = i;
		}
	}

	cout << "El mejor recorrido es: " << mejor << endl;
	res = mejor_sol.toString();
	cout << res << endl;
}

int main(int argc, char* argv[]){
    srand(time(NULL));
	Solucion mejor_sol;
	bool escrito = false;
	bool existe = false;
	int mejor = 0;

	if(argc == 2){
		Problema problema;
		ifstream archivo;
		string nombre;

		archivo.open(argv[1]);
		archivo >> nombre;
		while(!archivo.eof()){
			existe = problema.leer(nombre.c_str());

			if(existe){
				int numeroCiudades = problema.tamanio();
				int mejor = 0;
				
				buuscarMejorSol(problema, mejor_sol, mejor);

				string nombreSol = "";
				nombreSol += "c" + to_string(numeroCiudades); 
				nombreSol += ".sol";
				char* nomFinal = new char[nombreSol.length() + 1];
				strcpy(nomFinal, nombreSol.c_str());

				escrito = guardarSolucion(nomFinal,nombre.c_str(),problema,mejor_sol);
				if(escrito){
					cout << "Mejor recorrido encontrado y guardado correctamente para " << nomFinal << endl;
				}
				else{
					cout << "Mejor recorrido encontrado y NO guardado correctamente para " << nomFinal << endl;
				}
				delete []nomFinal;
			}
			else{
				cout << "Fallo al leer el fichero para " << argv[1] << endl;
			}
			archivo >> nombre;
		}
		archivo.close();
	}
	else if(argc == 3){
		Problema problema(argv[1]);
		
		buuscarMejorSol(problema, mejor_sol, mejor);

		escrito = guardarSolucion(argv[2],argv[1],problema,mejor_sol);

		if(escrito){
			cout << "Mejor recorrido encontrado y guardado correctamente" << endl;
		}
		else{
			cout << "Mejor recorrido encontrado y NO guardado correctamente" << endl;
		}
	}
	else{
		cout << "Mal introduccidos los parametros" << endl;
	}
}
