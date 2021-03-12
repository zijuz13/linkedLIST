#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct _BinTreeNode{
void* data;
struct _BinTreeNode* left;
struct _BinTreeNode* right;
}BinaryTreeNode;
typedef struct _BinaryTree{
BinaryTreeNode* top;
int itemSize;
char* type;
int (*compare)(void*,void*);
void (*print)(void*);
} BinaryTree;
typedef struct _Node{
    void* data;
   struct _Node* next;
   struct _Node* pre;
} Node;
typedef struct _Stack{
Node* head;
Node* last;
char* typeName;
int itemSize;
int size;
} Stack;
typedef struct _Queue{
Node* head;
Node* last;
char* typeName;
int itemSize;
int size;
} Queue;
BinaryTree* bintree_initialize(int, char*, int (*)(void*, void*), void (*)(void*));
BinaryTreeNode* bintree_create_node(int, void*);
bool bintree_insert(BinaryTree*, void*);
bool bintree_search(BinaryTree*, void*);
void bintree_print_in_order(BinaryTree*);
void bintree_print_pre_order(BinaryTree*);
void bintree_print_post_order(BinaryTree*);
void bintree_print_reverse_order(BinaryTree*);
bool _bintree_search_recursive(BinaryTree*, BinaryTreeNode*, void*);
void _bintree_in_order_recursive(BinaryTree*, BinaryTreeNode*);
void _bintree_pre_order_recursive(BinaryTree*, BinaryTreeNode*);
void _bintree_post_order_recursive(BinaryTree*, BinaryTreeNode*);
void _bintree_reverse_order_recursive(BinaryTree*, BinaryTreeNode*);
void bintree_print_breadth_first(BinaryTree*);
void bintree_print_depth_first(BinaryTree*);
bool bintree_insert_replace(BinaryTree*, void*);
bool _bintree_insert_replace_recursive(BinaryTree*, BinaryTreeNode*, void*);
Stack* stack_initialize(int, char*);
bool stack_push(Stack*, void*);
void* stack_pop(Stack*);
void* stack_peek(Stack*);
int stack_size(Stack*);
bool stack_contains(Stack*, void*);
bool stack_destroy(Stack*);
Queue* queue_initialize(int, char*);
bool queue_enqueue(Queue*, void*);
void* queue_dequeue(Queue*);
void* queue_peek(Queue*);
int queue_size(Queue*);
bool queue_contains(Queue*, void*);
bool queue_destroy(Queue*);
