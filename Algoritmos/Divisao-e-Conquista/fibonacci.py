"""
    Implementacao do problema da torre de hanoi
    usando o metodo de divisao e conquista
"""

def fib(n):
    if n <= 1:
        return n
    else:
        return fib(n-1) + fib(n-2)


def main():
    print(fib(18))


main()
