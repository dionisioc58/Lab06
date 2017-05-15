/**
* @file     tarefa3main.cpp
* @brief 	Arquivo fonte para execução do projeto
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    25/04/2017
* @date     15/05/2017
*/

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "tarefa3/aluno.h"
#include "tarefa3/turma.h"
#include "tarefa3/menu.h"
#include "tarefa3/bancodados.h"

/**
* @brief        Função principal do programa
* @param[in]	argc	Quantidade de argumentos
* @param[in]    *argv[]	Argumento com o caminho/nome do arquivo de dados a ser lido
* @return		Retorno
*/
int main(int argc, char* argv[]) {
    int qtdemp = 0;         /**< Quantidade de turmas cadastradas */
    Turma *emp = NULL;    /**< Vetor de turmas que conterá todo o cadastro */
    emp = abrirBD("./data/banco.dat", emp, qtdemp); /**< Recuperar o cadastro a partir de um arquivo */
    while(1) {
        switch(showMenu()) { //Exibir o menu
            case 0:             //Sair
                delete[] emp;
                return 0;
                break;
            case 1:              //Cadastrar uma Turma
                emp = cadTurma(emp, qtdemp);
                break;
            case 2:              //Excluir uma Turma
                emp = delTurma(emp, qtdemp);
                break;
            case 3:              //Listar as Turma
                impTurmas(emp, qtdemp);
                break;

            case 4:              //Adicionar um aluno
                emp = addAl(emp, qtdemp);
                break;
            case 5:              //Adicionar alunos através de um arquivo
                emp = addAlArq(emp, qtdemp);
                break;
            case 6:              //Remover um aluno
                emp = delAl(emp, qtdemp);
                break;
            
            case 7:              //Listar os alunos de uma turma
                impAl(emp, qtdemp, false);
                break;
            
            case 8:             //Listar todos os alunos de todas as turmas
                impAl(emp, qtdemp, true);
                break;

            case 9:            //Salvar o banco de dados
                salvarBD("./data/banco.dat", emp, qtdemp); 
                break;
            case 10:            //Recuperar o banco
                emp = abrirBD("./data/banco.dat", emp, qtdemp); 
                break;
        }
    }
    
    delete[] emp;
    return 0;
}