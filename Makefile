# Arquivo Makefile

all: velha clean
	@echo "Compilação Concluída!"

velha: main.o
	g++ -g -Wall main.o -o velha

main.o: main.cpp
	g++ -c -g -Wall main.cpp -o main.o

clean:
	rm *.o

