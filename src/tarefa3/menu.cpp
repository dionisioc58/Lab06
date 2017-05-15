/**
* @file 	menu.cpp
* @brief	Arquivo de corpo com a definição de funções para o menu
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    28/04/2017
* @date     15/05/2017
*/

#include "tarefa3/menu.h"

/**
* @brief        Função que exibe o menu principal
* @return       Retorna a opção escolhida
*/
int showMenu() {
    cout << "\t\t|**************************************************|" << endl;
    cout << "\t\t|          DDA - Turmas e Alunos                   |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|  (1) Cadastrar uma turma                         |" << endl;
    cout << "\t\t|  (2) Excluir uma turma                           |" << endl;
    cout << "\t\t|  (3) Listar as turmas                            |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|  (4) Cadastrar um aluno                          |" << endl;
    cout << "\t\t|  (5) Cadastrar alunos através de um arquivo      |" << endl;
    cout << "\t\t|  (6) Excluir um aluno                            |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|  (7) Listar alunos                               |" << endl;
    cout << "\t\t|  (8) Listar alunos de todas as turmas            |" << endl;
    cout << "\t\t|  (9) Listar as médias de uma turma               |" << endl;
    cout << "\t\t|  (10)Listar as médias de todas as turmas         |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|  (11)Salvar o cadastro em um arquivo             |" << endl;
    cout << "\t\t|  (12)Recuperar o cadastro em um arquivo          |" << endl;
    cout << "\t\t|  (0) Sair                                        |" << endl;
    cout << "\t\t|                                                  |" << endl;
    cout << "\t\t|**************************************************|" << endl;
    
    int opcao = 0;
    do {
        opcao = recebeInt(": ", 0);
        if((opcao < 0) || (opcao > 10))
            cout << "Valor inválido!" << endl;
    } while ((opcao < 0) || (opcao > 12));
    return opcao;
}