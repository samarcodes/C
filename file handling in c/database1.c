#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int check(char);
int main()
{
    FILE *fp,*ft;
    struct emp
    {
        int id;
        char name[50];
        float basic_salary;
    };
    struct emp e;
    char another;
    char choice;
    int recsize=sizeof(e);
    int num;//for fwrite() and fread()
    int flag;
    int emp_id;//for modify

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

    while(1)
    {
        system("cls");
        printf("1.Add Record/s");
        printf("\n2.List Record/s");
        printf("\n3.Modify Record/s");
        printf("\n4.Delete Record/s");
        printf("\n0.Exit");
        printf("\n\nEnter Choice : ");
        fflush(stdin);
        choice=getche();

        switch(choice)
        {
            case '1':
                fseek(fp,0,SEEK_END);
                another='y';

                while(check(another))
                {
                    printf("\nEnter id,name & basic salary\n");
                    scanf("%d%s%f",&e.id,e.name,&e.basic_salary);
                    num=fwrite(&e,recsize,1,fp);
                    if(num==1)
                        printf("Record Added Successfully");
                    fflush(stdin);
                    printf("\n\nAdd Another Record(Y/N) : ");
                    another=getche();
                }
                break;

            case '2':
                rewind(fp);
                system("cls");
                printf("1.List All Records");
                printf("\n2.List Record by ID");
                printf("\n\nEnter Choice : ");
                fflush(stdin);
                choice=getche();

                switch(choice)
                {
                    case '1':
                        printf("\nID\tName\tSalary\n");
                        flag=0;
                        while(fread(&e,recsize,1,fp)==1)
                        {
                            flag=1;
                            printf("%d\t%s\t%.3f\n",e.id,e.name,e.basic_salary);
                        }
                        if(flag==0)
                            printf("No Record Found...");
                        printf("\nPress Enter for Main Menu...");
                        getch();
                        fflush(stdin);
                        break;

                    case '2':
                        printf("\nEnter Employee Id : ");
                        scanf("%d",&emp_id);
                        printf("\nID\tName\tSalary\n");
                        flag=0;
                        while(fread(&e,recsize,1,fp)==1)
                        {
                            if(emp_id==e.id)
                            {
                                flag=1;
                                printf("%d\t%s\t%.3f\n",e.id,e.name,e.basic_salary);
                            }
                        }
                        if(flag==0)
                            printf("Record Not Found");
                        printf("\nPress Enter for Main Menu...");
                        getch();
                        fflush(stdin);
                        break;
                }
                break;

            case '3':
                flag=0;
                another='y';
                while(check(another))
                {
                    printf("\nEnter Employee Id to Modify : ");
                    scanf("%d",&emp_id);
                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1)
                    {
                        if(e.id==emp_id)
                        {
                            flag=1;
                            printf("Enter new Name : ");
                            scanf("%s",&e.name);
                            fseek(fp,-56,SEEK_CUR);
                            num=fwrite(&e.name,sizeof(e.name),1,fp);
                            if(num==1)
                                printf("Name Modified");
                            break;
                        }
                    }
                    if(flag==0)
                        printf("No Employee with Id %d",emp_id);
                    printf("\nModify another record(Y/N) : ");
                    fflush(stdin);
                    another=getche();
                }
                break;

            case '4':
                another='Y';
                flag=0;
                while(check(another))
                {
                    printf("\nEnter ID of the Employee to Delete\n");
                    scanf("%d",&emp_id);

                    ft=fopen("TEMP.dat","wb");

                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1)
                    {
                        flag=1;
                        if(e.id!=emp_id)
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
    if(a=='y' || a=='Y')
        return 1;
    else
        return 0;
}

