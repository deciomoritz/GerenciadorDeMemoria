#include "include/Parser.h"

int main() {

	Parser p;
	p.parse();

	while(!p.processos()->empty()){
		cout << p.processos()->front().getNome() << endl;
		p.processos()->pop();
	}

}
