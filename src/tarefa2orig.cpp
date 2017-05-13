#include <iostream>
using namespace std;

struct Node{
	int dado;
	struct node *ant;
	struct node *prox;
}; 
typedef struct Node node;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void inserePos(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);


int main(void) {
	node *LISTA = new Node();
	if(!LISTA) {
		cout << "Sem memoria disponivel!\n" ;
		return 0;
	}
	inicia(LISTA);
	//ALTERANDO DURANTE A AULA PARA TESTAR
	node **paulo = &LISTA->prox;
	node *tmp = new node();
	tmp->dado = 15;
	tmp->prox = *paulo;
	*paulo = tmp;
	//FIM DA ALTERAÇÃO DA AULA

	int opt;
	
	do {
		opt = menu();
		opcao(LISTA,opt);
	} while(opt);

    delete[] LISTA;
	return 0;
}

void inicia(node *LISTA) {
	LISTA->prox = NULL;
}

int menu(void) {
	int opt;
	
	cout << "Escolha a opcao\n";
	cout << "0. Sair\n";
	cout << "1. Exibir lista\n";
	cout << "2. Adicionar node no inicio\n";
	cout << "3. Adicionar node no final\n";
	cout << "4. Adicionar node em uma posição\n";
	cout << "5. Zerar lista\n";
	cout << "Opcao: ";
    cin >> opt;
	
	return opt;
}

void opcao(node *LISTA, int op) {
	switch(op) {
		case 0:
			libera(LISTA);
			break;
			
		case 1:
			exibe(LISTA);
			break;
		
		case 2:
			insereInicio(LISTA);
			break;
		
		case 3:
			insereFim(LISTA);
			break;		
			
		case 4:
			inserePos(LISTA);
			break;
		case 5:
			inicia(LISTA);
			break;
		
		default:
			cout << "Comando invalido\n\n";
	}
}

int vazia(node *LISTA) {
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

void inserePos(node *LISTA) {
	//NÃO ESTÁ TERMINADA
	node *novo = new Node();
	if(!novo){
		cout << "Sem memoria disponivel!\n";
		//exit(1);
	}
	int pos;
	cout << "Em qual posição: ";
	cin >> pos;
	cout << "Novo elemento: ";
    cin >> novo->dado;
	//BUSCAR A POSIÇÃO PARA INSERIR
		
	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
}

void insereFim(node *LISTA) {
	node *novo = new Node();
	if(!novo){
		cout << "Sem memoria disponivel!\n";
		//exit(1);
	}
	cout << "Novo elemento: ";
    cin >> novo->dado;
	novo->prox = NULL;
	
	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
}

void insereInicio(node *LISTA) {
	node *novo = new Node();
	if(!novo){
		cout << "Sem memoria disponivel!\n";
		//exit(1);
	}
	cout << "Novo elemento: ";
    cin >> novo->dado;
	
	node *oldHead = LISTA->prox;
	
	LISTA->prox = novo;
	novo->prox = oldHead;
}

void exibe(node *LISTA) {
	if(vazia(LISTA)){
		cout << "Lista vazia!\n\n";
		//exit(1);
	}
	
	node *tmp;
	tmp = LISTA->prox;
	
	while( tmp != NULL){
		cout << tmp->dado << "  ";
		tmp = tmp->prox;
	}
	cout << ("\n\n");
}

void libera(node *LISTA) {
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
            delete[] atual;
			atual = proxNode;
		}
	}
}