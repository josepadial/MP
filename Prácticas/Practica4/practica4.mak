BIN = bin
INC = include
LIB = lib
OBJ = obj
SRC = src

all : $(BIN)/1_RedimensionarArray $(BIN)/2_CalificacionesOrdenado $(BIN)/4_DemoMatriz2D_1  $(BIN)/5_DemoMatriz2D_2

$(BIN)/1_RedimensionarArray: $(OBJ)/1_RedimensionarArray.o
	g++ -o $(BIN)/1_RedimensionarArray $(OBJ)/1_RedimensionarArray.o

$(OBJ)/1_RedimensionarArray.o: $(SRC)/1_RedimensionarArray.cpp
	g++ -c $(SRC)/1_RedimensionarArray.cpp -o $(OBJ)/1_RedimensionarArray.o -Iinclude/


$(BIN)/2_CalificacionesOrdenado: $(OBJ)/2_CalificacionesOrdenado.o
	g++ -o $(BIN)/2_CalificacionesOrdenado $(OBJ)/2_CalificacionesOrdenado.o

$(OBJ)/2_CalificacionesOrdenado.o: $(SRC)/2_CalificacionesOrdenado.cpp
	g++ -c $(SRC)/2_CalificacionesOrdenado.cpp -o $(OBJ)/2_CalificacionesOrdenado.o -Iinclude/


$(BIN)/4_DemoMatriz2D_1: $(OBJ)/4_DemoMatriz2D_1.o $(OBJ)/Matriz2D_1.o
	g++ -o $(BIN)/4_DemoMatriz2D_1 $(OBJ)/4_DemoMatriz2D_1.o $(OBJ)/Matriz2D_1.o

$(OBJ)/4_DemoMatriz2D_1.o: $(SRC)/4_DemoMatriz2D_1.cpp
	g++ -c $(SRC)/4_DemoMatriz2D_1.cpp -o $(OBJ)/4_DemoMatriz2D_1.o -Iinclude/


$(BIN)/5_DemoMatriz2D_2: $(OBJ)/5_DemoMatriz2D_2.o $(OBJ)/Matriz2D_2.o
	g++ -o $(BIN)/5_DemoMatriz2D_2 $(OBJ)/5_DemoMatriz2D_2.o $(OBJ)/Matriz2D_2.o

$(OBJ)/5_DemoMatriz2D_2.o: $(SRC)/5_DemoMatriz2D_2.cpp
	g++ -c $(SRC)/5_DemoMatriz2D_2.cpp -o $(OBJ)/5_DemoMatriz2D_2.o -Iinclude/


$(OBJ)/Matriz2D_1.o: $(SRC)/Matriz2D_1.cpp $(INC)/Matriz2D_1.h
	g++ -c $(SRC)/Matriz2D_1.cpp -o $(OBJ)/Matriz2D_1.o -Iinclude/

$(OBJ)/Matriz2D_2.o: $(SRC)/Matriz2D_2.cpp $(INC)/Matriz2D_2.h
	g++ -c $(SRC)/Matriz2D_2.cpp -o $(OBJ)/Matriz2D_2.o -Iinclude/

clean:
	echo "Limpiando..." //Tambien puede emplearse @echo
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/1_RedimensionarArray.exe $(BIN)/2_CalificacionesOrdenado.exe $(BIN)/4_DemoMatriz2D_1.exe  $(BIN)/5_DemoMatriz2D_2.exe