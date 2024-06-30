#include <stdio.h>
#include <stdlib.h>

// Função para obter o maior valor em arr[]
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Função de contagem para um dígito específico
void countSort(int arr[], int n, int exp)
{
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    // Armazena a contagem de ocorrências
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Modifica count[] de modo que count[i] contenha a posição real desse dígito em output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para arr[], para que arr[] contenha os números ordenados de acordo com o dígito atual
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    free(output);
}

void radixSort(int arr[], int n)
{
    // Encontra o maior número para saber o número de dígitos
    int max = getMax(arr, n);

    // Faz o counting sort para cada dígito. Em vez de passar o número do dígito, exp é passado.
    // exp é 10^i, onde i é o dígito atual.
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}