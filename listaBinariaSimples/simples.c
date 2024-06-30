#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node **head, int key)
{
    Node *temp = *head;
    Node *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 0);

    printf("Lista encadeada: ");
    printList(head);

    deleteNode(&head, 2);
    printf("Lista após a remoção do elemento 2: ");
    printList(head);

    return 0;
}