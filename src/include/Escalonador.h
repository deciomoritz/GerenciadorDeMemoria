/*
 * Escalonador.h
 *
 *  Created on: Jun 8, 2014
 *      Author: decio
 */

#ifndef ESCALONADOR_H_
#define ESCALONADOR_H_

#include "GerenciadorDeMemoria.h"
#include "Parser.h"
#include "Relogio.h"

#include <fstream>
#include <iostream>

class Escalonador {

	Parser * p;
	GerenciadorDeMemoria g;
	Relogio r;

public:

	Escalonador();
	Escalonador(Parser * par);
	virtual ~Escalonador();

	void simular();
};

#endif /* ESCALONADOR_H_ */
