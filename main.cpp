#include <iostream>
#include <string>
using namespace std;

#include "pilha.h"
#include "tratastring.h"

int main() {
    string teste;
    cout << "Digite uma palavra para testar: ";
    getline(cin, teste);

    string palavra = teste;
    tratar_string(teste);

    Pilha<string> pilha(teste.length());
    for(unsigned int i = 0; i < teste.length(); i++)
        pilha.Push(teste.substr(i, 1));
    
    string teste2 = "";
    while(!pilha.Vazio())
        teste2 += pilha.Pop();

    if (teste == teste2)
        cout << "'" << palavra << "' é palíndrome!" << endl;
    else
        cout << "'" << palavra << "' NÃO é palíndrome!" << endl;
    return 0;
}