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
    char another='Y';
    fp=fopen("file1.txt","w");
    if(fp==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }
    while( another=='Y' || another=='y' )
    {
        printf("Enter id,name,salary\n");
        scanf("%d%s%d",&e.id,e.name,&e.salary);
        fprintf(fp,"%d %s %d\n",e.id,e.name,e.salary);
        fflush(stdin);
        printf("Want To Enter Another Record(Y/N) : ");
        another=getche();
    }
    fclose(fp);
    return 0;
} 