//Creating BST and printing in VLR,LVR,LRV
#include<stdio.h>
#include<stdlib.h>

typedef struct Node* node;
typedef struct Node
{
    node l,r;
    int data;
}Node;

node getnode(int x)
{
    node temp;
    temp=(node)malloc(sizeof(Node));
    temp->l=temp->r=NULL;
    temp->data=x;
    return temp;
}

void insert(node *list, int x)
{
    node cur=*list;
    node temp=getnode(x);
    if(*list==NULL)
    {
        *list=temp;
        return;
    }
    node prev=NULL;
    while(cur)
    {
        prev=cur;
        if(x<cur->data)
            cur=cur->l;
        else if(x>cur->data)
            cur=cur->r;
        else
            {
            printf("Key found!\n");
            return;
            }
    }
    if(x<prev->data)
        prev->l=temp;
    else
        prev->r=temp;
}

void inorder(node list)
{
    if(list)
    {
        inorder(list->l);
        printf("%d ",list->data);
        inorder(list->r);
    }
}

void postorder(node list)
{
    if(list)
    {
        postorder(list->l);
        postorder(list->r);
        printf("%d ",list->data);
    }
}

void preorder(node list)
{
    if(list)
    {
        printf("%d ",list->data);
        preorder(list->l);
        preorder(list->r);
    }
}

void main()
{
    node root=NULL;
    char c='Y';
    int n;
    while(c=='Y'||c=='y')
    {
        printf("Enter data: ");
        scanf("%d",&n);
        insert(&root,n);
        getchar();
        printf("Continue?(Y/N): ");
        scanf("%c",&c);
    }

    printf("\nEnter key to search: ");
    scanf("%d",&n);
    insert(&root,n);

    printf("\nPreorder: \n");
    preorder(root);
    printf("\nInorder: \n");
    inorder(root);
    printf("\nPostorder: \n");
    postorder(root);
}
