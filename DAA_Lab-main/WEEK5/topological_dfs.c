#include<stdio.h>

int g[100][100];
int V,t=-1,top=-1;
int visited[100], A[100];
char s[100];

void tdfsv(int v)
{
    int j;
    A[++top]=v;
    visited[v]=1;
    for(j=0;j<V;j++)
    {
        if(!visited[j] && g[v][j] && v!=j)
            tdfsv(j);
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
            s[++t]=(char)(A[top--]+65);
    }
}

void main()
{
	int i, j;
	printf("Enter the Number of Vertices : ");
	scanf(" %d", &V);
	printf("Enter the Adjacency Matrix: \n");
	
	for (i = 0; i < V; ++i)
		for (j = 0; j < V; ++j)
			scanf(" %d", &g[i][j]);		
    printf("Topological sort using Depth-First technique:  ");
	tdfs();
    for(i=t;i>=0;i--)
        printf("%c  ",s[i]);
}