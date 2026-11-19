#include<stdio.h>
#include<stdlib.h>

int *criar_vetor_dinamico(int n) {
    int *vetor;
    vetor = malloc(n * sizeof(int));
    
    if (vetor == NULL) {
        return NULL;
    }
    return vetor; 
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);

    int *vetor_dinamico1;
    vetor_dinamico1 = criar_vetor_dinamico(n);

    printf("Tamanho vetor em bytes: %ld\n", sizeof(vetor_dinamico1));
    printf("Endereco da memoria alocada: %ld\n", (unsigned long)vetor_dinamico1);
    printf("Endereco da variavel ponteiro: %p\n", &vetor_dinamico1);
    

    int *vetor_dinamico2;
    vetor_dinamico2 = criar_vetor_dinamico(n);

    printf("----------------\n");
    printf("Tamanho vetor em bytes: %ld\n", sizeof(vetor_dinamico2));
    printf("Endereco da memoria alocada: %ld\n", (unsigned long)vetor_dinamico2);
    printf("Endereco da variavel ponteiro: %p\n", &vetor_dinamico2);
    

    free(vetor_dinamico1);
    free(vetor_dinamico2);



    
    return 0;
}
