/*
    Dada uma coleção de numeros distintos, retorne todas as possiveis permutaçoes.
*/

#include <vector>
#include <iostream>

using namespace std;

void imprimirVetor(const std::vector<std::vector<int>>& vetor, size_t indice = 0) {
    if (indice >= vetor.size()) {
        return;  // Condição de parada: chegamos ao final do vetor
    }

    std::cout << "[";
    const std::vector<int>& vetorInterno = vetor[indice];
    for (size_t i = 0; i < vetorInterno.size(); i++) {
        std::cout << vetorInterno[i];
        if (i != vetorInterno.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    imprimirVetor(vetor, indice + 1);  // Chamada recursiva para o próximo vetor interno
}

void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& permutacao, vector<bool>& usados){
    if(permutacao.size() == nums.size()){ //objetivo atingido
        res.push_back(permutacao);
        return;
    }
    for(size_t i=0; i<nums.size(); i++){
        if(! usados[i]){ //escolha valida
            //fazer uma escolha
            usados[i] = true;
            permutacao.push_back(nums[i]);
            backtrack(res, nums, permutacao, usados);
            // desfazer a escolha
            usados[i] = false;
            permutacao.pop_back();
        }
    }
}

int main() {
    vector<vector<int>> solucao;
    vector<int> numeros = {1, 2, 3};
    vector<bool> usados(numeros.size(), false);
    vector<int> perm;
    backtrack(solucao, numeros, perm, usados);
    imprimirVetor(solucao);

    return 0;
}