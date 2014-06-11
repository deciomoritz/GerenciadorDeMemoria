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
	Processo * processo;

public:
	Bloco(unsigned tam, Processo * p);
	Bloco(unsigned tam);
	Bloco();
	virtual ~Bloco();

	void liberar();
	void alocar();
	void associar(Processo * p);

	Processo * getProcesso() {
		return processo;
	}

	bool isLivre() const {
		return livre;
	}

	unsigned getTamanho() const {
		return tamanho;
	}

	bool operator >=(const Bloco &b) const {
		return tamanho >= b.tamanho;
	}

	bool operator <(const Bloco &b) const {
		return tamanho < b.tamanho;
	}

	bool operator >=(const Processo &p) const {
		return tamanho >= p.getTamanho();
	}

	bool operator !=(const Bloco &b) const {
		return tamanho >= b.tamanho && livre != b.livre;
	}

};

#endif /* BLOCO_H_ */
