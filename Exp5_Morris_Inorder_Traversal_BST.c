/*Write a program to compute the median of an array A[1...n] of distinct numbers using atmost n+1 
comparisons. Use a decision tree: a binary tree where each internal node is a comparison of the 
form A[i] < > A[j] and each leaf is an index into the array.*/

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
float Median(struct node *root, int n){ //Morris Inorder Traversal
    if (root == NULL)
        return 0;
    int count = 0;
    struct node *curr = root, *predecessor, *parent;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            // count current node
            count++;
            // Check if current node is the median
            if (n % 2 != 0 && count == (n + 1) / 2) //Odd
                return curr->data;
            else if (n % 2 == 0 && count == (n / 2) + 1) //Even
                return (parent->data + curr->data) / 2;
            parent = curr;
            curr = curr->right;
        }
        else
        {
            // Find inorder predecessordecessor of curr
            predecessor = curr->left;
            while (predecessor->right != NULL && predecessor->right != curr)
                predecessor = predecessor->right;
                // Make current right child
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                parent = predecessor;
                // count current node
                count++;
                // Check if current node is the median
                if (n % 2 != 0 && count == (n + 1) / 2) //Odd
                     return curr->data;
                else if (n % 2 == 0 && count == (n / 2) + 1) //Even
                     return (parent->data + curr->data) / 2;
                parent = curr;
                curr = curr->right;
            }
        }
    }
}
int main(){
    int n;
    struct node *subtree = NULL;
    printf("Enter number of elements in array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        subtree = insert(subtree, arr[i]);
    }
    printf("The Median Is: %.1f", Median(subtree, n));
    return 0;
}
