#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[50];
} Person;

void addOne(int *n)
{
    *n = *n + 1; // Incrementa o valor apontado por n
}

int main()
{
    // int x = 10;
    // int *ptr; // Declaração de um ponteiro para um inteiro

    // ptr = &x; // ptr agora armazena o endereço de x

    // // Exibindo o valor de x usando o ponteiro
    // printf("O valor de x: %d\n", x);
    // printf("O valor de x usando o ponteiro: %d\n", *ptr);

    // // Exibindo o endereço de x
    // printf("O endereço de x: %p\n", (void *)&x);
    // printf("O valor armazenado no ponteiro ptr (endereço de x): %p\n", (void *)ptr);

    // printf("Valor de x antes: %d\n", x);
    // addOne(&x); // Passa o endereço de x para a função
    // printf("Valor de x depois: %d\n", x);

    // int arr[5] = {1, 2, 3, 4, 5};
    // int *ptr;

    // ptr = arr; // ptr agora aponta para o primeiro elemento de arr

    // // Acessando elementos do array usando ponteiros
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("Elemento %d: %d\n", i, *(ptr + i));
    // }

    // Person person1 = {1, "Alice"};
    // Person *ptr;

    // ptr = &person1; // ptr agora aponta para person1

    // // Acessando membros da estrutura usando o ponteiro
    // printf("ID: %d\n", ptr->id);
    // printf("Name: %s\n", ptr->name);

    int *ptr;
    int n = 5;

    // Alocação dinâmica de memória para um array de 5 inteiros
    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Inicializando o array
    for (int i = 0; i < n; i++)
    {
        ptr[i] = i + 1;
    }

    // Exibindo os valores do array
    for (int i = 0; i < n; i++)
    {
        printf("Elemento %d: %d\n", i, ptr[i]);
    }

    // Liberando a memória alocada
    free(ptr);

    return 0;
}