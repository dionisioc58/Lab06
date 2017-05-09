#ifndef PILHA_H
    #define PILHA_H

    template<typename T>
    class Pilha {
    private:
        T *dados;
        int qtde;
        int max;
    public:
        Pilha(int tam);
        void Push(T val);
        T Pop();
        bool Vazio();
        bool Cheio();
    };

    template<typename T>
    Pilha<T>::Pilha(int tam) {
        dados = new T[tam];
        max = tam;
        qtde = 0;
    }

    template<typename T>
    void Pilha<T>::Push(T val) {
        if(!Cheio())
            dados[qtde++] = val;
    }
    
    template<typename T>
    T Pilha<T>::Pop() {
        if(!Vazio())
            return dados[--qtde];
        else
            return dados[0];
    }

    template<typename T>
    bool Pilha<T>::Vazio() {
        return (qtde == 0);
    }

    template<typename T>
    bool Pilha<T>::Cheio() {
        return (qtde == max);
    }

#endif