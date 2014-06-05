#include "include/GerenciadorDeMemoria.h"
#include "include/Parser.h"

#include <list>
using std::list;

int main() {

	Parser p;
	p.parse();

	list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	for (list<int>::const_iterator  ci= l.begin(); ci != l.end(); ++ci) {
		cout << *ci << endl;
	}

}
