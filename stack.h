#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Node{
    void* data;
   struct _Node* next;
   struct _Node* pre;
} Node;

typedef struct _Stack{
Node* head;
Node* last;
char* typeName;
int itemSize;
int size;
} Stack;

Stack* stack_initialize(int, char*);
bool stack_push(Stack*, void*);
void* stack_pop(Stack*);
void* stack_peek(Stack*);
int stack_size(Stack*);
bool stack_contains(Stack*, void*);
bool stack_destroy(Stack*);
