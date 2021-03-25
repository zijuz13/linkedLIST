#include "unsafe.h"

void* counting(void* count){
    if(count==NULL)return NULL;
Counter* counter=(Counter*)count;
int value=counter->counter;
if(value<1000){
counter->counter++;
printf("%d\n",counter->counter);
}
return NULL;
}
void count_variable(int n){
    Counter counter;
    counter.counter=0;
   pthread_t* thread1=malloc(n*sizeof(pthread_t));
    for(int i=0;i<n;++i){
    pthread_create((thread1+i),NULL,counting,&counter);
    }
    for(int i=0;i<n;++i){
        pthread_join(*(thread1+i),NULL);
    }
}
