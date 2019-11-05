#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char tempc[20];
    int i,j;
    int flag;
    FILE *fp;
    struct student
    {
        char name[20];
        int age;
    } s[20];

    fp=fopen("source.txt","r");
    if(fp==NULL)
    {
        puts("Cannot Open File...");
        exit(1);
    }

    for(i=0;i<8;i++)
    {
        fscanf(fp,"%s%d",s[i].name,&s[i].age);
    }

    for(i=1;i<=8-1;i++)
    {
        flag=0;
        for(j=0;j<=8-1-i;j++)
        {
            if(strcmp(s[j].name,s[j+1].name)>0)
            {
                flag=1;
                strcpy(tempc,s[j].name);
                strcpy(s[j].name,s[j+1].name);
                strcpy(s[j+1].name,tempc);
            }
        }
        if(flag==0)
            break;
    }

    for(i=0;i<8;i++)
    {
        printf("%s\n",s[i].name);
    }

    fclose(fp);
    return 0;
}

