#include <iostream>
using namespace std;

#include "lista.h"

int main(void) {
	Lista *lista = new Lista();
	if(!lista) {
		cout << "Sem memoria disponivel!\n" ;
		return 0;
	}
	for(int i = 0; i < 5; i++)
		lista[0].Insere(150*i);
	lista->Exibe();

	lista[0].Remove(1);

	lista->Exibe();

    delete lista;
	return 0;
}