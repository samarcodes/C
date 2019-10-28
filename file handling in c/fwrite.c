#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    int i;
    FILE *fp;
    struct emp
    {
        int id;
        char name[50];
        int salary;
    };
    struct emp e;
    char another='y';
    fp=fopen("file2.txt","wb");
    if(fp==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }
    while(another=='y' || another=='Y')
    {
        printf("Enter Id,Name,Salary\n");
        scanf("%d%s%d",&e.id,e.name,&e.salary);
        fwrite(&e,sizeof(e),1,fp);
        fflush(stdin);
        printf("Want To Enter Another Record(Y/N) : ");
        another=getche();
    }
    fclose(fp);
    return 0;
}

