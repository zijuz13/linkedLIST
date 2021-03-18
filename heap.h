#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct _AList{
void ** arr;
int size;
int maxSize;
int itemSize;
char* type;
} ArrayList;

typedef struct _Heap{
ArrayList* list;
int (*compare)(void*,void*);
void (*print)(void*);
} Heap;
ArrayList* alist_initialize(int, int, char*);
bool alist_add(ArrayList*, void*);
bool alist_add_at(ArrayList*, int, void*);
void alist_clear(ArrayList*);
void* alist_get(ArrayList*, int);
int alist_index_of(ArrayList*, void*);
void* alist_remove(ArrayList*, int);
bool alist_destroy(ArrayList*);
bool alist_resize(ArrayList*);
Heap* heap_initialize(int, char*, int (*)(void*, void*), void (*)(void*));
bool heap_insert(Heap*, void*);
void* heap_remove(Heap*);
void* heap_peek(Heap*);
int heap_size(Heap*);
bool heap_contains(Heap*, void*);
bool _heapify(Heap*, int);
bool _heapify_up(Heap*, int);
