//MATRIX MULTIPLICATION
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a[20][20],b[20][20],c[20][20];
    int r1,c1,r2,c2,i,j,k;
    int oc=0;
    printf("Enter rows and columns of first and second matrix respectively: ");
    scanf("%d %d %d %d", &r1,&c1,&r2,&c2);
    if(c1!=r2)
    {
        printf("Multiplication not possible\n");
        exit(0);
    }
    printf("Enter elements of matrix 1: ");
    for(i=0; i<r1; i++)
        for(j=0; j<c1; j++)
            scanf("%d",&a[i][j]);

    printf("Enter elements of matrix 2: ");
    for(i=0; i<r2; i++)
        for(j=0; j<c2; j++)
            scanf("%d",&b[i][j]);
    
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
        {
            c[i][j]=0;
            for(k=0;k<c1;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
                oc++;
            }
        }

    printf("Resultant Matrix: \n");
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }

    printf("opcount: %d\n",oc);
}