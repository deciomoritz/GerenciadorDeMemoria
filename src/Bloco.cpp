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
}

Bloco::~Bloco() {
}

void Bloco::liberar() {
	livre = true;
}

void Bloco::alocar() {
	livre = false;
}
