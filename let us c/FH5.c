#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fs1,*fs2,*ft;
    char s1[50];
    char s2[50];
    fs1=fopen("source.txt","r");
    if(fs1==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }

    fs2=fopen("source1.txt","r");
    if(fs2==NULL)
    {
        puts("Cannot Open File...");
        fclose(fs1);
        exit(2);
    }

    ft=fopen("target.txt","w");
    if(ft==NULL)
    {
        puts("Cannot Open File...");
        fclose(fs1);
        fclose(fs2);
        exit(3);
    }

    fclose(fs1);
    fclose(fs2);
    fclose(ft);
    return 0;
}
