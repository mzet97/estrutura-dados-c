#include <stdio.h>
#include <stdlib.h>

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

    if (*head == NULL)
    {
        newNode->next = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteNode(Node **head, int key)
{
    if (*head == NULL)
        return;

    Node *temp = *head, *prev;
    while (temp->data != key)
    {
        if (temp->next == *head)
        {
            printf("Chave não encontrada.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head)
    {
        prev = *head;
        while (prev->next != *head)
        {
            prev = prev->next;
        }
        *head = temp->next;
        prev->next = *head;
        free(temp);
    }
    else if (temp->next == *head)
    {
        prev->next = *head;
        free(temp);
    }
    else
    {
        prev->next = temp->next;
        free(temp);
    }
}

void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("(head)\n");
}

int main()
{
    Node *head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 0);

    printf("Lista circular encadeada: ");
    printList(head);

    deleteNode(&head, 2);
    printf("Lista após a remoção do elemento 2: ");
    printList(head);

    return 0;
}