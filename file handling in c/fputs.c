#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;
    char s[100];
    fp=fopen("str.txt","w");
    if(fp==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }
    while(strlen(gets(s))>0)
    {
        fputs(s,fp);
        fputs("\n",fp);
    }
    fclose(fp);
    return 0;
}

