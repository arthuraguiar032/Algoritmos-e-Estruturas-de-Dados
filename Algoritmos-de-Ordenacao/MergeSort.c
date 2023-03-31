#include "utils.h"

void merge(int vetor[], int tamanho) {
	int meio = tamanho / 2;
	int top_esq = 0, top_dir = meio, i = 0;
	int aux[tamanho];

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
}

int merge_sort(int vetor[], int tamanho){
	int meio = tamanho / 2;

	if(tamanho > 1){
		merge_sort(vetor, meio);
		merge_sort(vetor + meio, tamanho - meio);
		merge(vetor, tamanho);
	}
}

int main(void){
	
	int tamanho = 500;
	int vetor[tamanho];

	preenche_vetor(vetor, tamanho);
	imprime_vetor(vetor, tamanho);
	merge_sort(vetor, tamanho);
	imprime_vetor(vetor, tamanho);

	return 0;
}