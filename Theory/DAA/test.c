#include<stdio.h>
void main()
{
    int n;
    float f,l,m;
    printf("Enter a number: ");
    scanf("%d",&n);
    f=0; l=n;
    while(f<=l)
    {
        
        m=((float)(f+l))/2;
        printf("%f\n",m);
        if(m*m==n || ((int)m*1000)%10==0)
        {
            printf("square root value: %f",m);
            break;
        }
        else if(n>(m*m))
            f=m;
        else
            l=m;
    }
}