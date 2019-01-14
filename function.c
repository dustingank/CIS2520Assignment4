/*This is main.c for assignment 4
 Name: Yizhou Wang
 ID: 1013411
 Date: November 8th 2018
 File Name: main.c file
 */
#include <stdio.h>
#include <stdlib.h>
#include "A4Header.h"
#include <string.h>

struct Node *loadFile() {
    FILE *fptr;
    char data[150];
    struct Node *root = NULL;
    
    fptr = fopen("A4_data_f18.txt", "r"); // opea the file
    //fptr = fopen("testCase.txt", "r"); // this is just for testing; delet before submit
    
    if (fptr == NULL){ // error message
        printf(" errror\n");
        exit(1);
    }
    while (!feof(fptr)) {
        fscanf(fptr, "%s", data);
        root = insertion(root, data); // make the avl tree
      
    }
    
    fclose(fptr);
    return root;
    
}

struct Node* newNode(char *key) {
    //printf("NewNode %s\n", key);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); // maek the new Node
    //printf("2NewNode %s\n", key);
    //printf("B4: (%s) (%s)\n",newNode->key, key);
    strcpy(newNode->key, key);
    //printf("%s %s\n",newNode->key, key);
    //printf("3NewNode %s\n", key);
    newNode->height = 1;
    //printf("4NewNode %s\n", key);
    newNode->countValue = 1;
    //printf("5NewNode %s\n", key);
    newNode->left = NULL;
    //printf("6NewNode %s\n", key);
    newNode->right = NULL;
    //printf("7NewNode %s\n", key);
    return newNode;
}


struct Node *insertion(struct Node *node, char *key) {
    
    if (node == NULL) {
        //printf("null\n");
        //printf("%s\n", key);
        return(newNode(key));
    }
    
    if (strcmp(node->key, key) > 0) { // put the subnode in the left
        node->left  = insertion(node->left, key);
        
        if(getBalance(node) > 1) { // if there is Unbalance happened
            if(strcmp(node->left->key, key) > 0){ // do left left rotation
                node = left_left_rotation(node);
            }else{
                node = left_right_rotation(node); // do left right rotation
            }
        }
    } else if(strcmp(node->key,key) < 0) { // put the subnode in the right
        node->right = insertion(node->right, key);
        
        if(getBalance(node) < -1){
           
            if(strcmp(node->right->key, key) < 0){
              
                node = right_right_rotation(node);
            }else{
               
                node = right_left_rotation(node);
            }
        }
    } else { // if it's same string
        node->countValue++;
        return node;
    }
    
    node->height = 1 + MAX(Height(node->left), Height(node->right)); // updata the height of node
    

    return node;
}

int getBalance(struct Node *node) {
    if (node == NULL){
        return 0;
    }
    return Height(node->left) - Height(node->right);
}

int MAX(int left, int right) { // find the biggest height
    if (left >= right) {
        return left;
    }
    return right;
}

int Height(struct Node *node) { // find the height of a node
    if(node == NULL) {
        return 0;
    }
    return node->height;
}

struct Node *left_left_rotation(struct Node *node){ // this is left left rotation function
    struct Node *tempNode;
    tempNode = node->left;
    node->left = tempNode->right;
    tempNode->right = node;
    
    node->height = MAX(Height(node->left), Height(node->right)) + 1;
    tempNode->height = MAX(Height(tempNode->left), node->height ) + 1;
    
    return tempNode;
}

struct Node* right_right_rotation(struct Node *node) { // this is right right rotation function
    struct Node *tempNode;
    
    tempNode = node->right;
    node->right = tempNode->left;
    tempNode->left = node;
    
    node->height = MAX(Height(node->left), Height(node->right)) + 1;
    tempNode->height = MAX(Height(tempNode->right), node->height) + 1;
    
    return tempNode;
}

struct Node* left_right_rotation(struct Node *node) { // this is left right rotation function
    node->left = right_right_rotation(node->left);
    return left_left_rotation(node);
}

struct Node* right_left_rotation(struct Node *node) { // this is right left rotation function
    node->right = left_left_rotation(node->right);
    return right_right_rotation(node);
}

void TotalSizeCount (struct Node *root, int *size, int *count) { // calculate the total size and total value of this avl tree
    if(root != NULL) {
        *size = *size + 1;
        *count = root->countValue + *count;
        TotalSizeCount(root->left, size, count);
        TotalSizeCount(root->right, size, count);
    }
}

struct Node *findKey(struct Node *node, char *key){ // find the key
    if (node == NULL || strcmp(node->key,key) == 0){ // if the key is found or didn't found
        return node;
    }
    
    if (strcmp(node->key, key) < 0){
        return findKey(node->right, key);
    }
    
    return findKey(node->left, key);
}

struct Node *deletion(struct Node *root, char *key){ // delete one node
    struct Node *temp = NULL;
    
    temp = findKey(root,key);
    
    if(temp == NULL) { // if there is no such key; return error message
        return NULL;
    }
    
    temp->countValue = temp->countValue - 1;
    return temp;
}

void findAll(struct Node *node, int frequency){ // find all the node that bigger or equal the input value
    if(node != NULL) {
        if(node->countValue >= frequency){
            printf(" key: %s, frequency: %d\n", node->key, node->countValue);
        }
        
        findAll(node->left,frequency);
        findAll(node->right,frequency);
    }
}
