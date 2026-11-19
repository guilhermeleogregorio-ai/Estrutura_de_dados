#include<stdio.h>

int main() {
    int n = 32;
    int soma;

    soma = 0;
    for (int i = 1; i <= n; i = i * 2) { // log_n vezes
        soma = soma + i;
    }

    soma = 0;
    for (int i = 1; i <= n; i++) { // n vezes
        for (int j = 1; j <= n; j = j * 2) { // log_n vezes
            soma = soma + j; // n * log_n
        }
    }

}