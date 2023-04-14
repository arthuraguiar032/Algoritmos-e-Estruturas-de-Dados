#include "utils.h"

int particiona(int vetor[], int inicio, int fim){
	int pivo = vetor[fim];
	int indice = inicio;

	for(int i=inicio; i<fim; i++){
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

void quick_sort(int vetor[], int inicio, int fim){
	if (fim>inicio){
		int pivo = particiona(vetor, inicio, fim);
		quick_sort(vetor, inicio, pivo-1);
		quick_sort(vetor, pivo+1, fim);
	}
}

int main(void){
	int tamanho = 500;
	int vetor[tamanho];

	preenche_vetor(vetor, tamanho);
	imprime_vetor(vetor, tamanho);
	quick_sort(vetor, 0, tamanho-1);
	imprime_vetor(vetor, tamanho);

	return 0;
}