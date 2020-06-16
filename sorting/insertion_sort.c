#include<stdio.h>

void insertion_sort(int A[],int N)
{
    int i,j,temp;
    for(i=1;i<N;i++)
    {
        temp=A[i];
        for(j=i-1;j>=0 && temp<A[j];j--)
        {
            A[j+1]=A[j];
        }
        A[j+1]=temp;
    }
}

int main()
{
    int A[50],n,i;
    printf("enter no of values\n");
    scanf("%d",&n);
    printf("enter values in array\n");

    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    insertion_sort(A,n);

     for(i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}
