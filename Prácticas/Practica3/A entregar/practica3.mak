BIN = bin
INC = include
LIB = lib
OBJ = obj
SRC = src

all : $(BIN)/16_PosMayor $(BIN)/17_OrdenConPunteros $(BIN)/18_Calificaciones_ArrayStruct  $(BIN)/19_Calificaciones_ArrayStruct_Ordenado

$(BIN)/16_PosMayor: $(OBJ)/16_PosMayor.o
	g++ -o $(BIN)/16_PosMayor $(OBJ)/16_PosMayor.o

$(OBJ)/16_PosMayor.o: $(SRC)/16_PosMayor.cpp
	g++ -c $(SRC)/16_PosMayor.cpp -o $(OBJ)/16_PosMayor.o -Iinclude/


$(BIN)/17_OrdenConPunteros: $(OBJ)/17_OrdenConPunteros.o
	g++ -o $(BIN)/17_OrdenConPunteros $(OBJ)/17_OrdenConPunteros.o

$(OBJ)/17_OrdenConPunteros.o: $(SRC)/17_OrdenConPunteros.cpp
	g++ -c $(SRC)/17_OrdenConPunteros.cpp -o $(OBJ)/17_OrdenConPunteros.o -Iinclude/


$(BIN)/18_Calificaciones_ArrayStruct: $(OBJ)/18_Calificaciones_ArrayStruct.o
	g++ -o $(BIN)/18_Calificaciones_ArrayStruct $(OBJ)/18_Calificaciones_ArrayStruct.o

$(OBJ)/18_Calificaciones_ArrayStruct.o: $(SRC)/18_Calificaciones_ArrayStruct.cpp
	g++ -c $(SRC)/18_Calificaciones_ArrayStruct.cpp -o $(OBJ)/18_Calificaciones_ArrayStruct.o -Iinclude/


$(BIN)/19_Calificaciones_ArrayStruct_Ordenado: $(OBJ)/19_Calificaciones_ArrayStruct_Ordenado.o
	g++ -o $(BIN)/19_Calificaciones_ArrayStruct_Ordenado $(OBJ)/19_Calificaciones_ArrayStruct_Ordenado.o

$(OBJ)/19_Calificaciones_ArrayStruct_Ordenado.o: $(SRC)/19_Calificaciones_ArrayStruct_Ordenado.cpp
	g++ -c $(SRC)/19_Calificaciones_ArrayStruct_Ordenado.cpp -o $(OBJ)/19_Calificaciones_ArrayStruct_Ordenado.o -Iinclude/


clean:
	echo "Limpiando..." //Tambien puede emplearse @echo
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/16_PosMayor.exe $(BIN)/17_OrdenConPunteros.exe $(BIN)/18_Calificaciones_ArrayStruct.exe $(BIN)/19_Calificaciones_ArrayStruct_Ordenado.exe