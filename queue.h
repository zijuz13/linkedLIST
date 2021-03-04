#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Node{
    void* data;
   struct _Node* next;
} Node;

typedef struct _Queue{
Node* head;
Node* last;
char* typeName;
int itemSize;
int size;
} Queue;

Queue* queue_initialize(int, char*);
bool queue_enqueue(Queue*, void*);
void* queue_dequeue(Queue*);
void* queue_peek(Queue*);
int queue_size(Queue*);
bool queue_contains(Queue*, void*);
bool queue_destroy(Queue*);
