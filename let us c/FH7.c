#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    FILE *fs,*ft;
    char ch='Z';
    fs=fopen("source.txt","r");
    if(fs==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }

    ft=fopen("temp.txt","w");
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
        fputc(ch-10,ft);
    }
    fclose(fs);
    fclose(ft);
    remove("source.txt");
    rename("temp.txt","source.txt");
    return 0;
}
