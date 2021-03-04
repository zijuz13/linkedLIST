#include "queue.h"

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
