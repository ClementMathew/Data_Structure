
// Implementation of Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * root = NULL;

struct Node * Insert();
struct Node * Delete(struct Node *,int );
void Inorder(struct Node *);
void Postorder(struct Node *);
void Preorder(struct Node *);

struct Node * Queue[50];
int front = -1, rear = -1;

void push(struct Node * x)
{
    if(front == -1)
    {
       front++;
    }
    rear++;
    Queue[rear] = x;
}

void pop()
{
    front++;
    if(front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void main()
{
    int k = 0, c, x;
    
    while(k == 0)
    {
        printf("1 - Insert\n2 - Inorder Display\n3 - Preorder Display");
        printf("\n4 - Postorder Display\n5 - Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: root = Insert();
                    break;

            case 2: Inorder(root);
                    printf("\n");
                    break;

            case 3: Preorder(root);
                    printf("\n");
                    break;

            case 4: Postorder(root);
                    printf("\n");
                    break;

            case 5: k = 1;
                    break;

            default : printf("\nYou entered wrong choice");
                      break;
        }
    }
}

struct Node * Insert()
{
    int y;
    struct Node * newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter data (-1 for prev) : ");
    scanf("%d",&y);
    if(y == -1)
    {
        return 0;
    }
    newnode->data = y;
    printf("\nEnter the left child of %d : ",y);
    newnode->left = Insert();
    printf("\nEnter the right child of %d : ",y);
    newnode->right = Insert();
    return newnode;
}

void Inorder(struct Node* node)
{
    if(node != NULL)
    {
        Inorder(node->left);
        printf("%d\t",node->data);
        Inorder(node->right);
    }
}
void Postorder(struct Node* node)
{
    if(node != NULL)
    {
        Postorder(node->left);
        Postorder(node->right);
        printf("%d\t",node->data);
    }
}
void Preorder(struct Node* node)
{
    if(node != NULL)
    {
        printf("%d\t",node->data);
        Preorder(node->left);
        Preorder(node->right);
    }
}