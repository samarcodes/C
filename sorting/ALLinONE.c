#include<stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void print_array(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

void bubble_sort(int a[],int n)
{
    int itr,j;
    int flag;
    for(itr=1;itr<=n-1;itr++)
    {
        flag=0;
        for(j=0;j<=n-1-itr;j++)
        {
            if(a[j]>a[j+1])
            {
                flag=1;
                swap(&a[j],&a[j+1]);
            }
        }
        if(flag==0)
            break;
    }
}

void selection_sort(int a[],int n)
{
    int i,j;
    int min_index;
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

void insertion_sort(int a[],int n)
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1 ; j>=0 && temp<a[j] ; j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}

void merge_sort(int a[],int s,int e)
{
    int mid;

    if(s>=e)
        return;

    mid=(s+e)/2;

    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);

    merge(a,s,e);
}

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

    for(i=0;i<=e;i++)
    {
        a[i]=temp[i];
    }
}

void quick_sort(int a[],int s,int e)
{
    int p;

    if(s>=e)
        return;

    p=partition(a,s,e);

    quick_sort(a,s,p-1);
    quick_sort(a,p+1,e);
}

int partition(int a[],int s,int e)
{
    int i=s-1;
    int j=s;
    int pivot;

    pivot=a[e];

    for(;j<e;)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
        j+=1;
    }
    swap(&a[i+1],&a[e]);
    return i+1;
}

int main()
{
    int a[]={5,7,3,8,2,0,9,1,2,7,3};
    int n=sizeof(a)/sizeof(a[0]);
    //bubble_sort(a,n);
    //selection_sort(a,n);
    //insertion_sort(a,n);
    //merge_sort(a,0,n-1);
    //quick_sort(a,0,n-1);
    print_array(a,n);
    return 0;
}
