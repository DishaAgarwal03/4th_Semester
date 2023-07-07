//COUNT THE NUMBER OF NODES IN BINARY TREE

#include <stdio.h>
#include <stdlib.h>

typedef struct BT * Node;
struct BT
{
    int d;
    Node l;
    Node r;
};
int opcount=0;
Node getnode()
{
    return ((Node)malloc(sizeof(struct BT)));
}

Node create_BT(Node root,int d)
{
    int x;
    if(d!=-1)
    {
        Node temp=getnode();
        temp->d=d;

        printf("Enter lchild of %d : \t",temp->d);
        scanf("%d",&x);
        temp->l=create_BT(temp->l,x);

        printf("Enter rchild of %d : \t",temp->d);
        scanf("%d",&x);
        temp->r=create_BT(temp->r,x);
        return temp;
    }
    return NULL;
}

int inorder(Node root)
{
    static int c=0;
    opcount++;
    if(root)
    {
        inorder(root->l);
        c++;
        inorder(root->r);
    }
    return c;
}

void main(){
	Node Tree = NULL;
	Tree = create_BT(Tree,0);
	int c=inorder(Tree);
	printf("\nNumber of nodes: %d",c);
    printf("\nOpcount: %d\n",opcount);
}