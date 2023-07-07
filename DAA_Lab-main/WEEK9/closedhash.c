//h(k)=k%6
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int d;  //data
    int c;  //counter
} cell;

int op=0;

int search(cell hash[], int m, int x)
{
    op++;
    int h=x%6;
    if(hash[h].d==x){printf("opcount: %d\n",op);
        return 1;}
    else if(hash[h].c==1){printf("opcount: %d\n",op);
        return 0;}
    else
    {
        int i=h+1;
        while(i!=h){
            op++;
            if(hash[i++].d==x){printf("opcount: %d\n",op);return 1;}
                
            if(i==m)
                i=0;
        }
    }
    printf("opcount: %d\n",op);
    return 0; 
}

void main()
{
    int h, n=10, m=15, i, j;
    int a[]={1,2,3,4,5,6,7,8,9,10};    //n=10
    cell hash[15];                     //m=15

    if(m<n)
        exit(0);

    for(i=0;i<m;i++)
        hash[i].c=0;

    //creating table
    for(i=0;i<n;i++)
    {
        h=a[i]%6;
        if(hash[h].c==0)
        {
            hash[h].d=a[i];
            (hash[h].c)++;
        }
        else 
        {
            (hash[h].c)++;

            int l=h+1;
            while(l!=h)
            {
                if(hash[l].c==0)
                    {
                        hash[l].d=a[i];
                        (hash[l].c)++;
                        break;
                    }
                l++;
                if(l==m)
                    l=0;
            }
        // }
        //     for(j=h+1;hash[j].c==0;j++);
        //     hash[j].d=a[i];
        //     (hash[j].c)++;
        }
    }

    //displaying
    for(i=0;i<m;i++)
        if(hash[i].c>0)
            printf("%d : %d\n",i,hash[i].d);

    //searching
    for(i=10;i<12;i++)
    {
        if(search(hash,m,i))
            printf("Found %d\n",i);
        else
            printf("%d not found\n",i);
    }
}