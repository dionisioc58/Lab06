/**
 * @file	turma.cpp
 * @brief	Implementação da classe Turma
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#include "tarefa3/turma.h"

/**
* @details O valor de nome é inicializados com vazio
*		   e a quantidade com zero
*/
Turma::Turma() {
    nome = "";
    qtde = 0;
}
/**
* @details Destrutor padrão
*/
Turma::~Turma() {
    if(qtde > 0)
        delete[] alunos;
}

/**
* @return Nome da Turma
*/
string Turma::getNome() {
    return nome;
}

/**
* @details O método modifica o nome da Turma
* @param   n Nome
*/
void Turma::setNome(string n) {
    nome = n;
}

/**
* @return Quantidade de alunos
*/
int Turma::getQtde() {
    return qtde;
}

/**
* @return Os alunos da Turma
*/
Aluno *Turma::getAlunos() {
    return alunos;
}

/**
* @details O método modifica todos os alunos da Turma
* @param   *f Vetor de alunos à associar com a Turma
* @param   n Nome
*/
void Turma::setAlunos(Aluno *f, int n) {
    alunos = new Aluno[n];
    for(int i = 0; i < n; i++) {
        alunos[i].setNome(f[i].getNome());
        alunos[i].setMatricula(f[i].getMatricula());
        alunos[i].setFaltas(f[i].getFaltas());
        alunos[i].setNota(f[i].getNota());
    }
    qtde = n;
}

/**
* @details O método modifica adiciona um aluno
* @param   *f Ponteiro com o aluno à incluir
* @return  True se adicionou
*/
bool Turma::addAluno(Aluno *f) {
    if(pertenceTurma(f->getNome())) 
        return false;

    //Cria um vetor maior
    Aluno *arr = new Aluno[qtde + 1];

    //Se já tem alunos, copia a antiga lista para uma nova maior
    for(int i = 0; i < qtde; i++)
        arr[i] = alunos[i];

    if(qtde > 0)
        delete[] alunos;
    
    alunos = arr;     //Vetor antigo recebe a nova lista
    alunos[qtde++] = f[0];  //Guarda o elemento informado e incrementa a quantidade de alunos
    
    return true;
}

/**
* @details O método remove um aluno
* @param   f Número zero-based do aluno na lista de alunos
* @return  True se conseguiu remover
*/
bool Turma::delAluno(int f) {
    if((f < 0) || (f >= qtde))
        return false;

    //Cria um vetor menor
    Aluno *arr = new Aluno[qtde - 1];

    //Se já tem alunos, copia a antiga lista para uma nova menor
    int j = 0;
    for(int i = 0; i < qtde; i++) {
        if(i != f)    //Se não é o aluno à remover, copie
            arr[j++] = alunos[i];
    }
    delete[] alunos;

    alunos = arr;     //Vetor antigo recebe a nova lista
    qtde--;
    
    return true;
}

/**
* @details O método verifica se um nome pertence à lista de alunos
* @param   n Nome do aluno à procurar
* @return  True se pertence ao quadro de alunos
*/
bool Turma::pertenceTurma(string n) {
    for(int i = 0; i < qtde; i++)
        if(alunos[i].getNome() == n)
            return true;
    return false;
}

/**
* @return String com os dados para exportação CSV
*/
string Turma::exportar() {
    return "turma;" + nome;
}

/** 
* @details O operador é sobrecarregado para representar a Turma e seus alunos
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Turma a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Turma &e) {
	os << "Nome: " << e.nome << "\t | Alunos: " << e.qtde;
	return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Turma a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Turma &e) {
	is >> e.nome;
	return is;
}