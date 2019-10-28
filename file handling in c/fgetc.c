#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch;
    fp=fopen("file.txt","r");
    if(fp==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }
    while(1)
    {
        ch=fgetc(fp);
        if(ch==EOF)
            break;
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}

