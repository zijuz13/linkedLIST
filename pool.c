#include "pool.h"
//Operators Definitions:
int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int mul(int a,int b){
    return a*b;
}
ArrayList* alist_initialize(int maxSize, int typeSize, char* name){
  ArrayList* list= (ArrayList*) malloc(sizeof(ArrayList));
  list->maxSize=maxSize;
  list->size=0;
  list->type=malloc(strlen(name)*sizeof(char));
  strcpy(list->type,name);
  list->itemSize=typeSize;
  //allocate continuous memory blocks for the 2-D pointer to point
  list->arr=calloc(maxSize,sizeof(void*));
  return list;
}
bool alist_add(ArrayList* list, void* elem){
 if(elem==NULL||list==NULL){
     return false;
 }
  return alist_add_at(list,list->size,elem);
}
bool alist_add_at(ArrayList* list, int index,void* element){
        if(NULL==list){
        return false;
    }
    int size=list->size;
    //the specified index should be in the range of [0,size]
if(index<0||index>size){
    return false;
}
//if the new size is greater than the maxSize, the list should grow
int maxSize=list->maxSize;
if(size+1>maxSize){
    alist_resize(list);
}
if(0<=index&&index<size){
    void** temp=calloc(list->maxSize,sizeof(void*));
    void** originalArr=list->arr;
    for(int i=0;i<index;++i){
        temp[i]=originalArr[i];
    }
    temp[index]=element;
    for(int j=index+1,i=index;i<size;++i){
        temp[j++]=originalArr[i];
    }
    originalArr=NULL;
    list->arr=temp;
    temp=NULL;
}else{
    list->arr[size]=element;
}
list->size++;
return true;
}
bool checkIndex(int index,int size){
 if(index<0||index>=size){
     return false;
 }else{
     return true;
 }
}
void alist_clear(ArrayList* list){
        if(NULL==list){
        return;
    }
   int size=list->size;
   list->size=0;
   for(int i=0;i<size;++i){
       free(list->arr[i]);
       list->arr[i]=NULL;
   }
}
void* alist_get(ArrayList* list, int index){
        if(NULL==list){
        return NULL;
    }
    if(!checkIndex(index,list->size)){
        return NULL;
    }
    return list->arr[index];
}
int alist_index_of(ArrayList* list, void* elem){
        if(NULL==list){
        return -1;
    }
    int size=list->size;
    for(int i=0;i<size;i++){
     if(0==memcmp(list->arr[i],elem,list->itemSize)){
         return i;
     } 
    }
    return -1;
}
void* alist_remove(ArrayList* list, int index){
        if(NULL==list){
        return NULL;
    }
if(checkIndex(index,list->size)){
    void* returnVal=list->arr[index];
    for(int i=index+1;i<list->size;++i){
        list->arr[i-1]=list->arr[i];
    } 
    // free(list->arr[list->size-1]);
    // list->arr[list->size-1]=NULL;
    list->size--;
    return returnVal;
}else{
    return NULL;
}
}
bool alist_destroy(ArrayList* list){
    if(NULL==list){
        return false;
    }
    list->size=0;
    list->maxSize=0;
    list->itemSize=0;
    free(list->type);
    list->type=NULL;
if(NULL!=list->arr){
    for(int i=0;i<list->size;++i){
       if(NULL!=list->arr[i])
       free(list->arr[i]);
    //    list->arr[i]=NULL; 
    }
   // free(list->arr);
    list->arr=NULL;
}
free(list);
list=NULL;
return true;
}
bool alist_resize(ArrayList* list){
    if(NULL==list){
        return false;
    }    
 list->maxSize*=2;
 list->arr=realloc(list->arr,list->maxSize*sizeof(void*));
 return true;   
}
Queue* queue_initialize(int typeSize, char* typeName){
    Queue* queue=malloc(sizeof(Queue));
    queue->itemSize=typeSize;
    queue->typeName=malloc(strlen(typeName)*sizeof(char));
    strcpy(queue->typeName,typeName);
    queue->head=NULL;
    queue->last=NULL;
    queue->size=0;
    return queue;
}
Node* node_initialize(int itemSize,void* element){
    Node* node=malloc(sizeof(Node));
    if(element==NULL){
        node->data=NULL;
    }else{
        node->data=malloc(itemSize);
      memcpy(node->data,element,itemSize);
    }
    node->next=NULL;
    return node;
}
bool checkNullPointer(Queue* queue){
    return queue==NULL;
}
bool queue_enqueue(Queue* queue, void* element){
if(checkNullPointer(queue)){
    return false;
}
Node* node=node_initialize(queue->itemSize,element);
if(NULL==queue->head){
   queue->head=node;
   queue->last=node;
   queue->size++;
   return true;
}
Node* oldLast=queue->last;
oldLast->next=node;
queue->last=node;
queue->size++;
return true;
}
void* queue_dequeue(Queue* queue){
    if(checkNullPointer(queue)){
        return NULL;
    }
   Node* temp= queue->head;
   if(NULL==temp){
       return NULL;
   }
   void* data=temp->data;
    Node* next=temp->next;
    free(queue->head);
    queue->size--;
   if(NULL==next){
       queue->head=NULL;
       queue->last=NULL;
       return data;
   }
   queue->head=next;
   return data;
}
void* queue_peek(Queue* queue){
if(checkNullPointer(queue)){
    return NULL;
}
return NULL!=queue->head?queue->head->data:NULL;
}
int queue_size(Queue* queue){
    if(checkNullPointer(queue)){
        return 0;
    }
    return queue->size;
}
bool queue_contains(Queue* queue, void* data){
    if(checkNullPointer(queue)){
        return false;
    }
    Node* temp=queue->head;
    while(NULL!=temp){
      void* content=temp->data;
      if(content==NULL&&data==NULL){
          return true;
      }
      if(NULL!=data&&NULL!=content&&0==memcmp(content,data,queue->itemSize)){
          return true;
      }
     temp=temp->next;
    }
    return false;
}
bool queue_destroy(Queue* queue){
    if(checkNullPointer(queue)){
        return false;
    }
   Node* node= queue->head;
   Node* next=NULL;
   while(NULL!=node){
    next=node->next;
    free(node);
    node=next;
   }
   queue->head=NULL;
   queue->last=NULL;
   queue->itemSize=0;
   free(queue->typeName);
   queue->typeName=NULL;
   queue->size=0;
   free(queue);
   queue=NULL;
   return true;
}
//Thread Pool Definitions Start
void* compute(void* args){
if(args==NULL)return NULL;
Args* temp=(Args*)args;
Operation* operation=temp->operation;
if(operation==NULL)return NULL;
int a=operation->a;
int b=operation->b;
int (*op)(int,int)=operation->op;
int* result=malloc(sizeof(int));
*result=op(a,b);
temp->is_complete=true;
return result;
}
Operation* initialize_operation_by_file(char* line){
    Operation* operation=malloc(sizeof(Operation));
    int size=strlen(line);
    char* result=strtok(line," ");
    int op=atoi(result);
    switch (op)
    {
    case 0:
        operation->op=add;
        break;
    case 1:
        operation->op=sub;
        break;
    case 2:
        operation->op=mul;
        break;
    default:
        return NULL;
    }
    int count=0;
while((result=strtok(NULL," "))){
    if(0==count){
      operation->a=atoi(result);
      count++;
    }else{
      operation->b=atoi(result);
      break;
    }
}
return operation;
}
bool read_operations(char* file_name, Queue* queue){
if(queue==NULL)return false;
FILE* file=fopen(file_name,"r");
if(NULL==file)return false;
char buffer[MAX_LINE];
while(fgets(buffer,MAX_LINE,file)!=NULL){
Operation* operation=initialize_operation_by_file(buffer);
queue_enqueue(queue,operation);
}
return true;
}
ArrayList* execute_thread_pool(char* file_name, int max_num){
    if(max_num==0)return NULL;
   Queue* queue=queue_initialize(sizeof(Operation),"operation");
   if(!read_operations(file_name,queue))return NULL;
  int size=queue_size(queue);
  pthread_t* threads=NULL;
  ArrayList* list=alist_initialize(size,sizeof(int),"int");
  if(size>=max_num){
    threads=malloc(max_num*sizeof(pthread_t));
 ArrayList* argsList=alist_initialize(max_num,sizeof(Args),"args");
    for(int i=0;i<max_num;++i){
          Args* args=malloc(sizeof(Args));
          args->is_complete=false;
          args->operation=(Operation*)queue_dequeue(queue);
          alist_add(argsList,args);
          pthread_create((threads+i),NULL,compute,args);
      }
    while(queue_size(queue)>0){
       for(int i=0;i<max_num;++i){
          Args* args=(Args*)alist_get(argsList,i);
          if(args->is_complete){
            int* result=NULL;
            pthread_join(*(threads+i),(void**)&result);
            alist_add(list,result);
              Args* args1=malloc(sizeof(Args));
              args1->is_complete=false;
              args1->operation=(Operation*)queue_dequeue(queue);
              alist_remove(argsList,i);
              alist_add_at(argsList,i,args1);
             pthread_create((threads+i),NULL,compute,args1);
          }
       } 
    }
    int count=0;
    int i=0;
    int* arr=malloc(max_num*sizeof(int));
    for(int i=0;i<max_num;++i){
        *(arr+i)=0;
    }
    while(true){
     Args* args=(Args*)alist_get(argsList,i);
     if(args->is_complete&&(*(arr+i)==0)){
         count++;
         int* result=NULL;
         pthread_join(*(threads+i),(void**)&result);
         alist_add(list,result);
         *(arr+i)=3;
     }
     if(count==max_num){
         break;
     }
     i=(i+1)%max_num;
    }
  }else{
      threads=malloc(size*sizeof(pthread_t));
      for(int i=0;i<size;++i){
          Args* args=malloc(sizeof(Args));
          args->is_complete=false;
          args->operation=(Operation*)queue_dequeue(queue);
          pthread_create((threads+i),NULL,compute,args);
      }
      for(int i=0;i<size;++i){
         int* result=NULL;
         pthread_join(*(threads+i),(void**)&result);
          alist_add(list,result);
      }
  }
  return list;
}
int compareIntValue(void* a,void* b){
    return (*((int*)b))-(*(int*)a);
}
void quick_sort_recursive(int left,int right,void** arr){
if(left>=right){
    return;
}
int mid=left+((right-left)>>1);
void* pivot=arr[mid];
int l=left;
int r=right;
void* temp;
while(l<r){
while(compareIntValue(arr[l],pivot)>0){
++l;
}
while(compareIntValue(arr[r],pivot)<0){
--r;
}
if(l==r)break;
temp=arr[l];
arr[l]=arr[r];
arr[r]=temp;
if(compareIntValue(arr[l],pivot)==0){
    --r;
}
if(compareIntValue(arr[r],pivot)==0){
    ++l;
}
}
if(l==r){
    ++l;
    --r;
}
quick_sort_recursive(left,r,arr);
quick_sort_recursive(l,right,arr);
}
void print_sorted(ArrayList* list){
 int size=list->size;
 void** arr=list->arr;
 quick_sort_recursive(0,size-1,arr);
     for(int i=0;i<size;++i){
        printf("%d\n",(*(int*)alist_get(list,i)));
    }
}
