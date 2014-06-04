/*
 * Parser.cpp
 *
 *  Created on: Jun 3, 2014
 *      Author: decio
 */

#include "include/Parser.h"
#include <stdlib.h>

Parser::Parser() {
}

Parser::~Parser() {
}

int Parser::parse() {
	// create a file-reading object
	ifstream fin;
	fin.open("input.txt"); // open a file
	if (!fin.good())
		return 1; // exit if file not found

	char buf[MAX_CHARS_PER_LINE];
	fin.getline(buf, MAX_CHARS_PER_LINE); //remove comment line
	// read each line of the file
	while (!fin.eof()) {
		// read an entire line into memory
		fin.getline(buf, MAX_CHARS_PER_LINE);

		// parse the line into blank-delimited tokens
		int n = 0; // a for-loop index

		// array to store memory addresses of the tokens in buf
		const char* token[MAX_TOKENS_PER_LINE] = { }; // initialize to 0

		// parse the line
		token[0] = strtok(buf, DELIMITER); // first token
		if (token[0]) // zero if line is blank
		{
			for (n = 1; n < MAX_TOKENS_PER_LINE; n++) {
				token[n] = strtok(0, DELIMITER); // subsequent tokens
				if (!token[n])
					break; // no more tokens
			}
		}

		// process (print) the tokens
		/*for (int i = 0; i < n; i++)
		 cout << "Token[" << i << "] = " << token[i] << endl;
		 cout << endl;*/

		string nome = token[0];
		unsigned tChegada = atoi(token[1]);
		unsigned duracao = atoi(token[2]);
		unsigned tamanho = atoi(token[3]);

		processosCriados.push(Processo(nome, tChegada, duracao, tamanho));

	}
	return 1;
}

queue<Processo>* Parser::processos() {
	return &processosCriados;
}
