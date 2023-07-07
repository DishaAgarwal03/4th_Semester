//dijkstra's algo
//Write a program to find shortest path from a given vertex to other vertices in a given
//weighted connected graph, Using Dijkstra's algorithm and analyse its time efficiency.

#include<stdio.h>
#include<limits.h>
#define V 9

int mindist(int dist[], int iset[])
{
    int min=INT_MAX, minidx;
    for(int i=0;i<V;i++)
    {
        if(!iset[i] && dist[i]<min)
            min=dist[i],minidx=i;
    }
    return minidx;
}

void dijkstra(int a[][V], int src)
{
    int dist[V], iset[V];
    int i;
    for(i=0;i<V;i++)
        iset[i]=0, dist[i]=INT_MAX;
    dist[src]=0;
    for(i=0;i<V-1;i++)
    {
        int u=mindist(dist, iset);
        iset[u]=1;
        for(int j=0;j<V;j++)
        {
            if(!iset[j] && a[u][j] && dist[u]<INT_MAX && dist[u]+a[u][j]<dist[j])
                dist[j]=dist[u]+a[u][j];
        }
    }

    for(i=0;i<V;i++)
        printf("%c to %c  :  %d\n", src+65, i+65, dist[i]);
}

void main()
{
    int a[V][V]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                  { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                  { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                  { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                  { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                  { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                  { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                  { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                  { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(a,0);
}
