/**
 * @file	empresa.cpp
 * @brief	Implementação da classe Empresa
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#include "empresa.h"

/**
* @details Os valores de nome e cnpj são inicializados com vazio
*			e a quantidade com zero
*/
Empresa::Empresa() {
    nome = "";
    cnpj = "";
    qtde = 0;
}
/**
* @details Destrutor padrão
*/
Empresa::~Empresa() {
    if(qtde > 0)
        delete[] funcionarios;
}

/**
* @return Nome da empresa
*/
string Empresa::getNome() {
    return nome;
}

/**
* @details O método modifica o nome da empresa
* @param   n Nome
*/
void Empresa::setNome(string n) {
    nome = n;
}

/**
* @return CNPJ da empresa
*/
string Empresa::getCnpj() {
    return cnpj;
}

/**
* @details O método modifica o CNPJ da empresa
* @param   c Nome
*/
void Empresa::setCnpj(string c) {
    cnpj = c;
}

/**
* @return Quantidade de funcionários
*/
int Empresa::getQtde() {
    return qtde;
}

/**
* @return Os funcionários da empresa
*/
Funcionario *Empresa::getFuncionarios() {
    return funcionarios;
}

/**
* @details O método modifica todos os funcionários da empresa
* @param   *f Vetor de funcionários à associar com a empresa
* @param   n Nome
*/
void Empresa::setFuncionarios(Funcionario *f, int n) {
    funcionarios = new Funcionario[n];
    for(int i = 0; i < n; i++) {
        funcionarios[i].setNome(f[i].getNome());
        funcionarios[i].setSalario(f[i].getSalario());
        funcionarios[i].setAdmissao(f[i].getAdmissao());
    }
    qtde = n;
}

/**
* @details O método modifica adiciona um funcionário
* @param   *f Ponteiro com o funcionário à incluir
* @return  True se adicionou
*/
bool Empresa::addFuncionario(Funcionario *f) {
    if(pertenceQuadro(f->getNome())) 
        return false;

    //Cria um vetor maior
    Funcionario *arr = new Funcionario[qtde + 1];

    //Se já tem funcionários, copia a antiga lista para um novo maior
    for(int i = 0; i < qtde; i++)
        arr[i] = funcionarios[i];

    if(qtde > 0)
        delete[] funcionarios;
    
    funcionarios = arr;     //Vetor antigo recebe a nova lista
    funcionarios[qtde++] = f[0];  //Guarda o elemento informado e incrementa a quantidade de funcionarios
    
    return true;
}

/**
* @details O método remove um funcionário
* @param   f Número zero-based do funcionário na lista de funcionários
* @return  True se conseguiu remover
*/
bool Empresa::delFuncionario(int f) {
    if((f < 0) || (f >= qtde))
        return false;

    //Cria um vetor menor
    Funcionario *arr = new Funcionario[qtde - 1];

    //Se já tem funcionários, copia a antiga lista para uma nova menor
    int j = 0;
    for(int i = 0; i < qtde; i++) {
        if(i != f)    //Se não é o funcionário à remover, copie
            arr[j++] = funcionarios[i];
    }
    delete[] funcionarios;

    funcionarios = arr;     //Vetor antigo recebe a nova lista
    qtde--;
    
    return true;
}

/**
* @details O método verifica se um nome pertence à lista de funcionários
* @param   n Nome do funcionário à procurar
* @return  True se pertence ao quadro de funcionários
*/
bool Empresa::pertenceQuadro(string n) {
    for(int i = 0; i < qtde; i++)
        if(funcionarios[i].getNome() == n)
            return true;
    return false;
}

/**
* @details O método aplica um percentual de aumento aos funcionários
* @param   percentual Valor em % que será aumentado o salário
*/
void Empresa::aumento(float percentual) {
    for(int i = 0; i < qtde; i++)
        funcionarios[i].setSalario(funcionarios[i].getSalario() * (1 + (percentual/100)));
}

/**
* @return String com os dados para exportação CSV
*/
string Empresa::exportar() {
    return "empr;" + nome + ";" + cnpj;
}

/** 
* @details O operador é sobrecarregado para representar a empresa e seus funcionários
* @param	os Referência para stream de saída
* @param	e Referência para o objeto Empresa a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Empresa &e) {
	os << "Nome: " << e.nome << " - ";
	os << "CNPJ: " << e.cnpj;
	return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	e Referência para o objeto Empresa a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Empresa &e) {
	is >> e.nome >> e.cnpj;
	return is;
}