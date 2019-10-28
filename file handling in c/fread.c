#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    FILE *fp;
    struct emp
    {
        int id;
        char name[50];
        int salary;
    };
    struct emp e;
    char another='y';
    fp=fopen("file2.txt","rb");
    if(fp==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }
    while(fread(&e,sizeof(e),1,fp)==1)
    {
        printf("%d %s %d\n",e.id,e.name,e.salary);
    }
    fclose(fp);
    return 0;
}


