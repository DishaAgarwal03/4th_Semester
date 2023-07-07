//consecutive integer checking method
#include<stdio.h>
void main()
{
    int m,n,opcount=0,k,gcd=1;
    printf("Enter 2 numbers: ");
    scanf("%d %d",&m,&n);
    k= m<n?m:n;
    for(int i=k;i>1;i--)
    {
        opcount++;
        if(m%i==0 && n%i==0)
            {
                gcd=i;
                break;
            }
    }
    printf("Greatest common divisor: %d\n",gcd);
    printf("m+n: %d and opcount: %d\n",(m+n),opcount);
}
