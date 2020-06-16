#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int A[],int n)
{
    int itr,j,flag;
    for(itr=1;itr<=n-1;itr++)
    {
        flag=0;
        for(j=0;j<=n-1-itr;j++)
        {
            if(A[j]>A[j+1])
            {
                flag=1;        //tells one or more checking has been done
                swap(&A[j],&A[j+1]);
            }
        }
        //check if no comparison is done then break(coz array is sorted)
        if(flag==0)
            break;
    }
}

int main()
{
    int n,A[50],i;
    printf("Enter number of terms : ");
    scanf("%d",&n);
    printf("Enter Values in array\n");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&A[i]);
    }
    bubble_sort(A,n);
    printf("Sorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
