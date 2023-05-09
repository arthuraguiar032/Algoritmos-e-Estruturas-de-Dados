#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"


void preenche_vetor(long int vetor[], long int tamanho){
	srand(time(NULL));

	for(long int i=0; i<tamanho; i++){
		vetor[i] = rand() % 1001;
	}
}

void imprime_vetor(long int vetor[], long int tamanho){
	printf("\n[");
	for(long int i=0; i<tamanho-1; i++){
		printf("%ld, ", vetor[i]);
	}
	printf("%ld]\n", vetor[tamanho-1]);
}

void le_vetor(long int vetor[], long int tamanho){
	for(int i=0; i<tamanho; i++){
		scanf("%ld", &vetor[i]);
	}
}

void troca(long int vetor[], long int i, long int j){
	long int temp = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = temp;
}
