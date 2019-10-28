//5 digit sum using recursion
#include<stdio.h>
#include<conio.h>
int sum_of_digits(int);
int main()
{
    int num;
    int sum;
    printf("Enter 5 digit number : ");
    scanf("%d",&num);
1    if(num>=10000 && num<100000)
    {
    sum=sum_of_digits(num);
    printf("%d",sum);
    }
}
int sum_of_digits(int n)
{
    /*int temp_num;
    int i;
    int sum=0;
    if(n>=10000 && n<100000)
    {
        temp_num=n;
        for(i=0;i<5;i++)
        {
            sum+=temp_num%10;
            temp_num/=10;
        }
        return(sum);
    }
    else
    {
        printf("Enter Five Digit Number ");
        return 0;
    }*/
    int temp_num;
    int rem;
    int sum=0;
    temp_num=n;
    rem=temp_num%10;
    if(temp_num>0)
    {
        temp_num/=10;
        sum=rem+sum_of_digits(temp_num);
        return sum;
    }
}
