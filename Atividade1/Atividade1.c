/*
  Arquivo: Atividade1.c
  Autor: Lucas Benicio Lima
  Date: 09/03/21 19:49
  Descricao: Implementacao do algoritmo Programa 3
*/

#include <stdio.h>

int main(){
    int n = 12;
    printf("N = %d\n", n);
    int x, y, z;

    for (x = 1; x <= 9; x++)
    {
        for (y = 1; y <= 9; y++)
        {
            for (z = 1; z <= 9; z++)
            {
                if ((x + y + z == n) && (x != y && x != z && y != z) && (x < y && x < z && y < z))
                {
                    printf("\nx = %d  y = %d  z = %d    valor = %d", x, y, z, ((x*3) + (y*2) + (z*1)));
                }  
            }  
        } 
    }

    printf("\n\nFIM");
}