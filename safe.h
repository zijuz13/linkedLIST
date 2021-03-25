
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
typedef struct _Count{
volatile int counter;
} Counter;
void* counting(void*);
void count_variable(int);
