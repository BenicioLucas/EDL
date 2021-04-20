/* IMPLEMENTAÇÕES DE PILHA */
/*
  Arquivo: Pilha.c
  Autor: Lucas Benício Lima
*/

#include <stdio.h>
#include<stdlib.h>

#include "Booleano.h"
#define Max 6
#define ghost 36
#define sinal 0

typedef struct {
    int topo;
    char vetor[Max];
} Pilha;

/* construtores */
void criarPilha(Pilha *);
/* acesso */
char acessarPilha(Pilha *);
bool PilhaVazia(Pilha *);

void mostrarPilha(Pilha *);

/* manipulação */
void pushPilha(Pilha *, char);
void popPilha(Pilha *);

void copiarPilha(Pilha *, Pilha *);
void inverterPilha (Pilha * pilha);
void editar(int, Pilha *, Pilha *, char );

int main(){
	Pilha A;
	//bool vazia;
	char ch;
	/*int j;
	criarPilha(&A); 
	mostrarPilha(&A);
	vazia = PilhaVazia(&A);
	printf("\n vazia = %d \n",vazia);
	for(j=1;j<=5;j++){	
		ch = j+64; 	
		pushPilha(&A,ch);
	}
	criarPilha(&B);
	for(j=1;j<=5;j++){	
		ch = j+69; 	
		pushPilha(&B,ch);
	}
	mostrarPilha(&A);
	copiarPilha(&A, &B);
	mostrarPilha(&B);

	for(j=1; j<=5; j++){ 	
		ch = acessarPilha(&A); 
		printf("\n chTopo = %c ",ch); 
		popPilha(&A); 
		mostrarPilha(&A);
	}*/
	criarPilha(&A); 
	for(int j=1;j<=5;j++){	
		ch = j+64; 	
		pushPilha(&A,ch);
	}
	mostrarPilha(&A);

	printf("\n FIM  \n");
	return 0;
}

void mostrarPilha(Pilha * ap){
	int k,n;	
	if (ap->topo == sinal) { 
		printf("\n pilha vazia \n");
	} 
	else {
		printf("\n");
		n = ap->topo;
		for(k = n; k >= 1; k--){
			printf(" %d - %c \n",k, ap->vetor[k]);
		}
	}
}

void criarPilha(Pilha *ap){
	ap->topo = sinal;
    ap->vetor[0] = Max-1;
}

char acessarPilha(Pilha *ap){
    int k;
    char y;
    if (ap->topo == sinal) y = ghost;
    else {k = ap->topo; y = ap->vetor[k];}
    return y;
}     

bool PilhaVazia(Pilha *ap){
    bool vazia;
    if (ap->topo == sinal) vazia = TRUE; else vazia = FALSE;
    return vazia;
}

void pushPilha(Pilha *ap, char ch){
    int k;
    if(ap->topo != Max-1){
        k = ap->topo + 1;
        ap->vetor[k] = ch;
        ap->topo = k;
    }
}

void popPilha(Pilha *ap){
    int k;
    if (ap->topo != sinal){
        k = ap->topo;
        ap->topo = k-1;
    }                   
}

void copiarPilha(Pilha * ap1, Pilha * ap2) {
    // Cria pilha auxiliar
    Pilha auxiliar;
    criarPilha(&auxiliar);
    char c;

    // pop na ap1 e push na auxiliar
    while (ap1->topo != sinal) {
        c = acessarPilha(ap1);
        pushPilha(&auxiliar, c);
        popPilha(ap1);
    }
    // push em ap1, push em ap2 e pop em auxiliar
    while (auxiliar.topo != sinal) {
        c = acessarPilha(&auxiliar);
        pushPilha(ap2, c);
        pushPilha(ap1, c);
        popPilha(&auxiliar);
    }
    // esvazia pilha auxiliar
    while (auxiliar.topo != sinal) {
        popPilha(&auxiliar);
    }

}

void inverterPilha (Pilha * pilha){
    Pilha pilhaAuxiliar1;
    Pilha pilhaAuxiliar2;
    criarPilha(&pilhaAuxiliar1);
    criarPilha(&pilhaAuxiliar2);
    char caracatere;


    while (pilha->topo != sinal) {
        caracatere = acessarPilha(pilha);
        pushPilha(&pilhaAuxiliar1, caracatere);
        popPilha(pilha);
    }


    while (pilhaAuxiliar1.topo != sinal) {
        caracatere = acessarPilha(&pilhaAuxiliar1);
        pushPilha(&pilhaAuxiliar2, caracatere);
        popPilha(&pilhaAuxiliar1);
    }

    while (pilhaAuxiliar2.topo != sinal) {
        caracatere = acessarPilha(&pilhaAuxiliar2);
        pushPilha(pilha, caracatere);
        popPilha(&pilhaAuxiliar2);
    }

}

void editar(int opcao, Pilha * ap1, Pilha * ap2, char inserir){
	bool vazia;
	
	switch (opcao){
	// DELETE
	case 1:
		popPilha(ap2);
		break;

	// INSERT
	case 2:
		pushPilha(ap1, inserir);
		break;

	// BACK
	case 3:
		popPilha(ap1);
		break;

	// START
	case 4:
		copiarPilha(ap1, ap2);
		vazia = PilhaVazia(ap1);
		while (vazia != TRUE){
			popPilha(ap1);
			vazia = PilhaVazia(ap1);
		}
		break;

	// END
	case 5:
		copiarPilha(ap2, ap1);
		vazia = PilhaVazia(ap2);
		while (vazia != TRUE){
			popPilha(ap2);
			vazia = PilhaVazia(ap2);
		}
		break;
	
	default:
		break;
	}

}