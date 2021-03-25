#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define MAX_LINE 1024
typedef struct _Operation{
int (*op)(int,int);
int a;
int b;
} Operation;
typedef struct _Args{
    Operation* operation;
 volatile bool is_complete;
} Args;
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
typedef struct _AList{
void ** arr;
int size;
int maxSize;
int itemSize;
char* type;
} ArrayList;
ArrayList* alist_initialize(int, int, char*);
bool alist_add(ArrayList*, void*);
bool alist_add_at(ArrayList*, int, void*);
void alist_clear(ArrayList*);
void* alist_get(ArrayList*, int);
int alist_index_of(ArrayList*, void*);
void* alist_remove(ArrayList*, int);
bool alist_destroy(ArrayList*);
bool alist_resize(ArrayList*);
Queue* queue_initialize(int, char*);
bool queue_enqueue(Queue*, void*);
void* queue_dequeue(Queue*);
void* queue_peek(Queue*);
int queue_size(Queue*);
bool queue_contains(Queue*, void*);
bool queue_destroy(Queue*);
void* compute(void*);
bool read_operations(char*, Queue*);
ArrayList* execute_thread_pool(char*, int);
void print_sorted(ArrayList*);
