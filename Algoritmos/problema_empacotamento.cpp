/*
  Esse problema é uma variação do problema do empacotamento, resolvido usando algoritmo guloso.
  Este programa determina o menor número de frascos necessários para armazenar um dado número de comprimidos, considerando a capacidade de cada frasco.
  É um problema clássico de otimização, onde o objetivo é encontrar a solução que minimize a quantidade total de frascos utilizados.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int somaVetor(vector<int>& vetor){
    int soma = 0;
    for(int i=0; i<vetor.size(); i++){
        soma += vetor[i];
    }
    return soma;
}

int minFrascos(int w, vector<int>& capacidade_frascos) {
    //teste de segurança
    if(somaVetor(capacidade_frascos) < w){
        return -1;        
    }
    
    // ordenando vetor do maior para o menor
    sort(capacidade_frascos.begin(), capacidade_frascos.end(), greater<int>());
    
    // indice usado para calcular em que posicao do vetor estou
    int frascos_usados = 0;
    // loop para ir alterando a quantidade de comprimidos que preciso alocar
    while(w>0 && frascos_usados<capacidade_frascos.size()){
        int capacidade = capacidade_frascos[frascos_usados];
        
        if(w>=capacidade){
            w -= capacidade;    
        }else{
            w = 0;
        }
        frascos_usados++;
    }
    return frascos_usados;
}

int main() {
    int w; //Comprimidos produzidos
    int n; //Qtd Frascos vazios

    cout << "Comprimidos feitos: ";
    cin >> w;
    cout << "Frascos vazios: ";
    cin >> n;
    
    vector<int> capacidade_frascos(n);
    cout << "Digite o nº de comprimidos que cada frascos pode conter: " << endl;
    
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        capacidade_frascos[i] = p;
    }
    
    int numFrasco = minFrascos(w, capacidade_frascos);
    if(numFrasco == -1){
        cout << "Não é possivel guardar todos os comprimidos nos frascos disponiveis" << endl; 
    }else{
        cout << "O menor nº de frascos é: " << numFrasco << endl;   
    }

    return 0;
}
