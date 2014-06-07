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

	if (iDisponivel == iNecessario){
		candidato->associar(p);
		candidato->alocar();
	}else {
		memoria.erase(candidato);
		dividir(iDisponivel, iNecessario, p);
	}
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

void GerenciadorDeMemoria::desalocar(Processo p) {

	blocos::iterator candidato;

	blocos::iterator processo;
	for (blocos::iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
		if(bloco->getTamanho() == p.getTamanho() && bloco->isLivre())
			candidato = bloco;
		if(bloco->getTamanho() == atoi(p.getNome().c_str()))
			processo = bloco;
	}

	if(!candidato->getTamanho()){
		memoria.erase(candidato);

	}

}

void GerenciadorDeMemoria::printMemoria() {
	for (blocos::iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
		cout << "Tamanho: " << bloco->getTamanho();
		cout << " Tamanho log2: " << log2(bloco->getTamanho());
		if(!bloco->isLivre())
			cout << " Processo: " << bloco->getProcesso()->getNome();
		cout << " livre: " << bloco->isLivre() << endl;
	}
}
