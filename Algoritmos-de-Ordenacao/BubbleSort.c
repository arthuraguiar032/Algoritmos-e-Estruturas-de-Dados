#include "utils.h"

void bubble_sort(long int vetor[], long int tamanho){
	for(long int i=0; i<tamanho-1; i++){
		for(long int j=0; j<tamanho-1-i; j++){
			if(vetor[j] > vetor[j+1]){
				troca(vetor, j, j+1);
			}
		}
	}
}

int main(void){
	long int tamanho = 10;
	long int vetor[tamanho];

	preenche_vetor(vetor, tamanho);
	imprime_vetor(vetor, tamanho);
	bubble_sort(vetor, tamanho);
	imprime_vetor(vetor, tamanho);

	return 0;
}