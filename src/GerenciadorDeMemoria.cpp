/*
 * GerenciadorDeMemoria.cpp
 *
 *  Created on: Jun 4, 2014
 *      Author: decio
 */

#include "include/GerenciadorDeMemoria.h"

GerenciadorDeMemoria::GerenciadorDeMemoria() {
	 tamanhoDaMemoria = 2e11;
	 memoria.push_back(Bloco(tamanhoDaMemoria));
}

void GerenciadorDeMemoria::carregar(Processo p) {

	Bloco menorBlocoSuficiente(tamanhoDaMemoria);

	blocos::iterator candidato;

	for (blocos::iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
		if(menorBlocoSuficiente < *bloco && menorBlocoSuficiente > p){
			menorBlocoSuficiente = *bloco;
			candidato = bloco;
		}
	}
	//TODO criar blocos do tamanho correto
	memoria.erase(candidato);
	if(menorBlocoSuficiente.getTamanho()/2 > p.getTamanho()){

	}
}

GerenciadorDeMemoria::~GerenciadorDeMemoria() {
}

string GerenciadorDeMemoria::toString() {
}
