#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;
    char s[100];
    fp=fopen("str.txt","r");
    if(fp==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }
    while(fgets(s,100,fp)!=NULL)
    {
        printf("%s",s);
    }
    fclose(fp);
    return 0;
}