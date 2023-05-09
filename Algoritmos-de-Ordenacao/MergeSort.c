#include "utils.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void merge(long int vetor[], long int tamanho) {
	long int meio = tamanho / 2;
	long int top_esq = 0, top_dir = meio, i = 0;
	long int *aux = (long int*) malloc(tamanho * sizeof(long int));

	while (top_esq < meio && top_dir < tamanho){
    	if(vetor[top_esq] <= vetor[top_dir]){
    		aux[i] = vetor[top_esq];
    		top_esq++;
    		i++;
    	} else{
    		aux[i] = vetor[top_dir];
    		top_dir++;
			i++;
		}	
  	}
 
	if(top_esq == meio ){
    	while(top_dir < tamanho){
			aux[i] = vetor[top_dir];
			i++;
			top_dir++;
		}
	} else{
    	while(top_esq < meio){
			aux[i] = vetor[top_esq];
			i++;
			top_esq++;
    	}
	}
 
	for(i = 0; i<tamanho; i++){
    	vetor[i] = aux[i];
	}

	free(aux);
}

void merge_sort(long int vetor[], long int tamanho){
	long int meio = tamanho / 2;

	if(tamanho > 1){
		merge_sort(vetor, meio);
		merge_sort(vetor + meio, tamanho - meio);
		merge(vetor, tamanho);
	}
}

int main(void){
	
	long int tamanho = 500;
	long int vetor[tamanho];
	clock_t tInicio, tFim;
	double tDecorrido;

	//leitura do arquivo
	FILE *fp;
	fp = fopen("numeros_ES1.txt", "r");
	if(fp==NULL){
		printf("Houve erro na abertura do arquivo.\n");
		return 1;
	}
    for (long i = 0; i < tamanho; i++) {
        fscanf(fp, "%ld", &vetor[i]);
    }
    fclose(fp);


    printf("Vetor Desordenado:");
	imprime_vetor(vetor, tamanho);
	printf("\nVetor Ordenado:");

	tInicio = clock();
	merge_sort(vetor, tamanho);
	tFim = clock();

	tDecorrido = ((double) (tFim - tInicio)) / CLOCKS_PER_SEC;

	imprime_vetor(vetor, tamanho);
	printf("\nTempo de Execução do MergeSort: %lf\n", tDecorrido);

	return 0;
}