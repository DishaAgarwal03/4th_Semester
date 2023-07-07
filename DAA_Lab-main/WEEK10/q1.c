//warshall's algorithm
#include<stdio.h>
void main()
{
    int a[10][10];
    int i,j,k,n;
    //taking input
    printf("Enter the size: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    //warshall's algo
    for(k=0;k<n;k++)
    {
        //b=a;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
    }
    //displaying
    printf("Transitive Closure:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}