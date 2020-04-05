BIN = bin
INC = include
LIB = lib
OBJ = obj
SRC = src

all : $(BIN)/central $(BIN)/main2

$(BIN)/central : $(OBJ)/central.o $(LIB)/libformas.a
	g++ -o $(BIN)/central $(OBJ)/central.o -Llib/ -lformas

$(LIB)/libformas.a: $(OBJ)/punto.o $(OBJ)/circulo.o
	ar rsv $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

$(OBJ)/central.o: $(SRC)/central.cpp
	g++ -c $(SRC)/central.cpp -o $(OBJ)/central.o -Iinclude/

$(OBJ)/punto.o: $(SRC)/punto.cpp $(INC)/punto.h
	g++ -c -std=c++0x $(SRC)/punto.cpp -o $(OBJ)/punto.o -Iinclude/

$(OBJ)/circulo.o: $(SRC)/circulo.cpp $(INC)/circulo.h $(INC)/punto.h
	g++ -c -std=c++0x $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -Iinclude/

clean:
	echo "Limpiando..." //Tambi´en puede emplearse @echo
	rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	rm $(BIN)/central.exe $(BIN)/main2.exe