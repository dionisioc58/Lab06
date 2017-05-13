#include "lista.h"

Lista::Lista() {
    ant = NULL;
    prox = NULL;
}

Lista::~Lista() {
    if(prox)
        delete prox;    //Deleta todos os próximos recursivamente
}

void Lista::Insere(int el) {
	Lista *novo = new Lista();
	if(!novo)
		cout << "Sem memoria disponivel!\n";

	novo->dado = el;
	//BUSCAR A POSIÇÃO PARA INSERIR
		
	if(!prox)
		prox = novo;
	else {
		Lista *tmp = prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
}

void Lista::Remove(int pos) {
    Lista *atual = prox;
    Lista *remove = prox->prox;
    for(int i = 1; i < pos; i++) {
        if(remove) {
            atual = remove;
            remove = remove->prox;
        }
    }
    if(remove) {
        atual->prox = remove->prox; //Relinka o anterior ao próximo
        remove->prox = NULL;        //Para não remover todos os próximos através do destrutor padrão
        delete remove;
    }
}

void Lista::Exibe() {
	if(!prox){
		cout << "Lista vazia!\n\n";
	}
	
	Lista *tmp;
	tmp = prox;
	
	while( tmp != NULL){
		cout << tmp->dado << "  ";
		tmp = tmp->prox;
	}
	cout << ("\n\n");
}