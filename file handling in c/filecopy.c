#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    FILE *fs,*ft;
    char ch;
    fs=fopen("source.txt","rt");
    if(fs==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }
    ft=fopen("target.txt","wt");
    if(ft==NULL)
    {
        puts("Cannot Open File...");
        fclose(fs);
        exit(2);
    }
    while(1)
    {
        ch=fgetc(fs);
        if(ch==EOF)
            break;
        fputc(ch,ft);
    }
    fclose(fs);
    fclose(ft);
    return 0;
}