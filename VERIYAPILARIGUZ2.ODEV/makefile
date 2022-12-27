all: build run

build:
	g++ -I ./include/ -o ./lib/Hucre.o -c ./src/Hucre.cpp
	g++ -I ./include/ -o ./lib/Queue.o -c ./src/Queue.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/Doku.o -c ./src/Doku.cpp
	g++ -I ./include/ -o ./lib/BSTNode.o -c ./src/BSTNode.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/Organ.o -c ./src/Organ.cpp
	g++ -I ./include/ -o ./lib/Sistem.o -c ./src/Sistem.cpp
	g++ -I ./include/ -o ./lib/Organizma.o -c ./src/Organizma.cpp
	g++ -I ./include/ -o ./lib/Kontrol.o -c ./src/Kontrol.cpp
	g++ -I ./include/ -o ./lib/AddFromFile.o -c ./src/AddFromFile.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Hucre.o ./lib/Queue.o ./lib/Radix.o ./lib/Doku.o ./lib/BSTNode.o ./lib/BST.o ./lib/Organ.o ./lib/Sistem.o ./lib/Organizma.o ./lib/Kontrol.o ./lib/AddFromFile.o ./src/test.cpp
	

run: 
	./bin/test