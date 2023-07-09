/*
    Implementacao do problema da torre de hanoi
    usando o metodo de divisao e conquista
*/

#include <stdio.h>

void hanoi(int n, char origem, char trabalho, char destino){
    if(n>0){
        hanoi(n-1, origem, destino, trabalho);
        printf("Mova disco %d de %c para %c\n", n, origem, destino);
        hanoi(n-1, trabalho, origem, destino);
    }
}

int main(){
    hanoi(3, 'A', 'B', 'C');
    return 1;
}
