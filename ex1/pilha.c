#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
//Nosso NULL é o 0, arrumar as funçoes para não receber 0
multipilha *criaPilhas(int tam){
    multipilha *mult = NULL;
    if(tam >0){
        mult = malloc(sizeof(multipilha));
        mult->tamVet = tam;
        mult->topo1 = -1;
        mult->topo2 = tam;
        mult->vet = malloc(sizeof(int)*tam);
    }
    return mult;
}

void destroiPilhas( multipilha **mult){
    free((*mult)->vet);
    free(*mult);
    *mult = NULL;
}

void reiniciaPilha(int pilha ,multipilha *mult){
    switch(pilha){
        case 1:
            mult->topo1 = -1;
        break;
        case 2:
            mult-> topo2 = mult->tamVet;
        break;
    }
}

//Adicionei a condição em que o 0 não pode ser colocado
int empilha(int obj, int pilha,  multipilha *mult){
    if(testeCheia(mult)){
        printf("Pilha cheia!\n");
        return 0; 
    }
    if(obj == 0){
        printf("Objeto invalido!\n");
        return 0;
    }
    switch(pilha){
        case 1:
            mult->topo1++;
            mult->vet[mult->topo1] = obj;
            return 1;
        break;

        case 2:
            mult->topo2--;
            mult->vet[mult->topo2] = obj;
            return 1;
        break;
    }
    printf("O objeto foi colocado na pilha!\n");
}

int desempilha(int pilha,  multipilha *mult){
    int obj;
    switch(pilha){
        case 1:
            if (testeVazio(1, mult)){
                return 0;
            }
            obj = mult->vet[mult->topo1];
            mult->topo1--;
            return obj;
        break;
        case 2:
        if (testeVazio(2, mult)){
                return 0;
            }
            obj = mult->vet[mult->topo2];
            mult->topo2++;            
            return obj;
        break;
    }
}


int testeCheia(multipilha *mult){
     return(mult->topo1)+1 == mult->topo2 || mult->topo1 == (mult->topo2)-1; 
}

int testeVazio(int pilha ,multipilha *mult){
    switch(pilha){
        case 1:
            return (mult->topo1 == -1);
        break;
        case 2:
            return (mult->topo2 == mult->tamVet);
        break;
    }
}
//coloquei o caso em que a pilha está vazia
int buscaTopo(int pilha,  multipilha *mult){
    switch(pilha){
        case 1:
            if (testeVazio(1, mult)){
                return 0;
            }
            return mult->vet[mult->topo1];
        break;
        case 2:
            if (testeVazio(2, mult)){
                return 0;
            }
            return mult->vet[mult->topo2];
        break;
    }
}

int tamanhoPilha(int pilha ,multipilha *mult){
    int cont = 0;
    switch(pilha){
        case 1:
            return mult->topo1 + 1;
        break;
        case 2:
            return mult->tamVet - mult->topo2;
        break;
    }
}
