#include "safe.h"
sem_t flag;
bool first_time=true;
Counter* counter=NULL;
void* counting(void* count){
if(count==NULL)return NULL;
sem_wait(&flag);
Counter* counter=(Counter*)count;
if(counter->counter<1000){
counter->counter++;
printf("%d\n",counter->counter);
}
sem_post(&flag);
return NULL;
}
void count_variable(int n){
    if(first_time){
    sem_init(&flag,0,1);
    first_time=false;
    counter=malloc(sizeof(Counter));
    counter->counter=0;
    }
    pthread_t* thread1=malloc(n*sizeof(pthread_t));
    for(int i=0;i<n;++i){
    pthread_create((thread1+i),NULL,counting,counter);
    }
    for(int i=0;i<n;++i){
        pthread_join(*(thread1+i),NULL);
    }
}
