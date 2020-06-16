#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int a[],int n)
{
    int i,j,min_index;
    for(i=0;i<n-1;i++)
    {
        min_index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
                min_index=j;
        }
        swap(&a[min_index],&a[i]);
    }
}

int main()
{
    int A[50];
    int n;
    int i;
    printf("enter number of terms(<50)\n");
    scanf("%d",&n);
    printf("enter values in array\n");

    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    selection_sort(A,n);

    for(i=0;i<n;i++)
        printf("%d ",A[i]);

    return 0;
}
