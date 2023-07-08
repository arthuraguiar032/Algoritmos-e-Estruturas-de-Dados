#include <stdio.h>
#include <stdlib.h>

//First In First Out
typedef struct no{
    int dado;
    struct no* prox;
}No;

typedef struct{
    int tamanho;
    No* inicio;
}Fila;

Fila* Fila_init(){
    Fila* fila = malloc(sizeof(Fila));
    if(fila){
        fila->tamanho = 0;
        fila->inicio = NULL;
    }
    return fila;
}

//Insere um elemento no final da fila
void Fila_enqueue(Fila* fila, int dado_ins){
    No* no_insert = malloc(sizeof(No));
    if(!no_insert){
        printf("ERRO AO INSERIR NA FILA!");
        return;
    }

    no_insert->dado = dado_ins;
    no_insert->prox = NULL;
    fila->tamanho++;

    if(!fila->inicio){
        fila->inicio = no_insert;
        return;
    }

    No* aux = fila->inicio;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = no_insert;

}

//Remove e retorna o elemento do início da fila
int Fila_dequeue(Fila* fila){
    if(fila->tamanho==0){
        return 0;
    }
    
    No* aux = fila->inicio;
    int valor = aux->dado;
    fila->inicio = aux->prox;
    free(aux);

    fila->tamanho--;
    return valor;
}

void Fila_delete(Fila** fila){
    while((*fila)->inicio){
        Fila_dequeue(*fila);
    }
    free(*fila);
    *fila = NULL;
}

void Fila_print(Fila* fila){
    if(!fila){
        printf("Fila deletada.\n");
        return;
    }
    if(!fila->inicio){
        printf("Fila vazia.\n");
        return;
    }

    No *atual = fila->inicio;
    printf("Fila: ");
    while (atual){
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

int Fila_isEmpty(Fila* fila){
    return (fila->tamanho==0);
}

//Retorna o elemento do início da fila sem removê-lo
int Fila_front(Fila* fila){
    if(fila->tamanho==0){
        return 0;
    }
    return fila->inicio->dado;
}

//Retorna o elemento no final da fila sem removê-lo
int Fila_back(Fila* fila){
    if(fila->tamanho==0){
        return 0;
    }
    
    No *atual = fila->inicio;
    while (atual->prox){
        atual = atual->prox;
    }
    return atual->dado;
}


int main(void) {
    Fila* fila = Fila_init();

    // Teste Fila_enqueue e Fila_print
    Fila_enqueue(fila, 1);
    Fila_enqueue(fila, 2);
    Fila_enqueue(fila, 3);
    Fila_print(fila); // Saída esperada: Fila: 1 2 3

    // Teste Fila_front
    int front = Fila_front(fila);
    printf("Elemento do início da fila: %d\n", front); // Saída esperada: Elemento do início da fila: 1

    // Teste Fila_back
    int back = Fila_back(fila);
    printf("Elemento do final da fila: %d\n", back); // Saída esperada: Elemento do final da fila: 3

    // Teste Fila_dequeue
    int valor_removido = Fila_dequeue(fila);
    printf("Valor removido da fila: %d\n", valor_removido); // Saída esperada: Valor removido da fila: 1
    Fila_print(fila); // Saída esperada: Fila: 2 3

    // Teste Fila_isEmpty
    int vazia = Fila_isEmpty(fila);
    printf("A fila está vazia? %s\n", vazia ? "Sim" : "Não"); // Saída esperada: A fila está vazia? Não

    // Teste Fila_delete
    Fila_delete(&fila);
    Fila_print(fila); // Saída esperada: Fila deletada

    return 0;
}

