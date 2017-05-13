#Makefile for "Laboratorio 06" C++ aplication
#Created by Dionísio Carvalho

# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf

# Compilador
CC = g++

# Variaveis para os subdiretorios
BIN_DIR = ./bin
OBJ_DIR = ./build
DOC_DIR = ./doc
INC_DIR = ./include
SRC_DIR = ./src
TST_DIR = ./test

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I $(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: clean tarefa1 tarefa2 doxy
debug: CFLAGS += -g -O0
debug: clean tarefa1 tarefa2

# Alvo (target) para a construcao do executavel tarefa1
# Define os arquivos tratastring.o e main.o como dependencias
tarefa1: $(OBJ_DIR)/tratastring.o $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto tratastring.o
# Define os arquivos tratastring.cpp e tratastring.h como dependencias.
$(OBJ_DIR)/tratastring.o: $(SRC_DIR)/tratastring.cpp $(INC_DIR)/tratastring.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto main.o
# Define o arquivo main.cpp como dependencia.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do executavel tarefa2
# Define os arquivos lista.o e tarefa2.o como dependencias
tarefa2: $(OBJ_DIR)/lista.o $(OBJ_DIR)/tarefa2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto lista.o
# Define o arquivo lista.cpp como dependencia.
$(OBJ_DIR)/lista.o: $(SRC_DIR)/lista.cpp $(INC_DIR)/lista.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto tarefa2.o
# Define o arquivo tarefa2.cpp como dependencia.
$(OBJ_DIR)/tarefa2.o: $(SRC_DIR)/tarefa2.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do executavel teste
# Define os arquivos lista.o e tarefa2.o como dependencias
teste: $(OBJ_DIR)/lista.o $(OBJ_DIR)/teste.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto teste.o
# Define o arquivo teste.cpp como dependencias.
$(OBJ_DIR)/teste.o: $(TST_DIR)/teste.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
