#include "utils.h"

void recursao(long int vetor[], long int tamanho, long int index){
    if(index == tamanho-1){
        return;
    }
    long int menor = index;
    for(long int i=index; i<tamanho; i++){
        if(vetor[i]<vetor[menor]){
            menor = i;
        }
    }
    troca(vetor, index, menor);
    recursao(vetor, tamanho, index+1);
}

void selection_sort(long int vetor[], long int tamanho){
    recursao(vetor, tamanho, 0);
}


int main(void){
    long int tamanho = 20;
    long int vetor[tamanho];

	preenche_vetor(vetor, tamanho);
	imprime_vetor(vetor, tamanho);
	selection_sort(vetor, tamanho);
	imprime_vetor(vetor, tamanho);

}