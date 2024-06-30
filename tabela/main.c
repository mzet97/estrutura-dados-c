#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node;

typedef struct HashTable
{
    Node *table[TABLE_SIZE];
} HashTable;

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

Node *createNode(int key, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashTable *createHashTable()
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable *hashTable, int key, int value)
{
    int index = hashFunction(key);
    Node *newNode = createNode(key, value);
    if (hashTable->table[index] == NULL)
    {
        hashTable->table[index] = newNode;
    }
    else
    {
        Node *temp = hashTable->table[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int search(HashTable *hashTable, int key)
{
    int index = hashFunction(key);
    Node *temp = hashTable->table[index];
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Indica que a chave não foi encontrada
}

int main()
{
    HashTable *hashTable = createHashTable();

    // Inserindo pares chave-valor na tabela de dispersão
    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 42, 30);
    insert(hashTable, 4, 40);
    insert(hashTable, 12, 50);
    insert(hashTable, 14, 60);

    // Buscando valores na tabela de dispersão
    printf("Valor para a chave 1: %d\n", search(hashTable, 1));
    printf("Valor para a chave 2: %d\n", search(hashTable, 2));
    printf("Valor para a chave 42: %d\n", search(hashTable, 42));
    printf("Valor para a chave 4: %d\n", search(hashTable, 4));
    printf("Valor para a chave 12: %d\n", search(hashTable, 12));
    printf("Valor para a chave 14: %d\n", search(hashTable, 14));
    printf("Valor para a chave 99: %d\n", search(hashTable, 99)); // Chave inexistente

    return 0;
}