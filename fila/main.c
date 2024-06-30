#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Fila está vazia\n");
        return -1;
    }
    Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL;
}

void printQueue(Queue *queue)
{
    Node *temp = queue->front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Fila: ");
    printQueue(queue);

    printf("Elemento removido: %d\n", dequeue(queue));
    printf("Fila após remoção: ");
    printQueue(queue);

    enqueue(queue, 40);
    printf("Fila após inserção de 40: ");
    printQueue(queue);

    while (!isQueueEmpty(queue))
    {
        printf("Elemento removido: %d\n", dequeue(queue));
    }

    return 0;
}