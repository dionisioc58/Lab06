/**
* @file     dados.cpp
* @brief 	Arquivo fonte para execução do projeto
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    07/05/2017
* @date     07/05/2017
*/

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "funcionario.h"

const int alvo = 50;

int dado(int max) {
    return 1 + (rand() % max);
}

/**
* @brief        Função principal do programa
* @param[in]	argc	Quantidade de argumentos
* @param[in]    *argv[]	Argumento com o caminho/nome do arquivo de dados a ser lido
* @return		Retorno
*/
int main(int argc, char* argv[]) {
    //Inicializa a função rand()
	srand (std::time(NULL));
    
    int jogadores = 3, rodadas = 0;
    Funcionario *f = new Funcionario[jogadores];
    f[0].setNome("Dionísio");
    f[0].setSalario(0);
    f[1].setNome("Ewerton");
    f[1].setSalario(0);
    f[2].setNome("Sílvio");
    f[2].setSalario(0);

    while(1) {
        rodadas++;
        for(int i = 0; i < jogadores; i++) {                        //Realiza uma rodada
            if(f[i].getSalario() < alvo) {                          //Somente quem está abaixo do alvo pode jogar
                int decide = dado(2);                               //Decide se o jogador vai participar da rodada ou não
                if(decide == 1) {                                   //Se 1 ele joga
                    float dados = f[i].getSalario() + dado(6) + dado(6);//Joga dois dados e soma
                    f[i].setSalario(dados);                             //Salva como o total do jogador
                }
            }
        }
        bool venceu = false;
        for(int i = 0; i < jogadores; i++) {        //Procura ganhadores
            if(f[i].getSalario() == alvo) {
                cout << "Jogador " << f[i].getNome() << " venceu após " << rodadas << " rodadas!" << endl;
                venceu = true;
            }
        }
        if(venceu)                              //Se alguém conseguiu o valor exato, encerra o jogo
            return 0;
        
        bool continua = false;
        for(int i = 0; i < jogadores; i++) {      //Procura se ainda há jogadores
            if(f[i].getSalario() < alvo)
                continua = true;
        }
        if(!continua) {
            cout << "Ninguém mais jogando!" << endl;
            cout << "Após " << rodadas << " rodadas." << endl;
            for(int i = 0; i < jogadores; i++) {        //Imprime a tabela de pontos
                cout << (i + 1) << "º jogador: " << f[i].getNome() << "\t Pontos: " << f[i].getSalario() << endl;
            }
            return 0;
        }
    }

    return 0;
}