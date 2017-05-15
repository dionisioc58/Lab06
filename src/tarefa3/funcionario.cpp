/**
 * @file	funcionario.cpp
 * @brief	Implementacao dos métodos da classe Funcionario
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#include "funcionario.h"

/**
* @details Os valores de nome e salario sao inicializados com vazio
*			e a data de admissão com a data atual
*/
Funcionario::Funcionario() {
    nome = "";
    salario = 0;
    admissao = std::time(NULL);
}

/**
* @return Nome do funcionário
*/
string Funcionario::getNome() {
    return nome;
}

/**
* @details O método modifica o nome do funcionário
* @param   n Nome
*/
void Funcionario::setNome(string n) {
    nome = n;
}

/**
* @return Salário do funcionário
*/
float Funcionario::getSalario() {
    return salario;
}

/**
* @details O método modifica o salário do funcionário
* @param   s Salário
*/
void Funcionario::setSalario(float s) {
    salario = s;
}

/**
* @return Data de admissão do funcionário
*/
std::time_t Funcionario::getAdmissao() {
    return admissao;
}

/**
* @details O método modifica a data de admissão do funcionário
* @param   a Data de admissão
*/
void Funcionario::setAdmissao(std::time_t a) {
    admissao = a;
}

/**
* @return True se o está em período de experiência
*/
bool Funcionario::experiencia() {
    std::time_t agora = std::time(NULL);
    double difference = std::difftime(agora, admissao) / (60 * 60 * 24);
    if(difference > 90)
        return false;
    return true;
}

/**
* @return String com os dados para exportação CSV
*/
string Funcionario::exportar() {
    stringstream ss;
    ss << "func;" << nome << ";" << salario << ";";
    char mbstr[20];
    if (std::strftime(mbstr, sizeof(mbstr), "%d/%m/%Y", std::localtime(&admissao)))
        ss << mbstr;
    string retorno;
    getline(ss, retorno);
    return retorno;
}

/** 
* @details O operador é sobrecarregado para representar a empresa e seus funcionários
* @param	os Referência para stream de saída
* @param	f Referência para o objeto Funcionario a ser impresso
* @return	Referência para stream de saída
*/
ostream& operator<<(ostream& os, Funcionario &f) {
	os <<  f.nome << "\t| ";
	os << "Sal.: " << f.salario << "\t| ";
    os << "Adm.: ";
    char mbstr[20];
    if (std::strftime(mbstr, sizeof(mbstr), "%d/%m/%Y", std::localtime(&f.admissao)))
        os << mbstr;
    return os;
}

/** 
* @param	is Referência para stream de entrada
* @param	f Referência para o objeto Funcionário a ser criado com base nos 
*			valores fornecidos
* @return	Referência para stream de entrada
*/
istream& operator>>(istream& is, Funcionario &f) {
    string adm;
    getline(is, f.nome, ';');
    if(f.nome == "\n")
        return is;
    getline(is, adm, ';');
    f.salario = stof(adm);
    getline(is, adm);

    int dia, mes, ano;
    dia = stoi(adm.substr(0, 2));
    mes = stoi(adm.substr(3, 2));
    ano = stoi(adm.substr(6, 4));
    std::tm a = {0, 0, 0, dia, mes - 1, ano - 1900};
    f.admissao = std::mktime(&a);
	
    return is;
}