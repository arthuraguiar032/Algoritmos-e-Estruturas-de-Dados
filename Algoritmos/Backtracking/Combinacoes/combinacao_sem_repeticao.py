"""
    Dados dois inteiros n e k, retorne todas as possiveis combinações de k numeros do range [1, n] sem repetição.
"""

def backtracking(solutions, n, k, comb, start=1):
    if len(comb) == k:
        solutions.append(comb.copy())
        return
    for i in range(start, n+1):
        comb.append(i)
        backtracking(solutions, n, k, comb, i+1)
        comb.pop()


def main():
    n = 4
    k = 2
    res = list()
    backtracking(res, n, k, [])
    print(res)


main()