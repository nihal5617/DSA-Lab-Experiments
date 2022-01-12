/*Write a program to construct Binary Search Tree and perform following operations on it.
a.	Given pointers to two nodes, find the lowest common ancestor (LCA). Assume that both values already 
    exist in the tree. 
b.	Find the kth smallest element.
c.	Check the given BST is balanced or not.
d.	Print all the elements in the range K1 and K2*/

#include <stdio.h> 
#include <stdlib.h> 

struct node{ 
    float data; 
    struct node *left; 
    struct node *right; 
}; 
struct node *create(float data){ 
    struct node *tree = (struct node *)malloc(sizeof(struct node)); 
    tree->data = data; 
    tree->left = NULL; 
    tree->right = NULL; 
    return tree; 
} 
struct node *insert(struct node *root, float data){ 
    if (root == NULL) 
        root = create(data); 
    else if (data < root->data) 
        root->left = insert(root->left, data); 
    else 
        root->right = insert(root->right, data); 
    return root; 
} 
//1)LCA
struct node *prev;
struct node *findlca(struct node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    // If both n1 and n2 are smaller
    // than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
    {
        prev = root;
        return findlca(root->left, n1, n2);
    }
    // If both n1 and n2 are greater than
    // root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
    {
        prev = root;
        return findlca(root->right, n1, n2);
    }
    // If both above condition are false than
    // the current node is the answer
    // if the current node is equal to either
    // value than previous node is answer
    if (root->data != n1 && root->data != n2)
        return root;
    // If previous node is null it means
    // one of the values is the head
    if (prev == NULL)
        return root;
    return prev;
}

//2)kth smallest element
int ansIs(struct node * root,int *k){
    if(root==NULL) return 0;
    int left=ansIs(root->left,k);
    if(left!=0)
        return left;
    *k=*k-1;
    if(*k==0){
        return root->data;
    }
    int right=ansIs(root->right,k);
    return right;
}
int kthsmallest(struct node *root ,int k){

    return ansIs(root,&k);
}
//3)balanced
int max(int a, int b)
{
    return (a >= b) ? a : b;
}
int height(struct node* root)
{
    /* base case tree is empty */
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}
int isBalanced(struct node* root)
{
    int lh; 
    int rh;

    if (root == NULL)
        return 1;

    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}
//4) elements between k1 and k2
void printbetweenk1andk2(struct node * root,int *k1,int *k2){
    if(root==NULL) return;
    printbetweenk1andk2(root->left,k1,k2);
    *k2=*k2-1;
    *k1=*k1-1;
    if(*k1<=0&&*k2>=0){
        printf("\t%.0f",root->data);
    }
    printbetweenk1andk2(root->right,k1,k2);
    return;
}

int main(){ 
    int n,n1,n2,k,k1,k2; 
    struct node *subtree = NULL,*lca; 
    printf("Enter number of elements in array:"); 
    scanf("%d", &n); 
    int arr[n]; 
    printf("Enter elements of array:"); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
        subtree = insert(subtree, arr[i]);
    }
    
    printf("\nTo find LCA \nEnter LCA of what you want : ");
    scanf("%d %d",&n1,&n2);
    lca=findlca(subtree,n1,n2);
    printf("\nLCA of %d and %d is %.1f ",n1,n2,lca->data);
    
    printf("\nTo find kth smallest term \nEnter k : ");
    scanf("%d",&k);
    printf("\nkth Smallest element is : %d",kthsmallest(subtree,k));
    
    if(isBalanced(subtree))
        printf("\nTree is balanced");
    else
        printf("\nTree is not balanced");
     
    printf("\nEnter k1 & k2 : ");
    scanf("%d %d",&k1,&k2); 
    printbetweenk1andk2(subtree,&k1,&k2);
    
    return 0;
}
