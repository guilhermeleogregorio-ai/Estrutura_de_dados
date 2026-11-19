#include<stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);

    int vetor_estatico[5];
    int vetor_vla[n]; // VLA - variable-length array
    
    printf("Tam. do int em bytes: %ld\n", sizeof(int));
    printf("Tam. do vet bytes: %ld\n", sizeof(vetor_estatico));
    printf("Tam. do vet bytes: %ld\n", sizeof(vetor_vla));

    printf("Endereco de n: %ld\n", (unsigned long)&n);
    printf("Endereco de vetor_estatico: %ld\n", (unsigned long)vetor_estatico);
    printf("Endereco do vetor vla: %ld\n", (unsigned long)vetor_vla);
    printf("Valor do primeiro elemento: %d\n", vetor_estatico[1]);
    printf("Valor do primeiro elemento: %d\n", *(vetor_estatico+1));
    


    

    return 0;
}

