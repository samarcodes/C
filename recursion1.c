#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void prime_factors(int);
int main()
{
    int num;
    int i;
    printf("Enter Positive Integer");
    scanf("%d",&num);
    prime_factors(num);
    return 0;
}
void prime_factors(int n)
{
    int i;
    if(n==0)
    {
        exit(0);
    }
    else if(n==1)
    {
        printf("1");
    }

    while(n%2==0)
    {
        printf("2 ");
        n/=2;
    }
    for(i=3;i<sqrt(n);i+=2)
    {
        while(n%i==0)
        {
            printf("%d ",i);
            n/=i;
        }
    }
    if(n>2)
        printf("%d",n);
}
