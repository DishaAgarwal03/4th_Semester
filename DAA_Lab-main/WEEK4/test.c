#include <stdio.h>
void main()
{
    int a[]={1,2,3,4,5},b[5];
    b=a;
    a[2]=10;
    for(int i=0;i<5;i++)
        printf("%d  ",b[i]);
}