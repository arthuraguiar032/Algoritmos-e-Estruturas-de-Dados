#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"


void preenche_vetor(int vetor[], int tamanho){
	srand(time(NULL));

	for(int i=0; i<tamanho; i++){
		vetor[i] = rand() % 1001;
	}
}

void imprime_vetor(int vetor[], int tamanho){
	printf("\n[");
	for(int i=0; i<tamanho-1; i++){
		printf("%d, ", vetor[i]);
	}
	printf("%d]\n", vetor[tamanho-1]);
}

void le_vetor(int vetor[], int tamanho){
	for(int i=0; i<tamanho; i++){
		scanf("%d", &vetor[i]);
	}
}

void troca(int vetor[], int i, int j){
	int temp = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = temp;
}
