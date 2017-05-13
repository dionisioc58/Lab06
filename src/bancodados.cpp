/**
* @file 	bancodados.cpp
* @brief	Arquivo de corpo com a definição de funções para o controle dos dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    29/04/2017
* @date     07/05/2017
*/

#include "bancodados.h"

/**
* @brief        Função que coleta os dados para cadastro de uma empresa
* @return       Empresa coletada
*/
Empresa *inputEmpresa() {
    //Coleta dados da empresa
    string input;
    Empresa *nova = new Empresa[1];
    cout << "Digite o nome da empresa: ";
    getline(cin, input);
    nova[0].setNome(input);
    cout << endl << "Digite o CNPJ da empresa: ";
    getline(cin, input);
    nova[0].setCnpj(input);
    return nova;
}

/**
* @brief        Função que coleta os dados para cadastro de um funcionário
* @return       Funcionário coletado
*/
Funcionario *inputFuncionario() {
    //Coleta dados do funcionário
    string input;
    Funcionario *novo = new Funcionario[1];

    cout << "Digite o nome do funcionário: ";
    getline(cin, input);
    novo[0].setNome(input);

    float sal = recebeFloat("Digite o salário: ", 0);
    novo[0].setSalario(sal);
    
    cout << "Digite a data de admissão (dd/mm/yyyy): ";
    cin >> input;
    int dia, mes, ano;
    dia = stoi(input.substr(0, 2));
    mes = stoi(input.substr(3, 2));
    ano = stoi(input.substr(6, 4));
    std::tm a = {0, 0, 0, dia, mes - 1, ano - 1900};
    novo[0].setAdmissao(std::mktime(&a));

    return novo;
}

/**
* @brief        Função que verifica se uma empresa já existe no cadastro
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @param[in]    *nova Empresa à ser verificada
* @return       Retorna true caso já exista
*/
bool existeEmpresa(Empresa *e, int n, Empresa *nova) {
    //Testa se já existe no cadastro
    for(int i = 0; i < n; i++) {
        if(e[i].getCnpj() == nova[0].getCnpj()) {
            cout << "Empresa já cadastrada!" << endl;
            return true;
        }
    }
    return false;
}

/**
* @brief        Função que realiza o cadastro uma empresa
* @param[in]    *e Vetor de empresas do cadastro
* @param[inout] n Número de empresas no cadastro
* @return       Retorna o novo vetor de empresas após o cadastro
*/
Empresa *cadEmpresa(Empresa *e, int &n) {
    Empresa *nova = inputEmpresa();
    if(existeEmpresa(e, n, nova))
        return e;

    Empresa *r = new Empresa[n + 1];
    
    //Se já tem empresas, aumenta o vetor, copia a antiga lista para um novo maior
    int j = 0;
    for(int i = 0; i < n; i++) {
        r[j].setNome(e[i].getNome());
        r[j].setCnpj(e[i].getCnpj());
        r[j].setFuncionarios(e[i].getFuncionarios(), e[i].getQtde());
        j++;
    }
    if(n > 0)
        delete[] e;

    r[n++] = nova[0]; //Guarda o elemento informado
    delete[] nova;
    return r;
}

/**
* @brief        Função que remove uma empresa do cadastro
* @param[in]    *e Vetor de empresas do cadastro
* @param[inout] n Número de empresas no cadastro
* @return       Retorna o novo vetor de empresas após a exclusão
*/
Empresa *delEmpresa(Empresa *e, int &n) {
    if(n == 0)
        return e;

    impEmpresas(e, n, false);
    int selecao = recebeInt("Digite o número da empresa para a remoção (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    if(selecao > (n - 1)) {
        cout << "Seleção inválida!" << endl;
        return e;
    }

    Empresa *r = new Empresa[n - 1];

    //Se já tem empresas, diminui o vetor, copia a antiga lista para uma nova menor
    int j = 0;
    for(int i = 0; i < n; i++)
        if(i != selecao) {
            r[j].setNome(e[i].getNome());
            r[j].setCnpj(e[i].getCnpj());
            r[j].setFuncionarios(e[i].getFuncionarios(), e[i].getQtde());
            j++;
        }

    delete[] e;
    n--;
    return r;
}

