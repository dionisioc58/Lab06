/**
 * @file	empresa.h
 * @brief	Definição da classe Empresa
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#ifndef EMPRESA_H
    #define EMPRESA_H

    #include <iostream>
    #include <ctime>
    #include <string>
    using std::string;
    using std::endl;

    #include "funcionario.h"

    /**
    * @class   Empresa empresa.h
    * @brief   Classe que representa uma empresa
    * @details Os atributos de um funcionário são: nome, cnpj, funcionários e a qtde deles
    */  
    class Empresa {
    private:
        string nome;                                        /**< Nome */
        string cnpj;                                        /**< CNPJ */
        Funcionario *funcionarios;                          /**< Lista de funcionários */
        int qtde;                                           /**< Quantidade de funcionários */
    public:
        Empresa();                                          /**< Construtor padrão */
        ~Empresa();                                         /**< Destrutor padrão */
        string getNome();                                   /**< Retorna o nome */
        void setNome(string n);                             /**< Modifica o nome */
        string getCnpj();                                   /**< Retorna o CNPJ */
        void setCnpj(string c);                             /**< Modifica o CNPJ */
        int getQtde();                                      /**< Retorna a quantidade de funcionários */
        Funcionario *getFuncionarios();                     /**< Retorna a lista de funcionários */
        void setFuncionarios(Funcionario *f, int n);        /**< Modifica a lista de funcionários */
        bool addFuncionario(Funcionario *f);                /**< Adiciona um funcionário */
        bool delFuncionario(int f);                         /**< Remove um funcionário */
        bool pertenceQuadro(string n);                      /**< Verifica se um nome pertence à lista de funcionários */
        void aumento(float percentual);                     /**< Aplica um percentual de aumento aos funcionários */
        string exportar();                                  /**< Retorna uma string com os dados para exportação CSV */
		friend ostream& operator<<(ostream& os, Empresa &e); /** @brief Sobrecarga do operador de inserção em stream */
		friend istream& operator>>(istream& is, Empresa &e); /** @brief Sobrecarga do operador de extração de stream */
    };

#endif