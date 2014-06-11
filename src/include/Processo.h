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
	bool alocado;

public:
	Processo();
	Processo(string n, unsigned tc, unsigned dur, unsigned tam);
	virtual ~Processo();

	bool isAlocado(){
		return alocado;
	}

	void alocar(){
		alocado = true;
	}

	void desalocar(){
		alocado = false;
	}

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

	bool operator ==(const Processo &p) const {
		return nome == p.nome;
	}

	bool operator <(const Processo &p) const {
		return tempoDeChegada < p.tempoDeChegada;
	}
};

#endif /* PROCESSO_H_ */
