#include <stdio.h>
#include <stdlib.h>

int g[100][100];
int V, top=-1, P[100];
int visited[100];


void dfsv(int v)
{
    P[++top]=v;
	visited[v] = 1;
	
	int i;
	
	for(i = 0; i < V; ++i)
	{
		if(!(visited[i]) && (g[v][i] == 1) && (i != v))
		{
  			dfsv(i);
		}
	}
    printf("%c  ",(65+v));
}

void dfs()
{
	int i;
	
	for(i = 0; i < V; ++i)
	{
		if(!visited[i])
		{
  			dfsv(i);
		}
	}
}

void main()
{
	printf("Enter the Number of Vertices: \n");
	scanf("%d", &V);
	
	int i, j;
	
	printf("Enter the Adjacency Matrix: \n");
	
	for(i = 0; i < V; ++i)
	{
		for(j = 0; j < V; ++j)
		
		scanf(" %d", &g[i][j]);
	}
	printf("\nPop order: ");
	dfs();
    printf("\nPush order: ");
    for(i=0;i<=top;i++)
        printf("%c  ",(P[i]+65));
}