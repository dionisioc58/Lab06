/**
 * @file	lista.h
 * @brief	Definição da classe Lista
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	06/05/2017
 * @date	28/04/2017
 */

#ifndef LISTA_H
    #define LISTA_H

    #include <iostream>
    #include <ctime>
    #include <string>
    using std::cout;
    using std::string;
    using std::endl;

    /**
    * @class   Lista lista.h
    * @brief   Classe que representa uma lista duplamente encadeada
    * @details Os atributos de uma lista são: dado, ant e prox
    */  
    class Lista {
    private:
        float dado;                                         /**< Dado */
        Lista *ant;                                         /**< Anterior */
        Lista *prox;                                        /**< Próximo */
    public:
        Lista();                                            /**< Construtor padrão */
        ~Lista();                                           /**< Destrutor padrão */
        void Insere(int el);
        void Remove(int pos);
        void Exibe();
    };

#endif