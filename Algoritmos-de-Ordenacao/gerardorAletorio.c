#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void){
	
	long int qtdNumeros = 1000000;
	srand(time(NULL));
	
	FILE *arq;
	arq = fopen("numeros.txt", "w");

	for(long int i=0; i<qtdNumeros; i++){
	       long int numero = rand() % 2000000;
	       fprintf(arq, "%ld\n", numero);
	}

	fclose(arq);
}