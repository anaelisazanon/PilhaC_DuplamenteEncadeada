typedef struct pilha{
    int topo1;
    int topo2;
    int tamVet;
    int *vet;
}multipilha;
  
multipilha *criaPilhas(int tam);

void destroiPilhas( multipilha **mult);

void reiniciaPilha(int pilha, multipilha *mult);

int empilha(int obj, int pilha,  multipilha *mult);

int desempilha(int pilha,  multipilha *mult);

int testeCheia(multipilha *mult);

int testeVazio(int pilha, multipilha *mult);

int buscaTopo(int pilha,  multipilha *mult);

int tamanhoPilha(int pilha ,multipilha *mult);


