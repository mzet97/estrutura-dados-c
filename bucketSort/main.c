#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10 // Número de baldes

// Estrutura do balde
typedef struct
{
    int count;
    int *values;
} Bucket;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

Bucket *createBuckets(int n)
{
    Bucket *buckets = (Bucket *)malloc(BUCKETS * sizeof(Bucket));
    for (int i = 0; i < BUCKETS; i++)
    {
        buckets[i].count = 0;
        buckets[i].values = (int *)malloc(n * sizeof(int));
    }
    return buckets;
}

void bucketSort(int arr[], int n)
{
    Bucket *buckets = createBuckets(n);

    // Distribui os elementos nos baldes
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / BUCKETS; // Supondo que os valores de arr[i] estejam no intervalo [0, 99]
        buckets[bucketIndex].values[buckets[bucketIndex].count++] = arr[i];
    }

    // Ordena cada balde usando Insertion Sort
    for (int i = 0; i < BUCKETS; i++)
    {
        if (buckets[i].count > 0)
        {
            insertionSort(buckets[i].values, buckets[i].count);
        }
    }

    // Concatenar todos os baldes no array original
    int index = 0;
    for (int i = 0; i < BUCKETS; i++)
    {
        for (int j = 0; j < buckets[i].count; j++)
        {
            arr[index++] = buckets[i].values[j];
        }
    }

    // Liberar a memória alocada para os baldes
    for (int i = 0; i < BUCKETS; i++)
    {
        free(buckets[i].values);
    }
    free(buckets);
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
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}