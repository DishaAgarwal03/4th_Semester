//kruskal's algo
//Write a program to find Minimum Cost Spanning Tree of a given undirected graph
//using Kruskal's algorithm and analyse its time efficiency

#include<stdio.h>
#include<stdlib.h>

int comparator(const void* p1, const void* p2)
{
    const int (*x)[3]=p1;
    const int (*y)[3]=p2;
    return (*x)[2] - (*y)[2];
}

void setval(int parent[],int rank[], int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(int parent[],int x)
{
    if(parent[x]==x)
        return x;
    return parent[x]=findParent(parent, parent[x]);
}

void unionset(int v1,int v2,int parent[],int rank[],int n)
{
    v1=findParent(parent, v1);
    v2=findParent(parent, v2);

    if(rank[v1]>rank[v2])
        parent[v2]=v1;
    else if(rank[v1]<rank[v2])
        parent[v1]=v2;
    else
    {
        parent[v2]=v1;
        rank[v1]++;
    }
    
}

void main()
{
    //src,dest,weight
    int edge[5][3]={{0,1,10},
                    {0,2,6},
                    {0,3,5},
                    {1,3,15},
                    {2,3,4}};
    int n=5, v1, v2, wt, minC=0;
    int parent[n], rank[n];

    qsort(edge, n, sizeof(edge[0]), comparator);        //sorting
    setval(parent,rank,n);      //initializing values

    for(int i=0;i<n;i++)
    {
        v1=findParent(parent,edge[i][0]);
        v2=findParent(parent,edge[i][1]);
        wt=edge[i][2];
        if(v1!=v2)
        {
            minC+=wt;
            printf("%d----%d  :  %d\n", edge[i][0],edge[i][1],wt);
            unionset(v1,v2,parent,rank,n);
        }
    }
    printf("Minimum cost of spanning tree: %d\n",minC);
}
