#include "include/GerenciadorDeMemoria.h"
#include "include/Parser.h"
#include "include/Escalonador.h"

#include <list>
using std::list;

int main() {

	Parser p;
	p.parse();

	Escalonador e(&p);

	e.simular();
}
