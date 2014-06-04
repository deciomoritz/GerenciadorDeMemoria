/*
 * Processo.cpp
 *
 *  Created on: Jun 3, 2014
 *      Author: decio
 */

#include "include/Processo.h"

Processo::Processo() {
	tempoDeChegada = 0;
	duracao = 0;
	tamanho = 0;
}

Processo::~Processo() {
}

Processo::Processo(string n, unsigned tc, unsigned dur, unsigned tam) {
	nome = n;
	tempoDeChegada = tc;
	duracao = dur;
	tamanho = tam;
}
