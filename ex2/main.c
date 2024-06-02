#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "arq.h"

int main(int argc, char *argv[]){
     if (argc < 2) {
        printf("[ E ]: Forneca o caminho completo do arquivo por meio do parametro. \n");
        return 0;
    }

    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) {
        printf("[ E ]: Arquivo nao encontrado. \n");
        return 0;
    }
    pilha *html = cria();
    char atual[50];
    info base;
    info lixo;
    
    while (strcmp(atual, "</html>")){
        
        strcpy(base.palavra, "\0");
    
        fscanf(arquivo, "%s", atual);
        char a = atual[0];
        char b = atual[1];

        int i = 0;
        while (!(atual[i] == '>' || atual[i] == '\0')){
            i++;
        }

        info excecao = base;
        int j = 0;
        for(j = 1; j<i;j++){
            excecao.palavra[j-1] = atual[j];
        }
        excecao.palavra[j-1] = '\0';
        
        if(strcmp(excecao.palavra, "meta") == 0 || strcmp(excecao.palavra, "br") == 0 || strcmp(excecao.palavra, "img") == 0 || strcmp(excecao.palavra, "input") == 0 || strcmp(excecao.palavra, "frame") == 0 || strcmp(excecao.palavra, "!DOCTYPE") == 0 ){
            continue;
        }
        info topo;
        busca(&topo, html);
        if(strcmp(topo.palavra, "!--") == 0 && strcmp(atual, "-->") != 0){
            continue;
        }else if(strcmp(topo.palavra, "!--") == 0 && strcmp(atual, "-->") == 0){
            desempilha(&lixo ,html);
            continue;
        }

        if(a == '<' && b != '/' ){
            info temp = base;
            for(j = 1; j < i; j++ ){
                temp.palavra[j-1] = atual[j];
            }
            temp.palavra[j-1] = '\0';
            empilha(&temp, html);
        }

        if(a == '<' && b == '/' ){
            info temp1 = base;
            info aux = base;
            for(int j = 2; j < i; j++ ){
                temp1.palavra[j-2] = atual[j];
            }
            temp1.palavra[j-2] = '\0';


            busca(&aux, html);
            if(strcmp(temp1.palavra, aux.palavra) == 0){
                desempilha(&aux, html);
            }else{
                printf("ERRO: esperado %s, recebido %s\n", aux.palavra, temp1.palavra);
                return 0;
            }
        }

    }
    printf("Certo\n");
    
    return 0;
}
