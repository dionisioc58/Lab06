/**
 * @file	funcionario.h
 * @brief	Definição da classe Funcionario
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#ifndef FUNCIONARIO_H
    #define FUNCIONARIO_H

    #include <iostream>
    #include <string>
    #include <sstream>
    using std::string;
    using std::ostream;
    using std::istream;
    using std::stringstream;
    #include <ctime>
    
    /**
    * @class   Funcionario funcionario.h
    * @brief   Classe que representa um funcionário
    * @details Os atributos de um funcionário são: nome, salário e data de admissão
    */  
    class Funcionario {
    private:
        string nome;                                            /**< Nome */
        float salario;                                          /**< Salário */
        std::time_t admissao;                                   /**< Data de admissão */
    public:
        Funcionario();                                          /**< Construtor padrão */
        string getNome();                                       /**< Retorna o nome */
        void setNome(string n);                                 /**< Modifica o nome */
        float getSalario();                                     /**< Retorna o salário */
        void setSalario(float s);                               /**< Modifica o salário */
        std::time_t getAdmissao();                              /**< Retorna a data de admissão */
        void setAdmissao(std::time_t a);                        /**< Modifica a data de admissão */
        bool experiencia();                                     /**< Retorna true se o está em período de experiência */
        string exportar();                                      /**< Retorna uma string com os dados para exportação CSV */
        friend ostream& operator<<(ostream& os, Funcionario &f); /** @brief Sobrecarga do operador de inserção em stream */
        friend istream& operator>>(istream& is, Funcionario &f); /** @brief Sobrecarga do operador de extração de stream */
    };

#endif