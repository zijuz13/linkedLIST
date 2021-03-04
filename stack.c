#include "stack.h"

Stack* stack_initialize(int typeSize, char* typeName){
    Stack* stack=malloc(sizeof(Stack));
    stack->itemSize=typeSize;
    stack->typeName=malloc(strlen(typeName)*sizeof(char));
    strcpy(stack->typeName,typeName);
    stack->head=NULL;
    stack->last=NULL;
    stack->size=0;
    return stack;
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
    node->pre=NULL;
    return node;
}
bool checkNullPointer(Stack* queue){
    return queue==NULL;
}
bool stack_push(Stack* queue, void* element){
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
node->pre=oldLast;
queue->last=node;
queue->size++;
return true;
}
void* stack_pop(Stack* stack){
    if(checkNullPointer(stack)){
        return NULL;
    }
   Node* temp= stack->last;
   if(NULL==temp){
       return NULL;
   }
   void* data=temp->data;
    Node* next=temp->pre;
    free(stack->last);
    stack->size--;
   if(NULL==next){
       stack->head=NULL;
       stack->last=NULL;
       return data;
   }
   next->next=NULL;
   stack->last=next;
   return data;
}
void* stack_peek(Stack* stack){
if(checkNullPointer(stack)){
    return NULL;
}
return NULL!=stack->last?stack->last->data:NULL;
}
int stack_size(Stack* stack){
    if(checkNullPointer(stack)){
        return 0;
    }
    return stack->size;
}
bool stack_contains(Stack* stack, void* data){
    if(checkNullPointer(stack)){
        return false;
    }
    Node* temp=stack->head;
    while(NULL!=temp){
      void* content=temp->data;
      if(content==NULL&&data==NULL){
          return true;
      }
      if(NULL!=data&&NULL!=content&&0==memcmp(content,data,stack->itemSize)){
          return true;
      }
     temp=temp->next;
    }
    return false;
}
bool stack_destroy(Stack* stack){
    if(checkNullPointer(stack)){
        return false;
    }
   Node* node= stack->head;
   Node* next=NULL;
   while(NULL!=node){
    next=node->next;
    free(node);
    node=next;
   }
   stack->head=NULL;
   stack->last=NULL;
   stack->itemSize=0;
   free(stack->typeName);
   stack->typeName=NULL;
   stack->size=0;
   free(stack);
   stack=NULL;
   return true;
}
