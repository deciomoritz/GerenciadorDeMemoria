/*
 * GerenciadorDeMemoria.cpp
 *
 *  Created on: Jun 4, 2014
 *      Author: decio
 */

#include "include/GerenciadorDeMemoria.h"

GerenciadorDeMemoria::GerenciadorDeMemoria(unsigned tamMemoria) {
	tamanhoDaMemoria = tamMemoria;
	memoria.push_back(Bloco(tamanhoDaMemoria));
}

GerenciadorDeMemoria::~GerenciadorDeMemoria() {
}

void GerenciadorDeMemoria::alocar(Processo * p) {
	Bloco menorBlocoSuficiente(tamanhoDaMemoria);
	blocos::iterator candidato;

	for (blocos::iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
		if (menorBlocoSuficiente >= *bloco && *bloco >= *p && bloco->isLivre()) {
			menorBlocoSuficiente = *bloco;
			candidato = bloco;
		}
	}

	unsigned iNecessario = log2(p->getTamanho()) + 1;
	unsigned iDisponivel = log2(menorBlocoSuficiente.getTamanho());

	if (iDisponivel == iNecessario) {
		candidato->associar(p);
		candidato->alocar();
	} else {
		memoria.erase(candidato);
		dividir(iDisponivel, iNecessario, p);
	}
	memoria.sort();
	memoria.reverse();
}

void GerenciadorDeMemoria::dividir(unsigned tamanhoDisponivel, unsigned tamanhoDesejado, Processo * p) {
	if (tamanhoDisponivel != tamanhoDesejado) {
		tamanhoDisponivel--;
		Bloco novo(pow(2, tamanhoDisponivel));
		memoria.push_back(novo);
		dividir(tamanhoDisponivel, tamanhoDesejado, p);
	} else {
		memoria.back().associar(p);
		memoria.push_back(memoria.back());
		memoria.back().alocar();
		return;
	}
}

void GerenciadorDeMemoria::desalocar(Processo * p) {

	blocos::iterator candidato;

	blocos::iterator processo;
	for (blocos::iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
		if (!bloco->isLivre())
			if (bloco->getProcesso()->getNome() == p->getNome())
				processo = bloco;
	}
	processo->liberar();
	reagrupar();
	memoria.sort();
	memoria.reverse();
}

void GerenciadorDeMemoria::printMemoria() {

	unsigned fragmentacaoInternaTotal = 0;
	for (blocos::iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
		cout << "Tamanho da partição: " << bloco->getTamanho() << " kb";
		if (!bloco->isLivre()){
			cout << " Processo: " << bloco->getProcesso()->getNome();
			cout << " Tamanho do processo: " << bloco->getProcesso()->getTamanho() << " kb";
			cout << " Fragmentação interna: " << bloco->getTamanho() - bloco->getProcesso()->getTamanho() << " kb";
			fragmentacaoInternaTotal += bloco->getTamanho() - bloco->getProcesso()->getTamanho();
		}
		cout << (bloco->isLivre() ? " Livre" : "") << endl;
	}
	cout << "\nFragmentação interna total: " << fragmentacaoInternaTotal << " kb\n";
}

void GerenciadorDeMemoria::reagrupar() {
	blocos::iterator primeiroLivre;
	for (blocos::iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
		if (bloco->isLivre())
			primeiroLivre = bloco;
		else
			continue;
		unsigned tamanhoBlocoLiberado = primeiroLivre->getTamanho() * 2;
		for (blocos::iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
			if (bloco->isLivre() && bloco->getTamanho() == primeiroLivre->getTamanho() && primeiroLivre != bloco) {
				memoria.erase(primeiroLivre);
				memoria.erase(bloco);
				memoria.push_back(Bloco(tamanhoBlocoLiberado));
				reagrupar();
				return;
			}
		}
	}
}

GerenciadorDeMemoria::GerenciadorDeMemoria() {
	tamanhoDaMemoria = 0;
}
