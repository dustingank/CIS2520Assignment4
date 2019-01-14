/*This is main.c for assignment 4
Name: Yizhou Wang
ID: 1013411
Date: November 8th 2018
File Name: main.c file
*/
#include <stdio.h>
#include <stdlib.h>
#include "A4Header.h"


int main(void) {
    int boolean = 0;
    int check = 0;
    int size = 0;
    int count = 0;
    int inputValue = 0;
    int initialized = 0;
    
    struct Node *root, *foundNode;
    char input[8];
    
    printf(" 1, Initialization\n 2, Find\n 3, Insert\n 4, Remove\n 5, Check heigh and size\n 6, Find all\n 7, Exit\n");
    printf(" Enter a code(1 - 7) and hit Return\n");
    
    while (boolean == 0) {
        printf(" avl/> ");
        scanf("%d", &check);
        if(check != 1 && initialized == 0){
            printf(" Error: Needed to Initialization tree\n");
            continue;
        }
        switch (check) {
            case 1: // load the file and make the avl tree
                root = loadFile();
                printf(" Initialization Done!\n");
                
                /*printf("Root: %s; countValue: %d; height: %d\n", root->key, root->countValue, root->height);
                printf("Left: %s; countValue: %d; height: %d\n", root->left->key, root->left->countValue,root->left->height);
                printf("Right: %s; countValue: %d; height: %d\n", root->right->key, root->right->countValue,root->right->height);
                printf("Left->left: %s; countValue: %d; height: %d\n", root->left->left->key, root->left->left->countValue, root->left->left->height);*/
                initialized = 1;
                break;
            case 2: // find element
                
                printf(" find key: ");
                scanf("%s", input);
                
                foundNode = findKey(root, input);
                if(foundNode == NULL) {
                    printf(" no_such_key\n");
                } else {
                    printf(" key: %s, frequency: %d\n", foundNode->key, foundNode->countValue);
                }
                break;
            case 3: // insert
                printf(" insert key: ");
                scanf("%s", input);
                
                root = insertion(root, input);
                foundNode = findKey(root,input);
                printf(" key: %s, frequency: %d\n", input, foundNode->countValue);
                break;
            case 4: //remove
                printf(" remove key: ");
                scanf("%s", input);
                
                foundNode = deletion(root, input);
                if(foundNode == NULL) {
                    printf(" no_such_key\n");
                    break;
                }
                printf(" key: %s, frequency: %d\n", input, foundNode->countValue);
                break;
            case 5: //check height, size, total count
                printf(" The height of this AVL tree is: %d\n", Height(root) - 1);
                TotalSizeCount(root, &size, &count);
                printf(" The size is: %d\n The total count is: %d\n", size, count - 1);
                break;
            case 6: // find all
                printf(" frequency: ");
                scanf("%d", &inputValue);
                findAll(root, inputValue);
                break;
            case 7:
                boolean = 1;
                printf(" Quit\n");
                free(root);
                break;
        }
    }
    return 0;
}
