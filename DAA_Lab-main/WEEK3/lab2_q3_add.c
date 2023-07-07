//NTH FIBONACCI NUMBER USING RECURSION
#include<stdio.h>

int fibo(int n, int *oc)
{
    (*oc)++;
    if(n==0 || n==1)
        return n;
    return fibo(n-1,oc)+fibo(n-2,oc);
}

void main()
{
    int n, oc=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("nth fibonacci number is %d\n",fibo(n,&oc));
    printf("opcount: %d\n",oc);
}