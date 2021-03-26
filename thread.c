#include "thread.h"
int arraySize=10000000;
// int arraySize=9;
void* fill(void* args){
    if(args==NULL)return NULL;
Args* temp=(Args*)args;
int start=temp->start;
int end=temp->end;
int* arr=temp->arr;
for(int i=start;i<end;++i){
    (*(arr+i))*=(*(arr+i));
}
return NULL;
}

void fill_memory(int* arr, int n){
    if(arr==NULL)return;
pthread_t thread;
int groups=arraySize/n;
for(int i=0;i<n;++i){
    Args args;
    args.arr=arr;
    if(i==n-1){
        args.start=i*groups;
        args.end=arraySize;
    }else{
    args.start=i*groups;
    args.end=i*groups+groups;
    }
    pthread_create(&thread,NULL,fill,&args);
    pthread_join(&thread,NULL);
}
}
