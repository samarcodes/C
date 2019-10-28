#include<stdio.h>
void quick(int A[],int N,int BEG,int END,int *LOCPTR)
{
    int LEFT,RIGHT,temp;
    LEFT=BEG; RIGHT=END;
    *LOCPTR=BEG;

step2:
    while(A[*LOCPTR]<=A[RIGHT] && *LOCPTR!=RIGHT)
        RIGHT--;
    if(A[*LOCPTR]==A[RIGHT])
        return;
    if(A[*LOCPTR]>A[RIGHT])
    {
        temp=A[*LOCPTR];
        A[*LOCPTR]=A[RIGHT];
        A[RIGHT]=temp;
        *LOCPTR=RIGHT;
    }
    goto step3;
step3:
    while(A[LEFT]<=A[*LOCPTR] && LEFT!=*LOCPTR)
    {
        LEFT++;
    }
    if(*LOCPTR==LEFT)
        return;
    if(A[LEFT]>A[*LOCPTR])
    {
        temp=A[LEFT];
        A[LEFT]=A[*LOCPTR];
        A[*LOCPTR]=temp;
        *LOCPTR=LEFT;
    }
    goto step2;
}
void quick_sort(int A[],int n)
{
    int BEG,END,LOC;
    int TOP=-1;
    int LOWER[20],UPPER[20];
    if(n>1)
    {
        TOP+=1;
        LOWER[TOP]=0;
        UPPER[TOP]=n-1;
    }
    while(TOP!=-1)
    {
        BEG=LOWER[TOP];
        END=UPPER[TOP];
        TOP--;
        quick(A,n,BEG,END,&LOC);
        if(BEG<LOC-1)
        {
            TOP++;
            LOWER[TOP]=BEG;
            UPPER[TOP]=LOC-1;
        }
        if(LOC+1<END)
        {
            TOP++;
            LOWER[TOP]=LOC+1;
            UPPER[TOP]=END;
        }
    }
}
int main()
{
    int A[]={55,3,7,2,9,0,1};
    quick_sort(A,7);
    for(int i=0;i<7;i++)
        printf("%d ",A[i]);
    return 0;
}
