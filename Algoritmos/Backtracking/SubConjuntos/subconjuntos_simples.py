"""
    Dado um array de inteiros, retorne todos os possiveis
    subconjuntos.
"""

def backtracking(solucao, numeros, sub, index=0):
    #verifcar se ja cheguei no resultado
    if index>=len(numeros):
        solucao.append(sub.copy())
        return
    #decisao de incluir o numero
    sub.append(numeros[index])
    backtracking(solucao, numeros, sub, index+1)
    #decisao de nao incluir o numero
    sub.pop()
    backtracking(solucao, numeros, sub, index+1)

def main():
    sol = list()
    conjunto = [1, 2, 3]
    backtracking(sol, conjunto, [])
    print(sol)

main()