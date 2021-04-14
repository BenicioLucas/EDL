#include <stdio.h>

#ifndef _Elemento_h
        #define _Elemento_h

typedef struct{
        char * nome;
        char chave;
        int valor;
}TipoElemento;

TipoElemento criarElemento(char *, char, int);
TipoElemento criarNovoElemento();
TipoElemento criarFantasma();
void setNome(TipoElemento *, char *);
void setChave(TipoElemento *, char);
void setValor(TipoElemento *, int);
char* getNome(TipoElemento );
char getChave(TipoElemento );
int getValor(TipoElemento );
void mostrarElemento(TipoElemento);

TipoElemento criarElemento(char *s, char ch, int pri){
             TipoElemento reg;
             reg.nome = s; reg.chave = ch, reg.valor = pri;
             return reg;
}

TipoElemento criarNovoElemento(){
             TipoElemento novo;
             novo.nome = "MARIA"; novo.chave = 'Z'; novo.valor = 13;
             return novo;
}

TipoElemento criarFantasma(){
             TipoElemento f;
             f.nome = "fantasma"; f.chave = '0'; f.valor = -1;
             return f;
}

void setNome(TipoElemento *reg, char *s){
        reg->nome = s;
}

void setChave(TipoElemento *reg, char ch){
     reg->chave = ch;
}
void setValor(TipoElemento *reg, int prior){
     reg->valor = prior;
}
 
char * getNome(TipoElemento reg){
     char * s;
     s = reg.nome;
     return s;
}
            
char getChave(TipoElemento reg){
     char ch;
     ch = reg.chave;
     return ch;
}

int getValor(TipoElemento reg){
     int v;
     v = reg.valor;
     return v;
}

void mostrarElemento(TipoElemento reg){
     printf(" nome = %s   ",reg.nome);
     printf(" chave = %c   ", reg.chave);
     printf(" prioridade = %d \n", reg.valor);
   //  printf("\n");
}
#endif
