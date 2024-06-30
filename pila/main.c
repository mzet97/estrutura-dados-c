#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = NULL;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Pilha vazia\n");
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Pilha vazia\n");
        return -1;
    }
    return stack->top->data;
}

int main()
{
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Elemento no topo: %d\n", peek(&stack));
    printf("Elemento removido: %d\n", pop(&stack));
    printf("Elemento removido: %d\n", pop(&stack));
    printf("Elemento no topo: %d\n", peek(&stack));

    return 0;
}