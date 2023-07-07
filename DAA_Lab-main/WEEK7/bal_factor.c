#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b?a:b)

typedef struct NODE* node;
struct NODE
{
    int d;
    node l,r;
}NODE;

node getnode(int x)
{
    node temp=(node)malloc(sizeof(struct NODE));
    temp->d=x;
    temp->l=temp->r=NULL;
}

node create(node root,int x)
{
    if(root==NULL)
        return getnode(x);
    else if(x>root->d)
        root->r=create(root->r,x);
    else if(x<root->d)
        root->l=create(root->l,x);
    else
    {
        printf("Duplicate node\n");
        exit(0);
    }
    return root;
}

int height(node root)
{
    if(root)
        return max(height(root->l),height(root->r))+1;
    else 
        return 0;
}

int findbal(node root)
{
    return height(root->l)-height(root->r);
}

void inorder(node root)
{
    if(root)
    {
        inorder(root->l);
        printf("Balance factor of %d is %d\n",root->d,findbal(root));`
        //printf("%d ",root->d);
        inorder(root->r);
    }
}

void main()
{
    node root=create(NULL,6);
    root=create(root,4);
    root=create(root,7);
    root=create(root,3);
    root=create(root,5);
    root=create(root,10);
    root=create(root,9);
    inorder(root);
}