#include "include/Relogio.h"

Relogio::Relogio() {
	tempoAtual = 0;
}

void Relogio::iniciar() {
	tempoAtual = 0;
}

long Relogio::getTempoAtual() {
	return tempoAtual;
}

void Relogio::tictac() {
	tempoAtual++;
}

void Relogio::percorrerTempoEm(long tempo) {
	tempoAtual += tempo;
}

