#include "dictionary.h"
BinaryTree* bintree_initialize(int typeSize, char* typeName, int (*compare)(void*, void*), void (*print)(void*)){
    BinaryTree* tree=malloc(sizeof(BinaryTree));
    tree->itemSize=typeSize;
    tree->type=malloc(strlen(typeName)*sizeof(char));
    strcpy(tree->type,typeName);
    tree->compare=compare;
    tree->print=print;
    tree->top=NULL;
    return tree;
}
BinaryTreeNode* bintree_create_node(int dataSize, void* element){
    BinaryTreeNode* node=malloc(sizeof(BinaryTreeNode));
    node->left=NULL;
    node->right=NULL;
    if(NULL==element){
        node->data=NULL;
    }else{
       node->data=malloc(dataSize);
       memcpy(node->data,element,dataSize);
    }
    return node;
}
bool check_null_pointer(BinaryTree* tree){
    return tree==NULL;
}
bool bintree_insert(BinaryTree* tree, void* data){
if(check_null_pointer(tree)){
    return false;
}
if(tree->top==NULL){
    tree->top=bintree_create_node(tree->itemSize,data);
    return true;
}else{
    return _bintree_insert_recursive(tree,tree->top,data);
}
}
bool bintree_search(BinaryTree* tree, void* data){
if(check_null_pointer(tree)){
    return false;
}
if(data==NULL){
    return false;
}
if(tree->top==NULL){
    return false;
}else{
    return _bintree_search_recursive(tree,tree->top,data);
}
}
void bintree_print_in_order(BinaryTree* tree){
    if(check_null_pointer(tree)){
        return;
    }
    if(NULL==tree->top){
        return;
    }else{
        _bintree_in_order_recursive(tree,tree->top);
    }
}
void bintree_print_pre_order(BinaryTree* tree){
        if(check_null_pointer(tree)){
        return;
    }
    if(NULL==tree->top){
        return;
    }else{
        _bintree_pre_order_recursive(tree,tree->top);
    }
}
void bintree_print_post_order(BinaryTree* tree){
        if(check_null_pointer(tree)){
        return;
    }
    if(NULL==tree->top){
        return;
    }else{
        _bintree_post_order_recursive(tree,tree->top);
    }
}
void bintree_print_reverse_order(BinaryTree* tree){
    if(check_null_pointer(tree)){
        return;
    }
    if(NULL==tree->top){
        return;
    }else{
        _bintree_reverse_order_recursive(tree,tree->top);
    }
}
bool _bintree_insert_recursive(BinaryTree* tree, BinaryTreeNode* node, void* data){
if(data==NULL){
    return false;
}
int (*compare)(void*,void*)=tree->compare;
if(compare(node->data,data)<0){
if(NULL==node->left){
    node->left=bintree_create_node(tree->itemSize,data);
    return true;
}else{
    return _bintree_insert_recursive(tree,node->left,data);
}
}else{
if(NULL==node->right){
    node->right=bintree_create_node(tree->itemSize,data);
    return true;
}else{
    return _bintree_insert_recursive(tree,node->right,data);
}
}
}
bool _bintree_search_recursive(BinaryTree* tree, BinaryTreeNode* node, void* data){
    if(node==NULL){
        return false;
    }
    int (*compare)(void*,void*)=tree->compare;
    if(compare(node->data,data)==0){
        return true;
    }else if(compare(node->data,data)<0){
        return _bintree_search_recursive(tree,node->left,data);
    }else{
        return _bintree_search_recursive(tree,node->right,data);
    }
}
void _bintree_in_order_recursive(BinaryTree* tree, BinaryTreeNode* node){
    if(NULL!=node->left){
        _bintree_in_order_recursive(tree,node->left);
    }
    void (*print)(void*)=tree->print;
    print(node->data);
    if(NULL!=node->right){
        _bintree_in_order_recursive(tree,node->right);
    }
}
void _bintree_pre_order_recursive(BinaryTree* tree, BinaryTreeNode* node){\
    void (*print)(void*)=tree->print;
    print(node->data);
        if(NULL!=node->left){
        _bintree_pre_order_recursive(tree,node->left);
    }
    if(NULL!=node->right){
        _bintree_pre_order_recursive(tree,node->right);
    }
}
void _bintree_post_order_recursive(BinaryTree* tree, BinaryTreeNode* node){
        if(NULL!=node->left){
        _bintree_post_order_recursive(tree,node->left);
    }
    if(NULL!=node->right){
        _bintree_post_order_recursive(tree,node->right);
    }
    void (*print)(void*)=tree->print;
    print(node->data);
}
void _bintree_reverse_order_recursive(BinaryTree* tree, BinaryTreeNode* node){
    if(NULL!=node->right){
        _bintree_reverse_order_recursive(tree,node->right);
    }
    void (*print)(void*)=tree->print;
    print(node->data);
    if(NULL!=node->left){
        _bintree_reverse_order_recursive(tree,node->left);
    }
}
//Stack Definition
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
bool checkNullPointer(void* queue){
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
//Stack Definition
//Queue Definition
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
//Queue Definition
void bintree_print_breadth_first(BinaryTree* tree){
if(check_null_pointer(tree)||checkNullPointer(tree->top))return;
Queue* queue=queue_initialize(sizeof(BinaryTreeNode),"node");
queue_enqueue(queue,tree->top);
void (*print)(void*)=tree->print;
while(0!=queue_size(queue))
{
BinaryTreeNode* node=(BinaryTreeNode*)queue_dequeue(queue);
print(node->data);
if(NULL!=node->left){
    queue_enqueue(queue,node->left);
}
if(NULL!=node->right){
    queue_enqueue(queue,node->right);
}
}
}
void bintree_print_depth_first(BinaryTree* tree){
    if(check_null_pointer(tree)||checkNullPointer(tree->top))return;
 Stack* stack=stack_initialize(sizeof(BinaryTreeNode),"node");
 stack_push(stack,tree->top);
 void (*print)(void*)=tree->print;
 while(0!=stack_size(stack)){
     BinaryTreeNode* node=(BinaryTreeNode*)stack_pop(stack);
     print(node->data);
     if(NULL!=node->right){
         stack_push(stack,node->right);
     }
     if(NULL!=node->left){
         stack_push(stack,node->left);
     }
 }
}
bool _bintree_insert_replace_recursive(BinaryTree* tree, BinaryTreeNode* node, void* data){
int (*compare)(void*,void*)=tree->compare;
if(0==compare(node->data,data)){
    free(node->data);
    node->data=data;
    return true;
}else if(0>compare(node->data,data)){
    if(NULL==node->left){
        node->left=bintree_create_node(tree->itemSize,data);
        return true;
    }else{
        return _bintree_insert_replace_recursive(tree,node->left,data);
    }
}else{
        if(NULL==node->right){
        node->right=bintree_create_node(tree->itemSize,data);
        return true;
    }else{
       return _bintree_insert_replace_recursive(tree,node->right,data);
    }
}
}
bool bintree_insert_replace(BinaryTree* tree, void* data){
  if(check_null_pointer(tree)){
    return false;
}
if(tree->top==NULL){
    tree->top=bintree_create_node(tree->itemSize,data);
    return true;
}else{
    return _bintree_insert_replace_recursive(tree,tree->top,data);
}
}
//ArrayList Definition
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
        temp[i]=malloc(list->itemSize);
        memcpy(temp[i],originalArr[i],list->itemSize);
        free(originalArr[i]);
    }
    temp[index]=malloc(list->itemSize);
    memcpy(temp[index],element,list->itemSize);
    for(int j=index+1,i=index;i<size;++i){
        temp[j]=malloc(list->itemSize);
        memcpy(temp[j++],originalArr[i],list->itemSize);
        free(originalArr[i]);
    }
    free(originalArr);
    originalArr=NULL;
    list->arr=temp;
    temp=NULL;
}else{
    list->arr[size]=malloc(list->itemSize);
memcpy(list->arr[size],element,list->itemSize);
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
   int size=list->size;
   list->size=0;
   for(int i=0;i<size;++i){
       free(list->arr[i]);
       list->arr[i]=NULL;
   }
}
void* alist_get(ArrayList* list, int index){
    if(!checkIndex(index,list->size)){
        return NULL;
    }
    return list->arr[index];
}
int alist_index_of(ArrayList* list, void* elem){
    int size=list->size;
    for(int i=0;i<size;i++){
     if(0==memcmp(list->arr[i],elem,list->itemSize)){
         return i;
     } 
    }
    return -1;
}
void* alist_remove(ArrayList* list, int index){
if(checkIndex(index,list->size)){
    void* returnVal=list->arr[index];
    for(int i=index+1;i<list->size;++i){
        list->arr[i-1]=list->arr[i];
    } 
    free(list->arr[list->size-1]);
    list->arr[list->size-1]=NULL;
    list->size--;
    return returnVal;
}else{
    return NULL;
}
}
bool alist_destroy(ArrayList* list){
      list->size=0;
    list->maxSize=0;
    list->itemSize=0;
    free(list->type);
    list->type=NULL;
if(NULL!=list->arr){
    for(int i=0;i<list->size;++i){
       free(list->arr[i]);
       list->arr[i]=NULL; 
    }
    free(list->arr);
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
}
//ArrayList Defintion
//Dictionary Definition
Dictionary* dict_initialize(int (*compare)(void*, void*), void (*print)(void*)){
BinaryTree* tree=bintree_initialize(sizeof(Pair),"pair",compare,print);
Dictionary* dictionary=malloc(sizeof(Dictionary));
dictionary->tree=tree;
return dictionary;
}
bool dict_insert(Dictionary* dictionary, void* key, void* value){
    if(checkNullPointer(dictionary))return false;
    Pair* pair=malloc(sizeof(Pair));
    pair->first=key;
    pair->second=value;
    bintree_insert_replace(dictionary->tree,pair);
    return true;
}
void* _dict_get_recursive(Dictionary* dictionary,BinaryTreeNode* node,void* key){
if(checkNullPointer(node)){
    return NULL;
}
BinaryTree* tree=dictionary->tree;
int (*compare)(void*,void*)=tree->compare;
if(0>compare(node->data,key)){
    return _dict_get_recursive(dictionary,node->left,key);
}else if(0==compare(node->data,key)){
  Pair* pair=(Pair*)(node->data);
  return pair->second;
}else{
  return _dict_get_recursive(dictionary,node->right,key);
}
}
Pair* constructPair(void* key){
   Pair* pair=malloc(sizeof(Pair));
   pair->first=key;
   pair->second=NULL;
   return pair;
}
void* dict_get(Dictionary* dictionary, void* key){
   if(checkNullPointer(dictionary))return NULL;
   Pair* pair=constructPair(key);
   return _dict_get_recursive(dictionary,dictionary->tree->top,pair);
}
void _dict_key_traversal_left_to_right(Dictionary* dictionary,ArrayList* list,BinaryTreeNode* node){
if(NULL==node)return;
if(NULL!=node->left){
    _dict_key_traversal_left_to_right(dictionary,list,node->left);
}
   Pair* pair=(Pair*)node->data;
   alist_add(list,pair->first);
   if(NULL!=node->right){
       _dict_key_traversal_left_to_right(dictionary,list,node->right);
   }
}
ArrayList* dict_key_list(Dictionary* dictionary, int typeSize){
    ArrayList* list=alist_initialize(50,typeSize,"Pair");
    if(checkNullPointer(dictionary))return list;
    _dict_key_traversal_left_to_right(dictionary,list,dictionary->tree->top);
    return list;
}
bool dict_contains(Dictionary* dictionary, void* key){
    if(checkNullPointer(dictionary))return false;
  Pair* pair=constructPair(key);
  return bintree_search(dictionary->tree,pair); 
}
//Dictionary Definition
