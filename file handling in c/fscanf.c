#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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
    fp=fopen("file1.txt","r");
    if(fp==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }
    while(fscanf(fp,"%d %s %d",&e.id,e.name,&e.salary)!=EOF)
    {
        printf("%d %s %d\n",e.id,e.name,e.salary);
    }
    fclose(fp);
    return 0;
}

