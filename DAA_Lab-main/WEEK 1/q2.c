//Creating adjacency matrix and adjacency list

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int v,n,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    int **m=(int**)malloc(v*sizeof(int*));
    for(i=0;i<v;i++)
        m[i]=(int*)malloc(v*sizeof(int));
    for(i=0; i<v; i++)
    {
        for(j=i;j<v;j++)
            {
                if(i==j)
                    m[i][j]=0;
                else
                {
                    printf("Edge present between %c and %c?(1/0): ",(65+i),(65+j));
                    scanf("%d",&n);
                    m[i][j]=n;
                    m[j][i]=n;
                }
            }
    }

    printf("\nAdjacency Matrix:\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            printf("%d  ",m[i][j]);
        printf("\n");
    }

    printf("\nAdjacency List:\n");
    for(i=0;i<v;i++)
    {
        printf("%c",(65+i));
        for(j=0;j<v;j++)
        {
            if(m[i][j]==1)
                printf("->%c",(65+j));
        }
        printf("\n");
    }
}
