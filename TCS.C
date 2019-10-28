#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int Q,i,j,P,flag,arr[10000];
    int N;
    char S[500000];
    scanf("%d",&N);
    scanf("%s",S);
    scanf("%d",&Q);
    if(N>=1&&N<=500000&&Q>=1&&Q<=10000&&strlen(S)==N)
    {
        for(i=0;i<Q;i++)
        {
            flag=0;
            scanf("%d",&P);
            for(j=0;j<P-1;j++)
            {
                if(S[j]==S[P-1])
                flag+=1;
            }
            arr[i]=flag;
        }
        for(i=0;i<Q;i++)
        printf("%d\n",arr[i]);
    }
    return 0;
}
