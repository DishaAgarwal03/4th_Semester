
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* a, int x, int y)
{
	int temp;
	temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int summ(int pj[][20], int* a, int n)
{
    int s=0;
    for(int i=0;i<n;i++)
    {
        s+=pj[i][a[i]];
    }
    return s;
}

void permute(int xx[],int s[], int pj[][20], int a[], int l, int r, int n)
{
	static int x=0, min;
    int sum,i;
	if (l == r)
	{
		/*for(i=0;i<n;i++)
			printf("%d  ",a[i]);
		printf("\n");*/
        sum=summ(pj,a,n);
        if(x==0)
            {
                min=sum;
                for(i=0;i<n;i++)
                    xx[i]=a[i];
                x++;
            }
        else if(min>sum)
            {
                min=sum;
                for(i=0;i<n;i++)
                    xx[i]=a[i];
            }
        
	}
	else {
		for (i = l; i <= r; i++) {
			swap(a, l, i);
			permute(xx, s, pj, a, l + 1, r, n);
			swap(a, l, i); 
		}
	}
}

void main()
{
	int a[20],pj[20][20],s[20],xx[20];
	int i,j,n;
	printf("Enter limit: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
        a[i]=i;
	for(i=0;i<n;i++)
	{
		printf("Enter time taken for jobs 1-n by person %d: ",i+1);
		for(j=0;j<n;j++)
		{
			scanf("%d",&pj[i][j]);
		}
	}
	permute(xx, s, pj, a, 0, n - 1, n);
    printf("Minimum values: ");
    for(i=0;i<n;i++)
        printf("%d  ",pj[i][xx[i]]);
    printf("\nMinimum sum: %d\n",summ(pj,xx,n));
}
