#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    FILE *fs,*ft;
    char c;

    fs=fopen("source.txt","r");
    if(fs==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }

    ft=fopen("target.txt","w");
    if(ft==NULL)
    {
        puts("Cannot Open File...");
        fclose(fs);
        exit(1);
    }

    while(1)
    {
        c=fgetc(fs);
        if(c==EOF)
            break;
        fputc(toupper(c),ft);
    }
    printf("File Successfully Copied");
    fclose(fs);
    fclose(ft);
}
