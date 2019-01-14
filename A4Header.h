/* this is header file for assignment
Name:Yizhou Wang
ID:1013411
Date:November 12th
File Name: A4Header.h file
*/
struct Node {
    char key[8];
    int height;
    int countValue;
    struct Node *left;
    struct Node *right;
   
};

struct Node *loadFile();
struct Node *insertion(struct Node *, char *);
struct Node* newNode(char *);
int Height(struct Node *);
int MAX(int, int);
int getBalance(struct Node *);
struct Node *left_left_rotation(struct Node *);
struct Node *right_right_rotation(struct Node *);
struct Node *right_left_rotation(struct Node *);
struct Node *left_right_rotation(struct Node *);
struct Node *findKey(struct Node *, char *);
struct Node *deletion(struct Node *, char *);
void TotalSizeCount(struct Node *, int *, int *);
void findAll(struct Node *, int);
