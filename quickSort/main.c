#include <stdio.h>

// Função de partição
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Escolhendo o pivô como o último elemento
    int i = (low - 1);     // Índice do menor elemento

    for (int j = low; j <= high - 1; j++)
    {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot)
        {
            i++; // Incrementa o índice do menor elemento
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Função QuickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}