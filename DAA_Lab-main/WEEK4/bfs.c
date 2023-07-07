#include <stdio.h>
#include <stdlib.h>

int g[100][100];
int V;
int visited[100];
int queue[100], f = 0, r = 0;

void enqueue(int v)
{
	queue[r++] = v;
}

int dequeue()
{
	if(f == r)
	{
		return -1;
	}
	
	return queue[f++];
}

void bfsv(int v)
{
	printf("%c  ", (v+65));
	visited[v] = 1;
	
	int i;
	
	for(i = 0; i < V; ++i)
	{
		if(!visited[i] && g[v][i] && i != v)
		{
			enqueue(i);
		}
	}
}

void bfs()
{
	int i, x;
	enqueue(0);
	
	do
	{
		x = dequeue();
		
		if(x != -1 && !visited[x])
		{
			bfsv(x);
		}
	}while (x != -1);
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
    printf("BFS order: ");
	bfs();

}