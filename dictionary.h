
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
typedef struct _Pair{
void* first;
void* second;
} Pair;
typedef struct _Dictionary{
BinaryTree* tree;
} Dictionary;
typedef struct _AList{
void ** arr;
int size;
int maxSize;
int itemSize;
char* type;
} ArrayList;
ArrayList* alist_initialize(int, int, char*);
bool alist_add(ArrayList*, void*);
bool alist_add_at(ArrayList*, int, void*);
void alist_clear(ArrayList*);
void* alist_get(ArrayList*, int);
int alist_index_of(ArrayList*, void*);
void* alist_remove(ArrayList*, int);
bool alist_destroy(ArrayList*);
bool alist_resize(ArrayList*);
BinaryTree* bintree_initialize(int, char*, int (*)(void*, void*), void (*)(void*));
BinaryTreeNode* bintree_create_node(int, void*);
bool bintree_insert(BinaryTree*, void*);
bool bintree_search(BinaryTree*, void*);
void bintree_print_in_order(BinaryTree*);
void bintree_print_pre_order(BinaryTree*);
void bintree_print_post_order(BinaryTree*);
void bintree_print_reverse_order(BinaryTree*);
bool _bintree_insert_recursive(BinaryTree*, BinaryTreeNode*, void*);
bool _bintree_search_recursive(BinaryTree*, BinaryTreeNode*, void*);
void _bintree_in_order_recursive(BinaryTree*, BinaryTreeNode*);
void _bintree_pre_order_recursive(BinaryTree*, BinaryTreeNode*);
void _bintree_post_order_recursive(BinaryTree*, BinaryTreeNode*);
void _bintree_reverse_order_recursive(BinaryTree*, BinaryTreeNode*);
void bintree_print_breadth_first(BinaryTree*);
void bintree_print_depth_first(BinaryTree*);
bool bintree_insert_replace(BinaryTree*, void*);
bool _bintree_insert_replace_recursive(BinaryTree*, BinaryTreeNode*, void*);
Dictionary* dict_initialize(int (*)(void*, void*), void (*)(void*));
bool dict_insert(Dictionary*, void*, void*);
void* dict_get(Dictionary*, void*);
ArrayList* dict_key_list(Dictionary*, int);
bool dict_contains(Dictionary*, void*);
