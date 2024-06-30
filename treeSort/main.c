#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        return createNode(data);
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorderTraversal(Node *root, int arr[], int *index)
{
    if (root != NULL)
    {
        inorderTraversal(root->left, arr, index);
        arr[(*index)++] = root->data;
        inorderTraversal(root->right, arr, index);
    }
}

void treeSort(int arr[], int n)
{
    Node *root = NULL;

    // Insere os elementos na BST
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    // Realiza a travessia em ordem para preencher o array ordenado
    int index = 0;
    inorderTraversal(root, arr, &index);
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
    int arr[] = {5, 3, 7, 1, 9, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    treeSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}