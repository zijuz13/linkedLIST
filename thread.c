#include "thread.h"
int arraySize=10000000;
void* fill(void* args){
    if(args==NULL)return NULL;
Args* temp=(Args*)args;
int start=temp->start;
int end=temp->end;
int* arr=temp->arr;
int temp12=0;
for(int i=start;i<end;++i){
    temp12=(*(arr+i));
    (*(arr+i))=temp12*temp12;
}
return NULL;
}

void fill_memory(int* arr, int n){
    if(arr==NULL)return;
pthread_t* thread=malloc(n*sizeof(pthread_t));
int groups=arraySize/n;
for(int i=0;i<n;++i){
    Args* args=malloc(sizeof(Args));
    args->arr=arr;
    if(i==n-1){
        args->start=i*groups;
        args->end=arraySize;
    }else{
    args->start=i*groups;
    args->end=i*groups+groups;
    }
    pthread_create((thread+i),NULL,fill,args);
    pthread_join(*(thread+i),NULL);
}
}
