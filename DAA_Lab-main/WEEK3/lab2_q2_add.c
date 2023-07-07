//TOWER OF HANOI
#include<stdio.h>

int toh(int n, char src, char temp, char dst)
{
    static int oc=0;
    oc++;
    if(n==1)
    {
        printf("%c to %c\n",src,dst);
        return oc;
    }
    toh(n-1,src,dst,temp);
    printf("%c to %c\n",src,dst);
    toh(n-1,temp,src,dst);
}

void main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("opcount: %d\n",toh(n,'A','B','C'));
}