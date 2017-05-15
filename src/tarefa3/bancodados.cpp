/**
* @file 	bancodados.cpp
* @brief	Arquivo de corpo com a definição de funções para o controle dos dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    29/04/2017
* @date     15/05/2017
*/

#include "tarefa3/bancodados.h"

/**
* @brief        Função que coleta os dados para cadastro de uma turma
* @return       Turma coletada
*/
Turma *inputTurma() {
    //Coleta dados da turma
    string input;
    Turma *nova = new Turma[1];
    cout << "Digite o nome da turma: ";
    getline(cin, input);
    nova[0].setNome(input);
    return nova;
}

/**
* @brief        Função que coleta os dados para cadastro de um aluno
* @return       Funcionário coletado
*/
Aluno *inputAluno() {
    //Coleta dados do aluno
    string input;
    Aluno *novo = new Aluno[1];

    cout << "Digite o nome do aluno: ";
    getline(cin, input);
    novo[0].setNome(input);

    cout << "Digite a matrícula do aluno: ";
    getline(cin, input);
    novo[0].setMatricula(input);

    int faltas = recebeInt("Digite a quantidade de faltas: ", 0);
    novo[0].setFaltas(faltas);

    float nota = recebeFloat("Digite a nota: ", 0);
    novo[0].setNota(nota);
    
    return novo;
}

/**
* @brief        Função que verifica se uma turma já existe no cadastro
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @param[in]    *nova Turma à ser verificada
* @return       Retorna true caso já exista
*/
bool existeTurma(Turma *e, int n, Turma *nova) {
    //Testa se já existe no cadastro
    for(int i = 0; i < n; i++) {
        if(e[i].getNome() == nova[0].getNome()) {
            cout << "Turma já cadastrada!" << endl;
            return true;
        }
    }
    return false;
}

/**
* @brief        Função que realiza o cadastro uma turma
* @param[in]    *e Vetor de turmas do cadastro
* @param[inout] n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *cadTurma(Turma *e, int &n) {
    Turma *nova = inputTurma();
    if(existeTurma(e, n, nova))
        return e;

    Turma *r = new Turma[n + 1];
    
    //Se já tem Turmas, aumenta o vetor, copia a antiga lista para um novo maior
    int j = 0;
    for(int i = 0; i < n; i++) {
        r[j].setNome(e[i].getNome());
        r[j].setAlunos(e[i].getAlunos(), e[i].getQtde());
        j++;
    }
    if(n > 0)
        delete[] e;

    r[n++] = nova[0]; //Guarda o elemento informado
    delete[] nova;
    return r;
}

/**
* @brief        Função que remove uma turma do cadastro
* @param[in]    *e Vetor de turmas do cadastro
* @param[inout] n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após a exclusão
*/
Turma *delTurma(Turma *e, int &n) {
    if(n == 0)
        return e;

    impTurmas(e, n, false);
    int selecao = recebeInt("Digite o número da turma para a remoção (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    if(selecao > (n - 1)) {
        cout << "Seleção inválida!" << endl;
        return e;
    }

    Turma *r = new Turma[n - 1];

    //Se já tem turmas, diminui o vetor, copia a antiga lista para uma nova menor
    int j = 0;
    for(int i = 0; i < n; i++)
        if(i != selecao) {
            r[j].setNome(e[i].getNome());
            r[j].setAlunos(e[i].getAlunos(), e[i].getQtde());
            j++;
        }

    delete[] e;
    n--;
    return r;
}

/**
* @brief        Função que adiciona um aluno à uma turma (apresenta escolha)
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *addAl(Turma *e, int n) {
    if(n == 0)
        return e;

    impTurmas(e, n, false);
    int selecao = recebeInt("Digite o número da turma para a adição (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    Aluno *f;
    f = inputAluno();
    e[selecao].addAluno(f);
    delete[] f;
    return e;
}

/**
* @brief        Função que adiciona alunos à uma turma (apresenta escolha),
*               carregando-os apartir de um arquivo CSV
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão do relatório de importação
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *addAlArq(Turma *e, int n, bool pausa) {
    if(n == 0)
        return e;

    impTurmas(e, n, false);
    int selecao = recebeInt("Digite o número da turma para a adição (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    string arquivo;
    cout << "Digite o caminho/nome do arquivo à ser lido: ";
    cin >> arquivo;
    ifstream lista(arquivo);
    if(!lista) {
        cout << "Arquivo inválido/não encontrado!" << endl;
        return e;
    }

    int linhas = 0, funcs = 0;
    Aluno f;
    while(!lista.eof()) {
        lista >> f;
        linhas++;
        if(f.getNome() != "\n") {
            e[selecao].addAluno(&f);
            funcs++;
        }
    }
    lista.close();
    cout << "Importação concluída com sucesso! " << endl;
    cout << linhas << " linhas no arquivo." << endl;
    cout << funcs << " alunos cadastrados." << endl;

    if(pausa) {
        cin.ignore();
        cout << "Pressione ENTER para continuar...";
        string pausa;
        getline(cin, pausa);
    }

    return e;
}

/**
* @brief        Função que remove um aluno de uma turma (apresenta escolha)
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *delAl(Turma *e, int n) {
    if(n == 0)
        return e;

    int empsel = impAl(e, n, false, false); //Captura a turma selecionada
    int selecao = recebeInt("Digite o número do aluno à remover (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    if(!e[empsel].delAluno(selecao))
        cout << "Não foi possível remover!" << endl;
    return e;
}

/**
* @brief        Função que imprime as turmas no cadastro
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão
*/
void impTurmas(Turma *e, int n, bool pausa) {
    cout << "Lista de turmas cadastradas: " << endl;
    for(int i = 0; i < n; i++)
        cout << "-- (" << (i + 1) << ") " << e[i] << endl;
    cout << endl;
    if(pausa) {
        cout << "Pressione ENTER para continuar...";
        string pausa;
        getline(cin, pausa);
    }
}

