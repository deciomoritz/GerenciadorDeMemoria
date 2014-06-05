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

typedef list<Bloco> blocos;
class GerenciadorDeMemoria {

	unsigned tamanhoDaMemoria;
	list<Bloco> memoria;
	list<Processo> criados;

public:
	void carregar(Processo p);

	GerenciadorDeMemoria();
	virtual ~GerenciadorDeMemoria();

	string toString();
};

#endif /* GERENCIADORDEMEMORIA_H_ */
