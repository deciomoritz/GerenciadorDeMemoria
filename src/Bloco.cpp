/*
 * Bloco.cpp
 *
 *  Created on: Jun 4, 2014
 *      Author: decio
 */

#include "include/Bloco.h"

Bloco::Bloco() {
	tamanho = 0;
	livre = true;
}

Bloco::Bloco(unsigned tam) {
	tamanho = tam;
	livre = true;
	processo = 0;
}

Bloco::Bloco(unsigned tam, Processo * p) {
	tamanho = tam;
	livre = true;
	processo = p;
}

Bloco::~Bloco() {
}

void Bloco::liberar() {
	livre = true;
}

void Bloco::alocar() {
	livre = false;
}

void Bloco::associar(Processo * p) {
	processo = p;
}
