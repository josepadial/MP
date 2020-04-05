BIN = bin
INC = include
LIB = lib
OBJ = obj
SRC = src

all : $(BIN)/PosicionPrimerBlanco $(BIN)/SaltarPrimeraPalabra $(BIN)/DemosCadenasClasicas

$(BIN)/PosicionPrimerBlanco: $(OBJ)/PosicionPrimerBlanco.o
	g++ -o $(BIN)/PosicionPrimerBlanco $(OBJ)/PosicionPrimerBlanco.o

$(OBJ)/PosicionPrimerBlanco.o: $(SRC)/PosicionPrimerBlanco.cpp
	g++ -c $(SRC)/PosicionPrimerBlanco.cpp -o $(OBJ)/PosicionPrimerBlanco.o -Iinclude/



$(BIN)/SaltarPrimeraPalabra: $(OBJ)/SaltarPrimeraPalabra.o
	g++ -o $(BIN)/SaltarPrimeraPalabra $(OBJ)/SaltarPrimeraPalabra.o

$(OBJ)/SaltarPrimeraPalabra.o: $(SRC)/SaltarPrimeraPalabra.cpp
	g++ -c $(SRC)/SaltarPrimeraPalabra.cpp -o $(OBJ)/SaltarPrimeraPalabra.o -Iinclude/



$(BIN)/DemosCadenasClasicas: $(OBJ)/DemosCadenasClasicas.o $(OBJ)/MiCadenaClasica.o
	g++ -o $(BIN)/DemosCadenasClasicas $(OBJ)/DemosCadenasClasicas.o $(OBJ)/MiCadenaClasica.o

$(OBJ)/DemosCadenasClasicas.o: $(SRC)/DemosCadenasClasicas.cpp
	g++ -c $(SRC)/DemosCadenasClasicas.cpp -o $(OBJ)/DemosCadenasClasicas.o -Iinclude/

$(OBJ)/MiCadenaClasica.o: $(SRC)/MiCadenaClasica.cpp $(INC)/MiCadenaClasica.h
	g++ -c $(SRC)/MiCadenaClasica.cpp -o $(OBJ)/MiCadenaClasica.o -Iinclude/


clean:
	echo "Limpiando..." //Tambien puede emplearse @echo
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/PosicionPrimerBlanco.exe $(BIN)/SaltarPrimeraPalabra.exe $(BIN)/DemosCadenasClasicas.exe