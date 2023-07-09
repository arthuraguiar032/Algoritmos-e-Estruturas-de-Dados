#include "utils.h"

void insertion_sort(long int vetor[], long int tamanho){
    for(long int i = 1; i < tamanho; i++){
        long int chave = vetor[i];
        long int j = i - 1;
        
        while(j >= 0 && vetor[j] > chave){
            vetor[j+1] = vetor[j];
            j--;
        }
        
        vetor[j+1] = chave;
    }
}

int main(void){
    long int tamanho = 20;
    long int vetor[tamanho];

	preenche_vetor(vetor, tamanho);
	imprime_vetor(vetor, tamanho);
	insertion_sort(vetor, tamanho);
	imprime_vetor(vetor, tamanho);
}