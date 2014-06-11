/*
 * Escalonador.cpp
 *
 *  Created on: Jun 8, 2014
 *      Author: decio
 */

#include "include/Escalonador.h"

Escalonador::Escalonador() {
	p = 0;
}

Escalonador::~Escalonador() {
}

Escalonador::Escalonador(Parser* par) {
	p = par;
	g = GerenciadorDeMemoria(p->tamanhoDaMemoria());
}

typedef list<Processo>::iterator iterador;
void Escalonador::simular() {

	std::ofstream outputFile;
	outputFile.open("../output.txt");
	cout << "Saída gerada no arquivo output.txt\n";

	r.iniciar();

	unsigned processosDesalocados = 0;

	bool print = false;
	while (processosDesalocados < p->processos()->size()) {
		print = false;
		for (iterador processo = p->processos()->begin(); processo != p->processos()->end(); processo++) {
			unsigned tempoSaida = processo->getTempoDeChegada() + processo->getDuracao();
			if (processo->getTempoDeChegada() == r.getTempoAtual()) {
				outputFile << "<Alocando processo " << processo->getNome() << ">(" << processo->getTamanho() << "kb)" << endl;
				bool ok = g.alocar(&*processo);
				if (!ok)
					outputFile << "Memória insuficiente!\n";
				print = true;
			} else if (tempoSaida == r.getTempoAtual()) {

				if (processo->isAlocado()) {
					outputFile << "<Desalocando processo " << processo->getNome() << ">" << endl;
					g.desalocar(&*processo);
					print = true;
				}
					processosDesalocados++;
			}
		}

		if (print) {
			outputFile << "################# Instante: " << r.getTempoAtual() << " #######################" << endl;
			//g.printMemoria();
			outputFile << g;
			outputFile << "______________________________________________________\n";
		}
		r.tictac();
	}
	outputFile << "#############################################################\n";
}
