#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char s[50];
    int i=0;

    fp=fopen("source.txt","r");
    if(fp==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }

    while(fgets(s,50,fp)!=NULL)
    {
        i++;
        printf("%d %s",i,s);
    }
    fclose(fp);
    return 0;
}