/**
* @brief        Função que imprime a lista de alunos de uma ou todas 
                as turmas do cadastro
* @param[inout] *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
* @param[in]    all "true" imprime todos os alunos de todas as turmas
                "false" imprime apenas os alunos de uma turma (apresenta escolha)
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número da turma selecionada
*/
int impAl(Turma *e, int n, bool all, bool pausa) {
    if(n == 0)
        return -1;
    if(!all) {      //Imprime todos os alunos de uma turma
        impTurmas(e, n, false);
        int selecao = recebeInt("Digite o número da turma (0 para cancelar): ", 0);
        if(selecao == 0)
            return -1;
        selecao--;  //O usuário vai digitar o número com base em 1

        if(e[selecao].getQtde() > 0) {
            cout << "Alunos da turma " << e[selecao].getNome() << endl;
            Aluno *f = e[selecao].getAlunos();
            for(int i = 0; i < e[selecao].getQtde(); i++)
                cout << "   (" << (i + 1) << ") " << f[i] << endl;

        } else
            cout << "Nenhum aluno na turma selecionada." << endl;
        
        if(pausa) {
            cout << "Pressione ENTER para continuar...";
            string pausa;
            getline(cin, pausa);
        }
        return selecao;
    } else {        //Imprime todos os funcionários de todas as empresas
        Aluno *f;
        for(int j = 0; j < n; j++) {
            if(e[j].getQtde() > 0) {
                cout << "Alunos da turma " << e[j].getNome() << endl;
                f = e[j].getAlunos();
                for(int i = 0; i < e[j].getQtde(); i++)
                    cout << "   (" << (i + 1) << ") " << f[i] << endl;
            }
        }
        
        if(pausa) {
            cout << "Pressione ENTER para continuar...";
            string pausa;
            getline(cin, pausa);
        }
        return -1;
    }
}

/**
* @brief        Função que salva o cadastro completo em arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de turmas do cadastro
* @param[in]    n Número de turmas no cadastro
*/
void salvarBD(string nome, Turma *e, int n) {
    ofstream saida(nome);
    if(!saida) {
        cout << "Não foi possível abrir o arquivo para salvar." << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        saida << e[i].exportar() << endl;
        for(int j = 0; j < e[i].getQtde(); j++)
            saida << e[i].getAlunos()[j].exportar() << endl;
    }

    saida.close();
    cout << "Banco de dados salvo com sucesso!" << endl;
}

/**
* @brief        Função que recupera o cadastro completo a partir de um arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de turmas do cadastro
* @param[inout] n Número de turmas no cadastro
* @return       Retorna o novo vetor de turmas após o cadastro
*/
Turma *abrirBD(string nome, Turma *e, int &n) {
    ifstream entrada(nome);
    if(!entrada) {
        cout << "Não foi possível abrir o arquivo para carregar." << endl;
        return e;
    }
    string texto;
    stringstream info;
    n = 0;
    while(!entrada.eof()) {
        getline(entrada, texto);
        if(texto.substr(0, 5) == "turma")
            n++;
    }
    Turma *r = new Turma[n];
    
    int conta = -1;
    entrada.clear();
    entrada.seekg(0);
    
    Aluno *f = new Aluno[1];
    while(!entrada.eof()) {
        getline(entrada, texto);
        if(texto != "") {
            info.clear();
            info << texto.substr(6);

            if(texto.substr(0, 5) == "turma")
                info >> r[++conta];

            if(texto.substr(0, 5) == "aluno") {
                if(conta > -1) {
                    info >> f[0];
                    r[conta].addAluno(f);
                }
            }
        }   
    }
    delete[] f;
    entrada.close();
    cout << "Recuperação concluída com sucesso!" << endl;

    return r;
}