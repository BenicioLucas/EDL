/*
  Arquivo: AtividadeSorting.c
  Autor: Lucas Benicio Lima
  Date: 12/04/2021 20:00
  Descrição: Esse programa compara o tempo de execução de uma mesma lista (em segundos) dos
             três algoritmos de ordenação, considerando uma lista com N números aleatórios.
*/

#include <time.h>
#include <stdio.h>
#include "TipoLista.h"

int main() {
    double dBubble, dSelection, dInsertion;
    time_t inicioBubble, fimBubble;        // o tipo time_t está definido em time.h
    time_t inicioSelection, fimSelection;
    time_t inicioInsertion, fimInsertion;
    ListaInt a, b;

    // --------------- Construcao lista aleatoria -----------------
    int M;                    // M é o limite da faixa de números aleatórios  [1..M]
    M = 5000;
    printf(" \nConstruir uma lista com inteiros positivos na faixa [1..%d] ", M);
    printf("\nTamanho da lista = %d itens", Max - 1);
    // o tamanho da lista é determinado por Max, definido no "TipoListaInteiro.h"
    printf(" \n\n\n");
    construirListaAleatoria(&a, M, Max - 1);
    mostrarLista(&a);
    printf("-------------------------------------------------------------------\n\n");

    // --------------- Bubble sort -----------------
    printf(" \n\n");
    printf("    BubbleSort - ");
    inicioBubble = time(NULL);       //tempo corrente em uma variável do tipo time_t
    ordenarListaCrescenteB(&a);
    fimBubble = time(NULL);
    dBubble = difftime(fimBubble, inicioBubble);
    printf("Tempo de execucao = %6.4f segundos\n", dBubble);
    printf("\n\n");
    mostrarLista(&a);
    printf("-------------------------------------------------------------------\n\n");

    // --------------- Selection sort -----------------
    printf(" \n\n");
    printf("    SelectSort - ");
    inicioSelection = time(NULL);       //tempo corrente em uma variável do tipo time_t
    ordenarListaCrescenteB(&a);
    fimSelection = time(NULL);
    dSelection = difftime(fimSelection, inicioSelection);
    printf("Tempo de execucao = %6.4f segundos\n", dSelection);
    printf("\n\n");
    mostrarLista(&a);
    printf("-------------------------------------------------------------------\n\n");

    // --------------- Insertion sort -----------------
    printf(" \n\n");
    printf("    InsertionSort - ");
    inicioInsertion = time(NULL);       //tempo corrente em uma variável do tipo time_t
    ordenarListaCrescenteB(&a);
    fimInsertion = time(NULL);
    dInsertion = difftime(fimInsertion, inicioInsertion);
    printf("Tempo de execucao = %6.4f segundos\n", dInsertion);
    printf("\n\n");
    mostrarLista(&a);

    printf("\n\nTempos de execucao:\n");
    printf("Tempo de execucao Bubble sort = %6.4f segundos\n", dBubble);
    printf("Tempo de execucao Selection sort = %6.4f segundos\n", dSelection);
    printf("Tempo de execucao Insertion sort = %6.4f segundos\n", dInsertion);
    printf(" \n\n  FIM \n ");
    return 0;
}
