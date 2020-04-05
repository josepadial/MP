BIN = bin
INC = include
LIB = lib
OBJ = obj
SRC = src

all : $(BIN)/tspFinal


$(BIN)/tspFinal: $(OBJ)/programa.o $(OBJ)/problema.o $(OBJ)/punto.o $(OBJ)/solucion.o
	g++ -o $(BIN)/tspFinal $(OBJ)/programa.o $(OBJ)/problema.o $(OBJ)/punto.o $(OBJ)/solucion.o -std=c++0x

$(OBJ)/programa.o: $(SRC)/programa.cpp
	g++ -c $(SRC)/programa.cpp -o $(OBJ)/programa.o -Iinclude/ -std=c++0x


$(OBJ)/problema.o: $(SRC)/problema.cpp $(INC)/problema.h
	g++ -c $(SRC)/problema.cpp -o $(OBJ)/problema.o -Iinclude/ -std=c++0x

$(OBJ)/punto.o: $(SRC)/punto.cpp $(INC)/punto.h
	g++ -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -Iinclude/ -std=c++0x

$(OBJ)/solucion.o: $(SRC)/solucion.cpp $(INC)/solucion.h
	g++ -c $(SRC)/solucion.cpp -o $(OBJ)/solucion.o -Iinclude/ -std=c++0x

clean:
	echo "Limpiando..." //Tambien puede emplearse @echo
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/tspFinal.exe