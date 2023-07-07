#include<stdio.h>

int g[5][5]={{0,0,1,0,0},{0,0,1,0,0},{0,0,0,1,1},{0,0,0,0,1},{0,0,0,0,0}}	;;
int V=5,t=-1;
int visited[100], A[100], top=-1;
char s[100];

void tdfsv(int v)
{
    char x;
    int j;
    A[++top]=v;  //push
    visited[v]=1;
    for(j=0;j<V;j++)
    {
        if(!visited[j] && g[v][j] && v!=j)
            tdfsv(j);
        
        // //s[++t]=(char)(A[top--]+65);
        // if(top!=-1)
        // printf("%c ",A[top--]+65);  //pop
    }

}

void tdfs()
{
    int i;
    for(i=0;i<V;i++)
    {
        if(!visited[i])
            tdfsv(i);
        while(top!=-1)
            printf("%c ",A[top--]+65);
    }
}

void main()
{
	int i, j;
	//printf("Enter the Number of Vertices : ");
	//scanf(" %d", &V);
	//printf("Enter the Adjacency Matrix: \n");
	
    //printf("Topological sort using Depth-First technique:  ");
	tdfs();
    // for(i=t;i>=0;i--)
    //     printf("%c  ",s[i]);
}