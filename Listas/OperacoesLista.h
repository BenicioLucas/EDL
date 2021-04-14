/*
  Arquivo: OperacoesLista.c
  Autor: Lucas Benicio Lima
  Date: 22/03/21 20:50
  Descrição: Esse arquivo implementa 8 funcoes de operacoes em listas.
             A estrutura de dados definida a seguir comporta uma lista
             de numeros inteiros positivos, ordenada em ordem crescente
             e nao contem duplicatas.
*/

#include <stdio.h>
#include "Booleano.h"

#define Fantasma (-1)
#define Maximo 1000

typedef struct {
    int tamanho;
    int vetor[Maximo];
} Lista;


Lista criarLista();

int obterTamanho(Lista);

bool verificarListaVazia(Lista);

int obterElemento(Lista, int);

int buscarElemento(Lista, int);

void mostrarLista(Lista);

Lista inserirLista(Lista, int);

Lista removerElemento(Lista, int);


Lista criarLista() {
    Lista L;
    L.tamanho = 0;
    return L;
}

int obterTamanho(Lista L) {
    int tam;
    tam = L.tamanho;
    return tam;
}

bool verificarListaVazia(Lista L) {
    bool vazia;
    if (L.tamanho == 0) {
        vazia = TRUE;
    } else {
        vazia = FALSE;
    }
    return vazia;
}

int obterElemento(Lista L, int posicao) {
    int elemento = Fantasma;

    if (posicao > 0 && posicao <= L.tamanho) {
        elemento = L.vetor[posicao];
    }
    return elemento;
}

int buscarElemento(Lista L, int num) {
    int inicio = 1;
    int fim = L.tamanho;
    int meio;
    int posicao = Fantasma;

    if (L.tamanho != 0) {
        while (inicio <= fim) {
            meio = (inicio + fim) / 2;
            if (L.vetor[meio] == num) {
                posicao = meio;
            }
            if (L.vetor[meio] < num) {
                inicio = meio + 1;
            } else {
                fim = meio - 1;
            }
        }
    }
    return posicao;
}

void mostrarLista(Lista L) {
    int i, tam;
    tam = L.tamanho;

    if (tam == 0) {
        printf(" \n lista vazia \n");
    } else {
        printf("\n");
        for (i = 1; i <= tam; i++) {
            printf(" %d", L.vetor[i]);
        }
    }
    printf("\n");
}

Lista inserirLista(Lista L, int item) {
    int tam = L.tamanho;
    int k;
    int j;
    int i;

    if (tam > 0) {
        i = 1;
        while (item != L.vetor[i] && i < L.tamanho) { // Ver se tem duplicata
            i++;
        }
        if (item != L.vetor[i]) { // if nao tem duplicata
            k = 1;
            while (item > L.vetor[k] && k < tam) { // busca posicao de insercao
                k++;
            }
            if (item > L.vetor[k]) {
                L.vetor[k + 1] = item;
                L.tamanho++;
            } else {
                for (j = tam; k <= j; j--) {
                    L.vetor[j + 1] = L.vetor[j];
                }
                L.vetor[k] = item;
                L.tamanho++;
            }
        }
    } else { // A lista esta vazia
        L.vetor[1] = item;
        L.tamanho++;
    }
    return L;
}

Lista removerElemento(Lista L, int posicao) {
    int x;
    if (posicao > 0 && posicao <= L.tamanho) {
        for (x = posicao; x < L.tamanho; x++) {
            L.vetor[x] = L.vetor[x + 1];
        }
        L.tamanho--;
    }
    return L;
}