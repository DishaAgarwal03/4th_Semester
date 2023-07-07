#include<stdio.h>

int g[100][100];
int V;
int indeg[100];

void tsrsv(int i)
{
	int j;
	for(;i<V;i++)
		{
			if(indeg[i]==0)
			{
				printf("%c ",i+65);
				indeg[i]--;
				for(j=0;j<V;j++)
				{
					if(g[i][j])
						indeg[j]--;
				}
			}
		}
}

void tsrs()
{
    int i;
	for(i=0;i<V;i++)
	{
		if(indeg[i]!=-1)
			tsrsv(i);
	}
}

void main()
{
	int i, j;
	printf("Enter the Number of Vertices : ");
	scanf(" %d", &V);
	printf("Enter the Adjacency Matrix: \n");
	
	for (i = 0; i < V; ++i)
	{
		indeg[i]=0;
		for (j = 0; j < V; ++j)
			scanf(" %d", &g[i][j]);
	}		

	for(j=0;j<V;j++)
		for(i=0;i<V;i++)
				indeg[j]+=g[i][j];

    printf("Topological sort using Source Removal technique:  ");
	tsrs();
}