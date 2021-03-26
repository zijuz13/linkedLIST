#include "safe.h"
sem_t flag;
void* counting(void* count){
sem_wait(&flag);
Counter* counter=(Counter*)count;
if(counter->counter<1000){
counter->counter++;
printf("%d\n",counter->counter);
}
sem_post(&flag);
}
void count_variable(int n){
    sem_init(&flag,0,1);
    Counter* counter=malloc(sizeof(Counter));
    counter->counter=0;
    pthread_t* thread1[1000];
    for(int i=0;i<1000;++i){
    pthread_create((thread1+i),NULL,counting,counter);
    }
    for(int i=0;i<1000;++i){
        pthread_join(*(thread1+i),NULL);
    }
}
