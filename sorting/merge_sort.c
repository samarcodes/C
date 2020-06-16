#include<stdio.h>
void merge(int a[],int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;

    int temp[100];

    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=e)
        temp[k++]=a[j++];

    for(i=s;i<=e;i++)
        a[i]=temp[i];
}

void merge_sort(int a[],int s,int e)
{
    int mid;
    count++;
    if(s>=e)
        return;

    mid=(s+e)/2;

    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);

    merge(a,s,e);
}

int main()
{
    int i;
    int a[]={5,4,3,6,2,0,1};
    int n=sizeof(a)/sizeof(a[0]);
    merge_sort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("\n%d ",a[i]);
    return 0;
}
