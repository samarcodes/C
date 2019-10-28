#include<stdio.h>
#include<conio.h>
int min(int [],int,int);  //to find min value from array
int main()
{
    int A[50],n,k,LOC,i,temp;
    printf("enter number of terms(<50)\n");
    scanf("%d",&n);
    printf("enter values in array\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    for(k=0;k<=n-2;k++)
    {
        LOC=min(A,k,n);
        temp=A[k];
        A[k]=A[LOC];
        A[LOC]=temp;
    }
    for(i=0;i<n;i++)
        printf("%d ",A[i]);

}

int min(int A[],int k,int n)
{
    int LOC,MIN,j;
    MIN=A[k];
    LOC=k;
    for(j=k+1;j<=n-1;j++)
    {
        if(MIN>A[j])
        {
            MIN=A[j];
            LOC=j;
        }
    }
    return (LOC);
}
