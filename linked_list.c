#include "linked_list.h"
LinkedList* llist_initialize(int itemSize, char* typeName){
  LinkedList* list=malloc(sizeof(LinkedList));
  list->first=NULL;
  list->last=NULL;
  list->itemSize=itemSize;
  list->size=0;
  list->type=typeName;
  return list;
}
//Will initialize a Node with element value
Node* initializeANode(LinkedList* list,void* elem){
    Node* node=malloc(sizeof(Node));
    node->next=NULL;
    node->prev=NULL;
    if(NULL==elem){
        node->data=NULL;
    }else{
    node->data=malloc(list->itemSize);
    memcpy(node->data,elem,list->itemSize);
    }
    return node;
}
bool checkIndex(int size,int index){
    if(index<0||index>size){
        return false;
    }
    return true;
}
bool llist_add_at(LinkedList* list, int index, void* elem){
    if(NULL==list){
        return false;
    }
      Node* node=initializeANode(list,elem);
      if(!checkIndex(list->size,index)){
          return false;
      }
      if(list->first==NULL){
          list->first=node;
          list->last=node;
          list->size++;
          return true;
      }
      Node* temp=list->first;
      if(0==index){
          node->next=temp;
          temp->prev=node;
          list->first=node;
          list->size++; 
          return true;
      }
      int counter=0;
      while(counter!=index-1&&NULL!=temp){
         counter++;
         temp=temp->next;
      }
      if(NULL==temp){
          return false;
      }else{
          Node* temp1=temp->next;
          if(NULL==temp1){
              temp->next=node;
              node->prev=temp;
              list->last=node;
              list->size++;
              return true;
          }
          temp->next=node;
          node->prev=temp;
          node->next=temp1;
          temp1->prev=node;
          list->size++;
          return true;
      }
}
bool llist_add_first(LinkedList* list, void* elem){
     if(list==NULL)return false;
   return llist_add_at(list,0,elem);
}
bool llist_add_last(LinkedList* list, void* elem){
    if(list==NULL)return false;
    return llist_add_at(list,list->size,elem);
}
void* llist_get(LinkedList* list, int index){
        if(NULL==list){
        return NULL;
    }
Node* temp=list->first;
int count=0;
while(NULL!=temp){
    if(count==index){
        return temp->data;
    }
    count++;
    temp=temp->next;
}
return NULL;
}
void* llist_get1(LinkedList* list, int index){
        if(NULL==list){
        return NULL;
    }
Node* temp=list->first;
int count=0;
while(NULL!=temp){
    if(count==index){
        return temp;
    }
    count++;
    temp=temp->next;
}
return NULL;
}
int llist_index_of(LinkedList* list, void* elem){
        if(NULL==list){
        return -1;
    }
  int count=0;
  Node* node=list->first;
  while(NULL!=node){
      if(NULL==node->data&&NULL==elem){
          return count;
      }
      if(NULL!=node->data&&NULL!=elem&&0==memcmp(node->data,elem,list->itemSize)){
          return count;
      }
      count++;
      node=node->next;
  }
  return -1;
}
void* llist_remove(LinkedList* list, int index){
    if(NULL==list){
        return  NULL;
    }
  Node* node=llist_get1(list,index);
  if(NULL==node){
      return NULL;
  }
  Node* pre=node->prev;
  Node* next=node->next;
  if(NULL!=pre){
      pre->next=next;
  }else{
      list->first=next;
  }
  if(NULL!=next){
      next->prev=pre;
  }else{
      list->last=pre;
  }
  list->size--;
  return node;
}
void* llist_remove_first(LinkedList* list){
    if(NULL==list)return NULL;
  return llist_remove(list,0);
}
void* llist_remove_last(LinkedList* list){
    if(NULL==list)return NULL;
    return llist_remove(list,list->size-1);
}
bool llist_destroy(LinkedList* list){
   Node* temp=list->first;
   Node* next=NULL;
   while(NULL!=temp){
    next=temp->next;
    free(temp->data);
    free(temp);
    temp=next;
   }
   list->size=0;
   list->itemSize=0;
   list->first=NULL;
   list->last=NULL;
   list->type=NULL;
   free(list);
   list=NULL;
}
