//middle school method
#include<stdio.h>
void main()
{
    int m,n,opcount=0,gcd=1,i,a,b;
    printf("Enter 2 numbers: ");
    scanf("%d %d",&m,&n);
    a=m;
    b=n;
    for(i=2;i<=a && a>1 && b>1;)
    {
        opcount++;
        if(a%i==0 && b%i==0)
            {
                gcd=gcd*i;
                a/=i;
                b/=i;
            }
        else
            i++;
    }
    printf("Greatest common divisor: %d\n",gcd);
    printf("m+n: %d and opcount: %d\n",(m+n),opcount);
}

