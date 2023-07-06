#include "utils.h"

int particiona(long int vetor[], long int inicio, long int fim){
	long int pivo = vetor[fim];
	long int indice = inicio;

	for(long int i=inicio; i<fim; i++){
		if(vetor[i]<=pivo){
			troca(vetor, i, indice);
			indice++;
		}
	}

	if(pivo<=vetor[indice]){
		troca(vetor, indice, fim);
	}

	return indice;
}

void quick_sort(long int vetor[], long int inicio, long int fim){
	if (fim>inicio){
		int pivo = particiona(vetor, inicio, fim);
		quick_sort(vetor, inicio, pivo-1);
		quick_sort(vetor, pivo+1, fim);
	}
}

int main(void){
	long int tamanho = 10;
	long int vetor[tamanho];

	preenche_vetor(vetor, tamanho);
	imprime_vetor(vetor, tamanho);
	quick_sort(vetor, 0, tamanho-1);
	imprime_vetor(vetor, tamanho);

	return 0;
}