/* IMPLEMENTA��ES DE PILHA */
/*
  Arquivo: PilhaModelo1.c
  Autor: Lisbete Madsen Barbosa
  Date: 11/10/09 10:34
  Descri��o: Define e implementa o tipo de dados Pilha
  definido no modelo 1.
*/

#include <stdio.h>
#include "Booleano.h"
#define Max 5
#define ghost 36
#define sinal 0

typedef struct {
    int topo;
    char vetor[Max];
} Pilha;

/* construtores */
Pilha criarPilha();
/* acesso */
char acessarPilha(Pilha);
bool PilhaVazia(Pilha);

void mostrarPilha(Pilha);

/* manipula��o */
Pilha pushPilha(Pilha, char);
Pilha popPilha(Pilha);

int main(){
	Pilha A;
	bool vazia;
	char ch;
	int j;
	A = criarPilha(A); 
    mostrarPilha(A);
	vazia = PilhaVazia(A);
	printf("\n vazia = %d \n",vazia);
	for(j=1;j<=5;j++){	
		ch = j+64; 	A = pushPilha(A,ch);
	}
	mostrarPilha(A);
	for(j=1; j<=5; j++){ 	
		ch = acessarPilha(A); printf("\n ch = %c \n",ch); A = popPilha(A); mostrarPilha(A);
	}
	
	
	printf("\n FIM  \n");
	return 0;
}

void mostrarPilha(Pilha S){
	int k,n;	
	if (S.topo == sinal) { 
		printf("\n pilha vazia \n");
	} 
	else {
		printf("\n");
		n = S.topo;
		for(k = n; k >= 1; k--){
			printf(" %d - %c \n",k, S.vetor[k]);
		}
	}
}

Pilha criarPilha(Pilha S){
    S.topo = sinal;
    S.vetor[0] = Max-1;
}

char acessarPilha(Pilha S){
    int k;
    char y;
    if (S.topo == sinal) y = ghost;
    else {k = S.topo; y = S.vetor[k];}
    return y;
}     

bool PilhaVazia(Pilha S){
    bool vazia;
    if (S.topo == sinal) vazia = TRUE; else vazia = FALSE;
    return vazia;
}

Pilha pushPilha(Pilha S, char ch){
    int k;
    if(S.topo != Max-1){
        k = S.topo + 1;
        S.vetor[k] = ch;
        S.topo = k;
    }
    return S;
}

Pilha popPilha(Pilha S){
    int k;
    if (S.topo != sinal){
        k = S.topo;
        S.topo = k-1;
    }        
	return S;           
}

