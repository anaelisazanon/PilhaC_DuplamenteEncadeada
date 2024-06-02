#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    multipilha *mp = criaPilhas(10);
    int index = -1;
    int pilha;
    int obj_out;
    int obj_in;
    int ctz;
    int tamanho;
    while (index != 0){
        printf("Digite uma opção: \n");
        printf("(1)Adicionar elemento nas pilhas\n");
        printf("(2)Remover elemento nas pilhas\n");
        printf("(3)Ver elemento do topo das pilhas\n");
        printf("(4)Ver o tamanho da pilha\n");
        printf("(5)Reiniciar a pilha\n");
        printf("(6)Apagar pilha\n");
        printf("(7)Criar pilha\n");
        printf("(0)Sair\n");
        scanf("%i", &index);
        switch (index){
        case 0:
            printf("Saindo...\n");
	    if(mp == NULL){
	    return 0;
	    }
            destroiPilhas(&mp);
            return 0;
        break;
        case 1:
            if(mp == NULL){
                printf("Crie uma pilha primeiro!\n");
                break;
            }
            printf("Digite qual das duas pilhas você quer acessar(1|2):\n");
            scanf("%i", &pilha);
            printf("Qual numero você quer colocar na pilha?\n");
            scanf("%i", &obj_in);
            empilha(obj_in, pilha, mp);
        break;
        case 2:
            if(mp == NULL){
                printf("Crie uma pilha primeiro!\n");
                break;
            }
            printf("Digite qual das duas pilhas você quer retirar um objeto(1|2):\n");
            scanf("%i", &pilha);
            obj_out = desempilha(pilha, mp);
            if(obj_out == 0){
                printf("A pilha esta vazia!\n");
                break;
            }
            printf("O objeto retirado: %i\n", obj_out);
        break;
        case 3:
            if(mp == NULL){
                printf("Crie uma pilha primeiro!\n");
                break;
            }
            printf("Digite qual das duas pilhas você quer buscar o topo(1|2):\n");
            scanf("%i", &pilha);
            int obj_out = buscaTopo(pilha, mp);
            if(obj_out == 0){
                printf("A pilha esta vazia!\n");
                break;
            }
            printf("O objeto no topo da pilha: %i\n", obj_out);
        break;
        case 4:
            if(mp == NULL){
                printf("Crie uma pilha primeiro!\n");
                break;
            }
            printf("Digite qual das duas pilhas você quer ver o tamanho(1|2):\n");
            scanf("%i", &pilha);
            int tam = tamanhoPilha(pilha, mp);
            printf("A pilha %i tem tamanho %i\n", pilha, tam);
        break;
        case 5:
            if(mp == NULL){
                printf("Crie uma pilha primeiro!\n");
                break;
            }
            printf("Digite qual das duas pilhas você quer reiniciar(1|2):\n");
            scanf("%i", &pilha);
            reiniciaPilha(pilha, mp);
        break;
        case 6:
            if(mp == NULL){
                printf("Crie uma pilha primeiro!\n");
                break;
            }
            printf("Tem certeza que quer apagar as pilhas?(sim - 0|Não - 1)\n");
            scanf("%i", &ctz);
            if(ctz){
                break;
            }
            printf("Destruindo pilha...\n");
            printf("3...\n");
            printf("2...\n");
            printf("1...\n");
            destroiPilhas(&mp);
        break;
        case 7:
            if(mp == NULL){
                printf("Qual o tamanho das pilhas?\n");
                scanf("%i", &tamanho);
                mp = criaPilhas(tamanho);
            }else{
                printf("Caso você crie uma nova está existente será apagada, tem certeza que quer continuar?(sim - 0|Não - 1)\n");
                scanf("%i", &ctz);
                if(ctz){
                    break;
                }
                destroiPilhas(&mp);
                printf("Qual o tamanho das pilhas?\n");
                scanf("%i", &tamanho);
                mp = criaPilhas(tamanho);
            }
        break;
        default:
        printf("Opção invalida\n");
            break;
        }
    }
    
}

