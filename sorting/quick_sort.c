#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int s,int e)
{
    //Inplace (Cant take extra array)
    int i=s-1;
    int j=s;

    int pivot=a[e];

    for(;j<=e-1;)
    {
        if(a[j]<=pivot)
        {
            //merge the smaller element in region 1
            i+=1;
            swap(&a[i],&a[j]);
        }
        //expand the larger region
        j+=1;
    }
    swap(&a[i+1],&a[e]);
    return i+1;
}

void quick_sort(int a[],int s ,int e)
{
    int p;

    //base case
    if(s>=e)
        return;

    //recursive case
    p=partition(a,s,e);
    //left part
    quick_sort(a,s,p-1);
    //right part
    quick_sort(a,p+1,e);
}

int main()
{
    int i;
    int a[]={5,7,0,2,6,1,55};
    int n=sizeof(a)/sizeof(a[0]);

    quick_sort(a,0,n-1);

    //print the array
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

	return 0;
}
