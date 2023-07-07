#include <stdlib.h>
#include <stdio.h>

//Last In First Out
typedef struct no{
    int dado;
    struct no *proximo;
}No;

typedef struct{
    No *topo;
}Pilha;


Pilha* Pilha_init(){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int Pilha_isEmpty(Pilha* pilha){
    return (pilha->topo==NULL);
}

void Pilha_push(Pilha* pilha, int valor){
    No* no = malloc(sizeof(No));
    no->proximo = NULL;
    no->dado = valor;

    if(Pilha_isEmpty(pilha)){
        pilha->topo = no;
        return;
    }
    no->proximo = pilha->topo;
    pilha->topo = no;
}

int Pilha_top(Pilha* pilha){
    return pilha->topo->dado;
}

int Pilha_pop(Pilha* pilha){
    if(Pilha_isEmpty(pilha)){
        return 0;
    }
    No* aux = pilha->topo;
    pilha->topo = aux->proximo;
    int valor = aux->dado;
    free(aux);
    return valor;
}

void Pilha_delete(Pilha** pilha){
    while((*pilha)->topo){
        Pilha_pop(*pilha);
    }
    free(*pilha);
    *pilha = NULL;
}

void Pilha_print(Pilha* pilha){
    if (!pilha) {
        printf("Pilha deletada.\n");
        return;
    }
    if(!pilha->topo){
        printf("Lista vazia.\n");
        return;
    }

    No *atual = pilha->topo;
    printf("Pilha: ");
    while (atual != NULL){
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}



int main(void){
    Pilha* pilha = Pilha_init();

    Pilha_push(pilha, 1);
    Pilha_push(pilha, 2);
    Pilha_push(pilha, 3);
    Pilha_push(pilha, 4);

    Pilha_print(pilha); // Saída esperada: Pilha: 4 3 2 1

    int valor_topo = Pilha_top(pilha);
    printf("Topo da pilha: %d\n", valor_topo); // Saída esperada: Topo da pilha: 4

    int valor_removido = Pilha_pop(pilha);
    printf("Valor removido: %d\n", valor_removido); // Saída esperada: Valor removido: 4

    Pilha_print(pilha); // Saída esperada: Pilha: 3 2 1

    Pilha_delete(&pilha);

    Pilha_print(pilha);

    return 0;
}