/**
* @brief        Função que adiciona um funcionário à uma empresa (apresenta escolha)
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @return       Retorna o novo vetor de empresas após o cadastro
*/
Empresa *addFunc(Empresa *e, int n) {
    if(n == 0)
        return e;

    impEmpresas(e, n, false);
    int selecao = recebeInt("Digite o número da empresa para a adição (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    Funcionario *f;
    f = inputFuncionario();
    e[selecao].addFuncionario(f);
    delete[] f;
    return e;
}

/**
* @brief        Função que adiciona funcionários à uma empresa (apresenta escolha),
*               carregando-os apartir de um arquivo CSV
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão do relatório de importação
* @return       Retorna o novo vetor de empresas após o cadastro
*/
Empresa *addFuncArq(Empresa *e, int n, bool pausa) {
    if(n == 0)
        return e;

    impEmpresas(e, n, false);
    int selecao = recebeInt("Digite o número da empresa para a adição (0 para cancelar): ", 0);
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
    Funcionario f;
    while(!lista.eof()) {
        lista >> f;
        linhas++;
        if(f.getNome() != "\n") {
            e[selecao].addFuncionario(&f);
            funcs++;
        }
    }
    lista.close();
    cout << "Importação concluída com sucesso! " << endl;
    cout << linhas << " linhas no arquivo." << endl;
    cout << funcs << " funcionários cadastrados." << endl;

    if(pausa) {
        cin.ignore();
        cout << "Pressione ENTER para continuar...";
        string pausa;
        getline(cin, pausa);
    }

    return e;
}

/**
* @brief        Função que remove um funcionário de uma empresa (apresenta escolha)
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @return       Retorna o novo vetor de empresas após o cadastro
*/
Empresa *delFunc(Empresa *e, int n) {
    if(n == 0)
        return e;

    int empsel = impFunc(e, n, false, false); //Captura a empresa selecionada
    int selecao = recebeInt("Digite o número do funcionário à remover (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    if(!e[empsel].delFuncionario(selecao))
        cout << "Não foi possível remover!" << endl;
    return e;
}

/**
* @brief        Função que solicita um valor (percentual) e uma empresa (apresenta escolha)
*               para dar um aumento à todos os seus funcionários
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @return       Retorna o novo vetor de empresas após o cadastro
*/
Empresa *aumento(Empresa *e, int n) {
    if(n == 0)
        return e;

    impEmpresas(e, n, false);
    int selecao = recebeInt("Digite o número da empresa para a adição (0 para cancelar): ", 0);
    if(selecao == 0)
        return e;
    selecao--;  //O usuário vai digitar o número com base em 1

    float add = recebeFloat("Digite o valor do percentual de aumento: ", 0);
    if(add <= 0)
        return e;

    e[selecao].aumento(add);

    return e;
}

/**
* @brief        Função que imprime as empresas no cadastro
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão
*/
void impEmpresas(Empresa *e, int n, bool pausa) {
    cout << "Lista de empresas cadastradas: " << endl;
    for(int i = 0; i < n; i++)
        cout << "-- (" << (i + 1) << ") " << e[i].getNome() << "\t CNPJ = " << e[i].getCnpj() << endl;
    cout << endl;
    if(pausa) {
        cout << "Pressione ENTER para continuar...";
        string pausa;
        getline(cin, pausa);
    }
}

/**
* @brief        Função que imprime a lista de funcionários de uma ou todas 
                as empresas do cadastro
* @param[inout] *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @param[in]    all "true" imprime todos os funcionários de todas as empresas
                "false" imprime apenas os funcionários de uma empresa (apresenta escolha)
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número da empresa selecionada
*/
int impFunc(Empresa *e, int n, bool all, bool pausa) {
    if(n == 0)
        return -1;
    if(!all) {      //Imprime todos os funcionários de uma empresa
        impEmpresas(e, n, false);
        int selecao = recebeInt("Digite o número da empresa (0 para cancelar): ", 0);
        if(selecao == 0)
            return -1;
        selecao--;  //O usuário vai digitar o número com base em 1

        if(e[selecao].getQtde() > 0) {
            cout << "Funcionários da empresa " << e[selecao].getNome() << endl;
            Funcionario *f = e[selecao].getFuncionarios();
            for(int i = 0; i < e[selecao].getQtde(); i++)
                cout << "   (" << (i + 1) << ") " << f[i] << endl;

        } else
            cout << "Nenhum funcionário na empresa selecionada." << endl;
        
        if(pausa) {
            cout << "Pressione ENTER para continuar...";
            string pausa;
            getline(cin, pausa);
        }
        return selecao;
    } else {        //Imprime todos os funcionários de todas as empresas
        Funcionario *f;
        for(int j = 0; j < n; j++) {
            if(e[j].getQtde() > 0) {
                cout << "Funcionários da empresa " << e[j].getNome() << endl;
                f = e[j].getFuncionarios();
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
* @brief        Função que imprime a lista de funcionários em experiência 
                de uma empresa (apresenta escolha)
* @param[inout] *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
* @param[in]    pausa True para apresentar uma pausa após a impressão
* @return       -1 ou o número da empresa selecionada
*/
int impFuncExp(Empresa *e, int n, bool pausa) {
    if(n == 0)
        return -1;
    impEmpresas(e, n, false);
    int selecao = recebeInt("Digite o número da empresa (0 para cancelar): ", 0);
    if(selecao == 0)
        return -1;
    selecao--;  //O usuário vai digitar o número com base em 1

    if(e[selecao].getQtde() > 0) {
        cout << "Funcionários da empresa " << e[selecao].getNome() << " em período de experiência:" << endl;
        Funcionario *f = e[selecao].getFuncionarios();
        bool existe = false;
        for(int i = 0; i < e[selecao].getQtde(); i++)
            if(f[i].experiencia()) {
                cout << "   (" << (i + 1) << ") " << f[i] << endl;
                existe = true;
            }
        if(!existe)
            cout << "0 funcionários";
    } else
        cout << "Nenhum funcionário na empresa selecionada." << endl;
    
    if(pausa) {
        cout << "Pressione ENTER para continuar...";
        string pausa;
        getline(cin, pausa);
    }
    return selecao;
}

/**
* @brief        Função que salva o cadastro completo em arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de empresas do cadastro
* @param[in]    n Número de empresas no cadastro
*/
void salvarBD(string nome, Empresa *e, int n) {
    ofstream saida(nome);
    if(!saida) {
        cout << "Não foi possível abrir o arquivo para salvar." << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        saida << e[i].exportar() << endl;
        for(int j = 0; j < e[i].getQtde(); j++)
            saida << e[i].getFuncionarios()[j].exportar() << endl;
    }

    saida.close();
    cout << "Banco de dados salvo com sucesso!" << endl;
}

/**
* @brief        Função que recupera o cadastro completo a partir de um arquivo
* @param[in]    nome Caminho/nome do arquivo de dados
* @param[in]    *e Vetor de empresas do cadastro
* @param[inout] n Número de empresas no cadastro
* @return       Retorna o novo vetor de empresas após o cadastro
*/
Empresa *abrirBD(string nome, Empresa *e, int &n) {
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
        if(texto.substr(0, 4) == "empr")
            n++;
    }
    Empresa *r = new Empresa[n];
    
    int conta = -1;
    entrada.clear();
    entrada.seekg(0);
    
    Funcionario *f = new Funcionario[1];
    while(!entrada.eof()) {
        getline(entrada, texto);
        if(texto != "") {
            info.clear();
            info << texto.substr(5);

            if(texto.substr(0, 4) == "empr")
                info >> r[++conta];

            if(texto.substr(0, 4) == "func") {
                if(conta > -1) {
                    info >> f[0];
                    r[conta].addFuncionario(f);
                }
            }
        }   
    }
    delete[] f;
    entrada.close();
    cout << "Recuperação concluída com sucesso!" << endl;

    return r;
}