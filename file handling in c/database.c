#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//#include<system.h>
int check(char);
//void gotoxy(short int col,short int row);
int main()
{
    FILE *fp,*ft;
    char another,choice;
    int num;
    int flag=0;
    struct emp
    {
        char name[50];
        int age;
        float bs;
    };
    struct emp e;
    char empname[50];
    long int recsize;

    fp=fopen("EMP.dat","rb+");
    if(fp==NULL)
    {
        fp=fopen("EMP.dat","wb+");
        if(fp==NULL)
        {
            puts("Cannot Open File...");
            exit(1);
        }
    }

    recsize=sizeof(e); //size of emp structure

    while(1)
    {
        system("cls");
        //gotoxy(30,10);
        printf("1. Add Records");
        //gotoxy(30,12);
        printf("\n2. List Records");
        //gotoxy(30,14);
        printf("\n3. Modify Records");
        //gotoxy(30,16);
        printf("\n4. Delete Records");
        //gotoxy(30,18);
        printf("\n0. Exit");
        printf("\nYour Choice : ");
        fflush(stdin);
        choice=getche();

        switch(choice)
        {
            case '1':
                fseek(fp,0,SEEK_END);
                another='Y';
                while(check(another))
                {
                    printf("\nEnter name,age,basic salary\n");
                    scanf("%s%d%f",e.name,&e.age,&e.bs);
                    num=fwrite(&e,recsize,1,fp);
                    if(num==1)
                        printf("Record Added Successfully");
                    printf("\nAdd Another Record(Y/N) : ");
                    fflush(stdin);
                    another=getche();
                }
                break;

            case '2':
                rewind(fp);
                printf("\nName\tAge\tSalary\n");
                while(fread(&e,recsize,1,fp)==1)
                {
                    printf("%s\t%d\t%.3f\n",e.name,e.age,e.bs);
                }
                getch();
                break;

            case '3':
                another='Y';
                while(check(another))
                {
                    printf("\nEnter name of the employee to modify : ");
                    scanf("%s",empname);
                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1)
                    {
                        if(strcmp(empname,e.name)==0)
                        {
                            flag=1;
                            printf("Enter new name, age & bs\n");
                            scanf("%s%d%f",e.name,&e.age,&e.bs);
                            fseek(fp,-recsize,SEEK_CUR);
                            num=fwrite(&e,recsize,1,fp);
                            if(num==1)
                                printf("Record Modified");
                            break;
                        }
                    }

                    if(flag==0)
                        printf("Record Not Found...");

                    printf("\nModify another record(Y/N) : ");
                    fflush(stdin);
                    another=getche();
                }
                break;

            case '4':
                another='Y';
                while(check(another))
                {
                    printf("\nEnter name of the employee to delete\n");
                    scanf("%s",empname);

                    ft=fopen("TEMP.dat","wb");

                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1)
                    {
                        if(strcmp(e.name,empname)!=0)
                        {
                            fwrite(&e,recsize,1,ft);
                        }
                    }
                        fclose(fp);
                        fclose(ft);
                        remove("EMP.dat");
                        rename("TEMP.dat","EMP.dat");

                        fp=fopen("EMP.dat","rb+");

                        printf("Delete another record(Y/N)");
                        fflush(stdin);
                        another=getche();
                }
                break;

            case '0':
                fclose(fp);
                exit(0);
        }
    }
    return 0;
}

int check(char a)
{
    if(a=='Y' || a=='y')
        return 1;
    else
        return 0;
}
 /*void gotoxy(short int col,short int row)
 {
     HANDLE h Stdout=GetStdHandle(STD_OUTPUT_HANDLE);
     COORD position={col,row};
     SetConsoleCursorPosition(hStdout,position);
 }*/
