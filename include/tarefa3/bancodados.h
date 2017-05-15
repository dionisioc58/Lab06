/**
* @file 	bancodados.h
* @brief	Arquivo de cabeçalho com a definição de funções para o controle dos dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    29/04/2017
* @date     07/05/2017
*/

#ifndef BANCODADOS_H
    #define BANCODADOS_H

    #include <iostream>
    using std::cin;
    using std::cout;
    using std::endl;

    #include <fstream>
    using std::ifstream;
    using std::ofstream;

    #include <string>
    using std::string;

    #include "empresa.h"
    #include "funcionario.h"
    #include "funcoes.h"

    /**
    * @brief        Função que coleta os dados para cadastro de uma empresa
    * @return       Empresa coletada
    */
    Empresa *inputEmpresa();

    /**
    * @brief        Função que coleta os dados para cadastro de um funcionário
    * @return       Funcionário coletado
    */
    Funcionario *inputFuncionario();

    /**
    * @brief        Função que verifica se uma empresa já existe no cadastro
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[in]    n Número de empresas no cadastro
    * @param[in]    *nova Empresa à ser verificada
    * @return       Retorna true caso já exista
    */
    bool existeEmpresa(Empresa *e, int n, Empresa *nova);

    /**
    * @brief        Função que realiza o cadastro uma empresa
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[inout] n Número de empresas no cadastro
    * @return       Retorna o novo vetor de empresas após o cadastro
    */
    Empresa *cadEmpresa(Empresa *e, int &n);

    /**
    * @brief        Função que remove uma empresa do cadastro
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[inout] n Número de empresas no cadastro
    * @return       Retorna o novo vetor de empresas após a exclusão
    */
    Empresa *delEmpresa(Empresa *e, int &n);

    /**
    * @brief        Função que adiciona um funcionário à uma empresa (apresenta escolha)
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[in]    n Número de empresas no cadastro
    * @return       Retorna o novo vetor de empresas após o cadastro
    */
    Empresa *addFunc(Empresa *e, int n);

    /**
    * @brief        Função que adiciona funcionários à uma empresa (apresenta escolha),
    *               carregando-os apartir de um arquivo CSV
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[in]    n Número de empresas no cadastro
    * @param[in]    pausa True para apresentar uma pausa após a impressão do relatório de importação
    * @return       Retorna o novo vetor de empresas após o cadastro
    */
    Empresa *addFuncArq(Empresa *e, int n, bool pausa = true);

    /**
    * @brief        Função que remove um funcionário de uma empresa (apresenta escolha)
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[in]    n Número de empresas no cadastro
    * @return       Retorna o novo vetor de empresas após o cadastro
    */
    Empresa *delFunc(Empresa *e, int n);

    /**
    * @brief        Função que solicita um valor (percentual) e uma empresa (apresenta escolha)
    *               para dar um aumento à todos os seus funcionários
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[in]    n Número de empresas no cadastro
    * @return       Retorna o novo vetor de empresas após o cadastro
    */
    Empresa *aumento(Empresa *e, int n);

    /**
    * @brief        Função que imprime as empresas no cadastro
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    * @param[in]    n Número de empresas no cadastro
    */
    void impEmpresas(Empresa *e, int n, bool pausa = true);

    /**
    * @brief        Função que imprime a lista de funcionários de uma ou todas 
                    as empresas do cadastro
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[in]    n Número de empresas no cadastro
    * @param[in]    all "true" imprime todos os funcionários de todas as empresas
                    "false" imprime apenas os funcionários de uma empresa (apresenta escolha)
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    * @return       -1 ou o número da empresa selecionada
    */
    int impFunc(Empresa *e, int n, bool all = true, bool pausa = true);

    /**
    * @brief        Função que imprime a lista de funcionários em experiência 
                    de uma empresa (apresenta escolha)
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[in]    n Número de empresas no cadastro
    * @param[in]    pausa True para apresentar uma pausa após a impressão
    * @return       -1 ou o número da empresa selecionada
    */
    int impFuncExp(Empresa *e, int n, bool pausa);

    /**
    * @brief        Função que salva o cadastro completo em arquivo
    * @param[in]    nome Caminho/nome do arquivo de dados
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[in]    n Número de empresas no cadastro
    */
    void salvarBD(string nome, Empresa *e, int n);

    /**
    * @brief        Função que recupera o cadastro completo a partir de um arquivo
    * @param[in]    nome Caminho/nome do arquivo de dados
    * @param[in]    *e Vetor de empresas do cadastro
    * @param[inout] n Número de empresas no cadastro
    * @return       Retorna o novo vetor de empresas após a importação
    */
    Empresa *abrirBD(string nome, Empresa *e, int &n);

#endif