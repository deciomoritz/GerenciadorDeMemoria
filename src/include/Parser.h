/*
 * Parser.h
 *
 *  Created on: Jun 3, 2014
 *      Author: decio
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <cstring>

#include "Processo.h"

#include <list>
using std::list;

#include <stdlib.h>

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";

class Parser {

	list<Processo> processosLidos;

public:
	Parser();
	virtual ~Parser();

	int parse();

	list<Processo> * processos();
};

#endif /* PARSER_H_ */
