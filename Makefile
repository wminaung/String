CXX = g++
CFLAGS = -g -std=c++11 -Wall
OBJ = build/main.o build/String.o build/Console.o
OUT = build/main.exe

all:  $(OUT)

$(OUT): $(OBJ) 
	$(CXX) $(CFLAGS) $(OBJ) -o $(OUT)

build:
	mkdir -p build

build/main.o: src/main.cpp src/String.hpp | build
	$(CXX) $(CFLAGS) -c src/main.cpp -o build/main.o

build/String.o: src/String.cpp src/String.hpp | build
	$(CXX) $(CFLAGS) -c src/String.cpp -o build/String.o

build/Console.o: src/Console.cpp | build
	$(CXX) $(CFLAGS) -c src/Console.cpp -o build/Console.o

run: $(OUT)
	./$(OUT)

clean:
	rm -f build/*.o build/*.exe

.PHONY: all run clean
