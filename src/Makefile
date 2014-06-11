CC = g++
CFLAGS = -w -g -fpermissive
LDFLAGS =

all: Main.o Relogio.o Processo.o Parser.o GerenciadorDeMemoria.o Bloco.o Escalonador.o
	${CC} -o exec Main.o Processo.o Parser.o GerenciadorDeMemoria.o Bloco.o Escalonador.o Relogio.o

Relogio.o : include/Relogio.h Relogio.cpp
	${CC} ${CFLAGS} -c include/Relogio.h Relogio.cpp

Processo.o : include/Processo.h Processo.cpp
	${CC} ${CFLAGS} -c Processo.cpp include/Processo.h


Parser.o : include/Parser.h Parser.cpp
	${CC} ${CFLAGS} -c Parser.cpp include/Parser.h

GerenciadorDeMemoria.o: include/GerenciadorDeMemoria.h  GerenciadorDeMemoria.cpp 
	${CC} ${CFLAGS} -c include/GerenciadorDeMemoria.h GerenciadorDeMemoria.cpp
	
Bloco.o: include/Bloco.h  Bloco.cpp 
	${CC} ${CFLAGS} -c include/Bloco.h Bloco.cpp
	
Escalonador.o: include/Escalonador.h  Escalonador.cpp 
	${CC} ${CFLAGS} -c include/Escalonador.h Escalonador.cpp

Main.o: Main.cpp
	${CC} ${CFLAGS} -c Main.cpp

n : Main.cpp Relogio.h Processo.h Parser.h GerenciadorDeMemoria.h  Bloco.o Escalonador.o
	${CC} ${CFLAGS} Main.cpp  include/Relogio.h include/Processo.h include/Parser.h include/GerenciadorDeMemoria.h GerenciadorDeMemoria.o Bloco.o Escalonador.o ${LDFLAGS} -o exec

clean:
	rm -rf *.cpp~ *.o Makefile~ *.h~ *.h.gch
	cd include;rm -rf *.cpp~ *.o Makefile~ *.h~ *.h.gch
