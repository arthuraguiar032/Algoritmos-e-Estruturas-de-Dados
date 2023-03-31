#include "utils.h"

void troca(int vetor[], int i){
	int aux = vetor[i];
	vetor[i] = vetor[i+1];
	vetor[i+1] = aux;
}

void bubble_sort(int vetor[], int tamanho){
	for(int i=0; i<tamanho-1; i++){
		for(int j=0; j<tamanho-1-i; j++){
			if(vetor[j] > vetor[j+1]){
				troca(vetor, j);
			}
		}
	}
}

int main(void){
	int tamanho = 10;
	int vetor[tamanho];

	preenche_vetor(vetor, tamanho);
	imprime_vetor(vetor, tamanho);
	bubble_sort(vetor, tamanho);
	imprime_vetor(vetor, tamanho);


	return 0;
}