/*
 * Escalonador.h
 *
 *  Created on: Jun 3, 2014
 *      Author: decio
 */

#ifndef ESCALONADOR_H_
#define ESCALONADOR_H_

#include <queue>
using std::queue;

#include "Processo.h"

class Escalonador {

	queue<Processo> criados;
	queue<Processo> prontos;

public:
	Escalonador();
	virtual ~Escalonador();
};

#endif /* ESCALONADOR_H_ */
