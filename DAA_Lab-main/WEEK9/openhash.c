//open hashing
//hash function: h(k)=k%5
//n keys, m cells, alpha=n/m
#include<stdio.h>
#include<stdlib.h>

typedef struct Node* node;
struct Node{
    int d;
    node r; 
};

node getnode(int x)
{
    node temp=(node)(malloc(sizeof(struct Node)));
    temp->r=NULL;
    temp->d=x;
}

void search(node b[], int x)
{
    int op=0;
    int h=x%5;
    node cur=b[h]->r;
    while(cur)
    {
        op++;
        if(cur->d==x) 
        {
            printf("Found %d\nopcount: %d\n",x,op);
            return;
        }
        cur=cur->r;
    }
    printf("%d not found\nopcount: %d\n",x,op);
}

void main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int i,h;
    node b[5];

    //creating table
    int m=5, n=10;
    for(i=0;i<m;i++)
        b[i]=getnode('x');

    for(i=0;i<n;i++)
    {
        h=a[i]%5;
        node cur=b[h];
        while(cur->r)
            cur=cur->r;
        cur->r=getnode(a[i]);
    }

    //displaying
    for(i=0;i<m;i++)
    {   
        printf("%d| ",i);
        node cur=b[i]->r;
        while(cur)
        {
            printf("-> %d ",cur->d);
            cur=cur->r;
        }
        printf("\n");
    }

    //searching
    search(b,2);
    search(b,11);
}