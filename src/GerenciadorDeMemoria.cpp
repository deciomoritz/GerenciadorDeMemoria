/*
 * GerenciadorDeMemoria.cpp
 *
 *  Created on: Jun 4, 2014
 *      Author: decio
 */

#include "include/GerenciadorDeMemoria.h"

GerenciadorDeMemoria::GerenciadorDeMemoria() {
	tamanhoDaMemoria = pow(2, 11);
	memoria.push_back(Bloco(tamanhoDaMemoria));
}

GerenciadorDeMemoria::~GerenciadorDeMemoria() {
}

void GerenciadorDeMemoria::carregar(Processo p) {

	Bloco menorBlocoSuficiente(tamanhoDaMemoria);
	blocos::iterator candidato;

	for (blocos::iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
		if (menorBlocoSuficiente >= *bloco && *bloco >= p && bloco->isLivre()) {
			menorBlocoSuficiente = *bloco;
			candidato = bloco;
		}
	}

	unsigned iNecessario = log2(p.getTamanho()) + 1;
	unsigned iDisponivel = log2(menorBlocoSuficiente.getTamanho());

	if (iDisponivel == iNecessario)
		candidato->alocar();
	else {
		memoria.erase(candidato);
		dividir(iDisponivel, iNecessario);
	}
}

void GerenciadorDeMemoria::dividir(unsigned tamanhoDisponivel, unsigned tamanhoDesejado) {
	if (tamanhoDisponivel != tamanhoDesejado) {
		tamanhoDisponivel--;
		Bloco novo(pow(2, tamanhoDisponivel));
		memoria.push_back(novo);
		dividir(tamanhoDisponivel, tamanhoDesejado);
	} else {
		memoria.push_back(memoria.back());
		memoria.back().alocar();
		return;
	}
}

void GerenciadorDeMemoria::printMemoria() {
	for (blocos::const_iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
		cout << "Tamanho: " << bloco->getTamanho();
		cout << " Tamanho log2: " << log2(bloco->getTamanho());
		cout << " livre: " << bloco->isLivre() << endl;
	}
}
