#include <stdlib.h>
#include <stdio.h>


typedef struct no{
    int dado;
    struct no *proximo;
    struct no *anterior;
}No;

typedef struct{
    int tamanho;
    No *inicio;
    No *fim;
}ListaDupla;

ListaDupla* Lista_init(){
    ListaDupla* lista = malloc(sizeof(ListaDupla));
    
    if(!lista){
        printf("Erro ao alocar a lista.\n");
        return NULL;
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

No* Lista_tail(ListaDupla* lista){
    if(lista->tamanho == 0){
        return NULL;
    }
    return lista->fim;
}

void Lista_append(ListaDupla* lista, int dado_insert){
    No* no_insert = malloc(sizeof(No));
    if(!no_insert){
        printf("Erro ao inserir na lista.");
        return;
    }
    lista->tamanho++;

    no_insert->proximo = NULL;
    no_insert->anterior = NULL;
    no_insert->dado = dado_insert;

    if(!lista->inicio){
        lista->inicio = no_insert;
        return;
    }

    No* ultimo = Lista_tail(lista);
    no_insert->anterior = ultimo;
    ultimo->proximo = no_insert;
    return;
}

int Lista_pop(ListaDupla* lista){
    if(!lista->inicio){
        return 0;
    }
    lista->tamanho--;

    No *ultimo = Lista_tail(lista);
    int valor = ultimo->dado;

    if(lista->tamanho == 1){
        lista->inicio = NULL;
        free(ultimo);
        return valor;
    }

    No *penultimo = ultimo->anterior;
    penultimo->proximo = NULL;
    free(ultimo);
    return valor;
}

void Lista_delete(ListaDupla** lista) {
    while ((*lista)->tamanho > 0) {
        Lista_pop(*lista);
    }
    free(*lista);
    *lista = NULL;
}

void Lista_print(ListaDupla* lista){
    if (!lista) {
        printf("Lista deletada.\n");
        return;
    }
    if(!lista->inicio){
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->inicio;
    printf("Lista: ");
    while (atual != NULL && lista->inicio != NULL){
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

int Lista_get(ListaDupla* lista, int index){
    if(lista->tamanho<=index){
        return 0;
    }
    No* aux = lista->inicio;
    for(int i=0; i<index; i++){
        aux = aux->proximo;
    }
    return aux->dado;
}

void Lista_set(ListaDupla* lista, int index, int value){
    if(lista->tamanho<=index){
        return;
    }
    No* aux = lista->inicio;
    for(int i=0; i<index; i++){
        aux = aux->proximo;
    }
    aux->dado = value;
}


int main(void) {
    printf("Aqui");
    ListaDupla* lista = Lista_init();
    printf("Aqui");
    // Teste Lista_append e Lista_print
    Lista_append(lista, 1);
    Lista_append(lista, 2);
    Lista_append(lista, 3);
    printf("Aqui");
    Lista_print(lista); // Saída esperada: Lista: 1 2 3

    // Teste Lista_pop e Lista_print
    int valor_removido = Lista_pop(lista);
    printf("Valor removido: %d\n", valor_removido); // Saída esperada: Valor removido: 3
    Lista_print(lista); // Saída esperada: Lista: 1 2

    // Teste Lista_get
    int valor = Lista_get(lista, 0);
    printf("Valor no índice 0: %d\n", valor); // Saída esperada: Valor no índice 0: 1

    // Teste Lista_set e Lista_print
    Lista_set(lista, 1, 5);
    Lista_print(lista); // Saída esperada: Lista: 1 5

    // Teste Lista_delete
    Lista_delete(&lista);
    Lista_print(lista); // Saída esperada: Lista deletada

    return 0;
}
