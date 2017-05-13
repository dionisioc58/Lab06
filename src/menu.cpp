/**
* @file 	menu.cpp
* @brief	Arquivo de corpo com a definição de funções para o menu
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    28/04/2017
* @date     28/04/2017
*/

#include "menu.h"

/**
* @brief        Função que exibe o menu principal
* @return       Retorna a opção escolhida
*/
int showMenuEmp() {
    cout << "\t\t|**************************************************|" << endl;
    cout << "\t\t|          DDA - Cadastro de Empresas              |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|  (1) Cadastrar uma empresa                       |" << endl;
    cout << "\t\t|  (2) Excluir uma empresa                         |" << endl;
    cout << "\t\t|  (3) Listar as empresas                          |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|  (4) Cadastrar um funcionário                    |" << endl;
    cout << "\t\t|  (5) Cadastrar funcionários através de um arquivo|" << endl;
    cout << "\t\t|  (6) Excluir um funcionário                      |" << endl;
    cout << "\t\t|  (7) Dar aumento aos funcionários                |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|  (8) Listar funcionários                         |" << endl;
    cout << "\t\t|  (9) Listar funcionários em experiência          |" << endl;
    cout << "\t\t|  (10)Listar funcionários de todas as empresas    |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|  (11)Salvar o cadastro em um arquivo             |" << endl;
    cout << "\t\t|  (12)Recuperar o cadastro em um arquivo          |" << endl;
    cout << "\t\t|  (0) Sair                                        |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|**************************************************|" << endl;
    
    int opcao = 0;
    do {
        opcao = recebeInt(": ", 0);
        if((opcao < 0) || (opcao > 12))
            cout << "Valor inválido!" << endl;
    } while ((opcao < 0) || (opcao > 12));
    return opcao;
}