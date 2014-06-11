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

public:
	bool alocar(Processo * p);
	void desalocar(Processo * p);
	void reagrupar();

	GerenciadorDeMemoria();
	GerenciadorDeMemoria(unsigned tamMemoria);
	virtual ~GerenciadorDeMemoria();

	void printMemoria(); //debug

	friend ostream& operator<<(ostream & out, const GerenciadorDeMemoria g) {
		unsigned fragmentacaoInternaTotal = 0;

		double memoriaOcupada = 0;
		double memoriaEfetivamenteUsada = 0;

		for (blocos::const_iterator bloco = g.memoria.begin(); bloco != g.memoria.end(); bloco++) {
			out << "Tamanho da partição: " << bloco->getTamanho() << " kb";
			if (!bloco->isLivre()) {
				out << " Processo: " << bloco->getProcesso()->getNome();
				memoriaOcupada += bloco->getTamanho();
				out << " Tamanho do processo: " << bloco->getProcesso()->getTamanho() << " kb";
				memoriaEfetivamenteUsada += bloco->getProcesso()->getTamanho();
				out << " Fragmentação interna: " << bloco->getTamanho() - bloco->getProcesso()->getTamanho() << " kb";
				fragmentacaoInternaTotal += bloco->getTamanho() - bloco->getProcesso()->getTamanho();
			}
			out << (bloco->isLivre() ? " Livre" : "") << endl;
		}
		out << "\nFragmentação interna total: " << fragmentacaoInternaTotal << " kb\n";

		if(memoriaOcupada != 0)
			out << "Taxa de uso da memória: " << 100 -(memoriaOcupada - memoriaEfetivamenteUsada)/memoriaOcupada*100 << " %\n";
		else
			out << "Taxa de uso da memória: 0 %\n";
		return out;
	}
};

#endif /* GERENCIADORDEMEMORIA_H_ */
