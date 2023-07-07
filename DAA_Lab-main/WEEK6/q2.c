//QUICKSORT

/*
initialize: 
    low(first index) and high(last index)
    k=high
    pivot=a[low]
for i from high->low+1
    if a[i]>pivot
        swap a[i] and a[k]
        k--
swap a[low] i.e pivot and a[k]
*/

#include<stdio.h>
#include<stdlib.h>

int n,opcount=0;
void swap(int a[], int x, int y)
{
    int t=a[x];
    a[x]=a[y];
    a[y]=t;
}

int partition(int a[], int low, int high)
{
    int k=high;
    int pivot=a[low];
    for(int i=high; i>low; i--)
    {
        if (a[i]>pivot)
            {
                swap(a,i,k);
                k--;
            }
    }
    swap(a,low,k);
    return k;
}

void quicksort(int a[], int low, int high)
{
    opcount++;
    if(low<high) 
    {
        int idx=partition(a,low,high);         //index of pivot element in sorted position
        quicksort(a,low,idx-1);
        quicksort(a,idx+1,high);
    }
}

void main()
{
    int a[]={0,7,80,100,44,10,6,5,2,8,7,1};
    n=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\nOpcount: %d \n",opcount);
}