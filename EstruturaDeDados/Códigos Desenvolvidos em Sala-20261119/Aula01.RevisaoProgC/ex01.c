#include<stdio.h>

int main() {
    int n = 100;
    int soma = 0;
    
    // soma de 1 a N
    for (int i = 1; i <= n; i++) {
        soma = soma + i; // n vezes -> O(n)
    }
    printf("%d\n", soma);

    // soma dos pares de 1 a N - v1
    soma = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) { // n vezes -> O(n)
            soma = soma + i;
        }
    }
    printf("%d\n", soma);
    
    // soma dos pares de 1 a N - v2
    soma = 0;
    for (int i = 2; i <= n; i = i + 2) {
        soma = soma + i; // (n / 2)  vezes -> O(n) 
    }
    printf("%d\n", soma);


}