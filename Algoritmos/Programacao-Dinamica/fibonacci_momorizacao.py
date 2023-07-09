"""
    Implementacao de algoritmo de fibonacci
    com o conceito de programacao dinamica
"""

MAX = 100
memo = [-1]*(MAX+1)
memo[0] = 0
memo[1] = 1

def fib(n):
    if memo[n]==-1:
        memo[n] = fib(n-1)+fib(n-2)
    return memo[n]


def main():
    print(fib(18))    


main()
