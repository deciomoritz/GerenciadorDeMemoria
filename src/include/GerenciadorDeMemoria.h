/*
 * GerenciadorDeMemoria.h
 *
 *  Created on: Jun 4, 2014
 *      Author: decio
 */

#ifndef GERENCIADORDEMEMORIA_H_
#define GERENCIADORDEMEMORIA_H_

#include "Bloco.h"
#include "Processo.h"
#include <list>
using std::list;

#include <stdlib.h>

#include <ostream>
using std::ostream;

#include <math.h>

#include <iostream>
using std::cout;
using std::endl;

typedef list<Bloco> blocos;
class GerenciadorDeMemoria {

	unsigned tamanhoDaMemoria;
	list<Bloco> memoria;
	list<Processo> criados;

	void dividir(unsigned tamanhoDisponivel, unsigned tamanhoDesejado, Processo * p); //passar log2 dos parametros

	friend ostream & operator<<(ostream & out, const blocos & memoria) {
		for (blocos::const_iterator bloco = memoria.begin(); bloco != memoria.end(); bloco++) {
			out << "Tamanho: " << bloco->getTamanho();
			out << " Tamanho log2: " << log2(bloco->getTamanho()) << endl;
		}
		return out;
	}

public:
	void alocar(Processo * p);
	void desalocar(Processo p);

	GerenciadorDeMemoria();
	virtual ~GerenciadorDeMemoria();

	void printMemoria();
};

#endif /* GERENCIADORDEMEMORIA_H_ */
