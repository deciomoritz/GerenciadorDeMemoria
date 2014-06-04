/*
 * Processo.h
 *
 *  Created on: Jun 3, 2014
 *      Author: decio
 */

#ifndef PROCESSO_H_
#define PROCESSO_H_

#include <string>
using std::string;

class Processo {

	string nome;
	unsigned tempoDeChegada;
	unsigned duracao;
	unsigned tamanho; //Kb

public:
	Processo();
	Processo(string n, unsigned tc, unsigned dur, unsigned tam);
	virtual ~Processo();

	unsigned getDuracao() const {
		return duracao;
	}

	unsigned getTamanho() const {
		return tamanho;
	}

	unsigned getTempoDeChegada() const {
		return tempoDeChegada;
	}

	const string& getNome() const {
		return nome;
	}
};

#endif /* PROCESSO_H_ */
