/**
 * @file	tratastring.cpp
 * @brief	Implementacao de funcoes para tratamento de strings
 * @details	As funcoes definidas neste arquivo de corpo dizem respeito a conversao
 *			da string para letras minusculas, remocao de espacos em branco e
 *			remocao de caracteres de pontuacao.
 * @author	Everton Cavalcante (everton@dimap.ufrn.br)
 * @author	Silvio Sampaio (silviocs@imd.ufrn.br)
 * @since	18/03/2017
 * @date	11/05/2017
 * @sa		tratastring.h
 */

#include <cctype>
using std::ispunct;
using std::tolower;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "tratastring.h"

/**
 * @brief Funcao que converte todos os caracteres para letra minuscula
 * @param s String a ser convertida
 */
void minusculas(string& s) {
	for (int i = 0; i < (int)s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}


/**
 * @brief Funcao que remove espacos de uma string
 * @param s String com espacos a remover
 */
void remove_espacos(string& s) {
	string strOut;
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
			s.erase(i, 1);
			i--;
		}
	}
}


/**
 * @brief Funcao que remove sinais de pontuacao de uma string
 * @param s String com sinais de pontuacao a remover
 */
void remove_pontuacao(string& s) {
	for (int i = 0; i < (int)s.length(); i++) {
		if (ispunct(s[i])) {
			s.erase(i, 1);
		}
	}
}

/**
 * @brief Função que remove acentuações de uma string
 * @param s String com acentuações a remover
 */
void remove_acentos (string &s) {
    string com_acento = "âÂàÀáÁãÃêÊèÈéÉẽẼîÎìÌíÍõÕôÔòÒóÓüÜûÛúÚùÙçÇ";
    string sem_acento = "aAaAaAaAeEeEeEeEiIiIiIoOoOoOoOuUuUuUuUcC";
    int temp = com_acento.length();
    for (int ii = 0; s[ii] != '\0'; ii++) {
        int kk = 0;
        for (int jj = 0; jj < temp; jj += 2) {
            if ((s[ii] == com_acento[jj]) && (s[ii + 1] == com_acento[jj + 1])) {   
                s[ii] = sem_acento[kk];
                s.erase((ii + 1), 1);
                ii += 1;
                break;
            }
            kk++;
        }
    }
}

/**
 * @brief Funcao que trata uma string, removendo espacos em branco
 * @param s String a ser tratada
 */
void tratar_string(string& s) {
	minusculas(s);			// Conversao da string para minusculas
	remove_espacos(s);		// Remocao de espacos
	remove_pontuacao(s);	// Remocao de pontuacao
	remove_acentos(s);
}