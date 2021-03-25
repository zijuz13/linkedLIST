#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct _Args{
int* arr;
int start;
int end;
} Args;
void* fill(void*);
void fill_memory(int*, int);
