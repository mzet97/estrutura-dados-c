#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
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

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

Node *searchNode(Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return searchNode(root->left, data);
    }

    return searchNode(root->right, data);
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    Node *root = NULL;

    // Inserindo nós na árvore
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Imprimindo a árvore em ordem
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Buscando um valor na árvore
    int searchValue = 40;
    Node *searchResult = searchNode(root, searchValue);
    if (searchResult != NULL)
    {
        printf("Valor %d encontrado na árvore.\n", searchValue);
    }
    else
    {
        printf("Valor %d não encontrado na árvore.\n", searchValue);
    }

    return 0;
}