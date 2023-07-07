#include <stdlib.h>
#include <stdio.h>


typedef struct no{
    int dado;
    struct no *proximo;
}No;

typedef struct{
    int tamanho;
    No *inicio;
}ListaLigada;

ListaLigada* Lista_init(){
    ListaLigada* lista = malloc(sizeof(ListaLigada));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

No* Lista_tail(ListaLigada* lista){
    if(!lista->inicio){
        return NULL;
    }

    No* aux = lista->inicio;
    while(aux->proximo!=NULL){
        aux = aux->proximo;
    }
    return aux;
}

void Lista_append(ListaLigada* lista, int dado_insert){
    No* no_insert = malloc(sizeof(No));
    no_insert->proximo = NULL;
    no_insert->dado = dado_insert;
    lista->tamanho++;

    if(!lista->inicio){
        lista->inicio = no_insert;
        return;
    }

    No* ultimo = Lista_tail(lista);
    ultimo->proximo = no_insert;
    return;
}

void Lista_pop(ListaLigada* lista){
    if(!lista->inicio){
        return;
    }
    lista->tamanho--;

    No *fim, *anterior;
    fim = lista->inicio;
    while(fim->proximo!=NULL){
        anterior = fim;
        fim = fim->proximo;
    }
    free(fim);
    anterior->proximo = NULL;
    return;
}

void Lista_delete(ListaLigada** lista) {
    while ((*lista)->tamanho > 0) {
        Lista_pop(*lista);
    }
    free(*lista);
    *lista = NULL;
}

void Lista_print(ListaLigada* lista){
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

int Lista_get(ListaLigada* lista, int index){
    if(lista->tamanho<=index){
        return 0;
    }
    No* aux = lista->inicio;
    for(int i=0; i<index; i++){
        aux = aux->proximo;
    }
    return aux->dado;
}

void Lista_set(ListaLigada* lista, int index, int value){
    if(lista->tamanho<=index){
        return;
    }
    No* aux = lista->inicio;
    for(int i=0; i<index; i++){
        aux = aux->proximo;
    }
    aux->dado = value;
}


int main(void){
    ListaLigada *lista = Lista_init();

    Lista_append(lista, 15);
    Lista_append(lista, 7);
    Lista_append(lista, 38);
    Lista_append(lista, 19);

    printf("O valor do indice %d da lista é: %d\n", 1, Lista_get(lista, 1));

    Lista_print(lista);

    Lista_set(lista, 0, 1);

    Lista_print(lista);

    Lista_pop(lista);
    Lista_pop(lista);

    Lista_print(lista);

    Lista_delete(&lista);
    Lista_print(lista);

    return 0;
}