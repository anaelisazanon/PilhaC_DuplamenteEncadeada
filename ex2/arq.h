#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0

// Escolhemos essa implementação da pilha encadeada, pois não teremos que lidar com o limite de tamanho que ocorre quando ultilizamos em um vetor

typedef struct info{ 
    char palavra[50];
}info;

struct noPSE{	
	info dados;
	struct noPSE *abaixo;
};	
typedef struct pilha{ 
	struct noPSE *topo;
	int tamPilha;
} pilha;

struct pilha * cria(void);
int vazia(struct pilha *pil);
int empilha(info *reg, struct pilha *pil);
int desempilha(info *reg, struct pilha *pil);
int busca(info *reg, struct pilha *pil);
void reinicia(struct pilha *pil);
struct pilha *destroi(struct pilha *pil);
