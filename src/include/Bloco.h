/*
 * Bloco.h
 *
 *  Created on: Jun 4, 2014
 *      Author: decio
 */

#ifndef BLOCO_H_
#define BLOCO_H_

#include "Processo.h"

class Bloco {

	unsigned tamanho;
	bool livre;

public:
	Bloco(unsigned tam);
	Bloco();
	virtual ~Bloco();

	void liberar();
	void alocar();

	bool isLivre() const {
		return livre;
	}

	unsigned getTamanho() const {
		return tamanho;
	}

	bool operator >=(const Bloco &b) const {
		return tamanho >= b.tamanho;
	}

	bool operator >=(const Processo &p) const {
		return tamanho >= p.getTamanho();
	}
};

#endif /* BLOCO_H_ */
