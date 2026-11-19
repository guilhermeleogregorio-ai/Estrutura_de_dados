#include<stdio.h>

int main() {
    int vetor[] = {1, 3, 5, 8, 10, 15};
    //int vetor[] = {10, 6, 10, 3, 5, 8};
    int n = 6;
    int ordenado = 1;

    for (int i = 0; i < n - 1; i++) {
        if (vetor[i + 1] < vetor[i]) { // n vezes -> O(n)
            ordenado = 0;
            break;
        }
    }

    printf("%d\n", ordenado);
}