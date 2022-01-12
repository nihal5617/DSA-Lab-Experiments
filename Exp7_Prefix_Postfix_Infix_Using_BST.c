/*Write a program for construction of expression tree using postfix expression and perform traversal
(Inorder, Preorder and Postorder) of tree. */

#include <stdio.h>
#include <stdlib.h>

int top = -1;

struct node {
    char data;
    struct node* left;
    struct node* right;
};
struct node *stack[100];

struct node* newNode(char data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
     
    return (node);
}
void push(struct node *root){
    stack[++top]=root;
}

struct node* pop(){
    if(top==-1)
        return NULL;
    else
        return stack[top--];
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    else{
        printInorder(node->left);
        printf("%c ", node->data);
        printInorder(node->right);
    }
}

void printPreorder(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        printf("%c ", node->data);
        printPreorder(node->left);
        printPreorder(node->right);
    }
}
void printPostorder(struct node *node)
    {
    if (node == NULL)
        return;
    else
    {
        printPostorder(node->left);
        printPostorder(node->right);
        printf("%c ", node->data);
    }
}

int main()
{
    int l;
    printf("Enter number of elements: ");
    scanf("%d",&l);
    char s[l];
    printf("Enter postfix expression : ");
    scanf("%s",s);
    struct node *x, *y, *z;
    for (int i = 0; i < l; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'
            || s[i] == '/' || s[i] == '^') {
            z = newNode(s[i]);
            x = pop();
            y = pop();
            z->left = y;
            z->right = x;
            push(z);
        }
        else {
            z = newNode(s[i]);
            push(z);
        }
    }
    printf("The Inorder Traversal of Expression Tree: \n");
    printInorder(z);
    
    printf("\nThe Preorder Traversal of Expression Tree: \n");
    printPreorder(z);
    
    printf("\nThe Postorder Traversal of Expression Tree: \n");
    printPostorder(z);

    return 0;
}
