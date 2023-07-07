//floyd's algorithm
//cannot use max_int in limits.h w/o conditions since adding two max_ints will give wrong output 
#include<stdio.h>
#define min(a,b) (a<b?a:b)
void main()
{
    int a[4][4]={{0,1000,3,1000},{2,0,1000,1000},{1000,7,0,1},{6,1000,1000,0}};
    int i,j,k,n=4,x,y;

    //taking input
    // printf("Enter the size: ");
    // scanf("%d",&n);
    // printf("Enter the elements:\n");
    // for(i=0;i<n;i++)
    //     for(j=0;j<n;j++)
    //         scanf("%d",&a[i][j]);


    //floyd's algo
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                x=a[i][j];
                y=a[i][k] + a[k][j];
                a[i][j]=min(x,y);

                //if infinity=-1:

                //wrong:
                // if(x>-1 && y>-1)    a[i][j]=min(x,y);
                // else if(y>-1)   a[i][j]=y;    //doesn't work since a[i][k] and a[k][j] need not be >-1 separately if checking y
                // else    continue;

                //correct:
                // if(x>-1 && a[i][k]>-1 && a[k][j]>-1)  a[i][j]=min(x,y);
                // else if(a[i][k]>-1 && a[k][j]>-1) a[i][j]=y;    
                // else    continue;
                
                
            }
    }
    //displaying
    printf("All-pairs shortest paths:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}