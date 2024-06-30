#include <stdio.h>

// Função para realizar o Bubble Sort otimizado
void bubbleSort(int arr[], int n)
{
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Troca arr[j] e arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // Se nenhum elemento foi trocado na passagem interna, a lista está ordenada
        if (swapped == 0)
        {
            break;
        }
    }
}

// Função para imprimir um array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}