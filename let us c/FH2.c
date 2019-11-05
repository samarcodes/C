#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    FILE *fs,*ft;
    char s[50];

    fs=fopen("source.txt","r");
    if(fs==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }

    ft=fopen("target.txt","a");
    if(ft==NULL)
    {
        puts("Cannot Open File...");
        fclose(fs);
        exit(2);
    }

    while(fgets(s,50,fs)!=NULL)
    {
        fputs(s,ft);
    }
    fclose(fs);
    fclose(ft);
    return 0;
}

