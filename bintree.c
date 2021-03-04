#include "bintree.h"
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
