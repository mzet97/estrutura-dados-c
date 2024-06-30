#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(Node **head, int key)
{
    Node *temp = *head;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void printList(Node *node)
{
    Node *last;
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        last = node;
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

    printf("Lista duplamente encadeada: ");
    printList(head);

    deleteNode(&head, 2);
    printf("Lista após a remoção do elemento 2: ");
    printList(head);

    return 0;
}