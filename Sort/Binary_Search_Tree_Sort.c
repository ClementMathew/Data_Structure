
// Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *NewNode(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *root, int x)
{
    if (root == NULL)
    {
        root = NewNode(x);
    }
    else if (root->data >= x)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }
    return root;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int x, n;
    printf("Enter no. of elements : ");
    scanf("%d", &n);

    printf("Enter the elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Sorted order is : ");
    inOrder(root);
}