#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct _Count{
int counter;
} Counter;
void* counting(void*);
void count_variable(int);
