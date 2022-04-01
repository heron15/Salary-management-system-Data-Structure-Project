#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define s1 60

struct salary
{
    char name[s1];
    int age;
    double salary;
    char joinDate[s1];
    int id;
    struct salary *next;
};

struct salary *head;

void insert(char *name, int age, double salary, char *joinDate, int id)
{
    struct salary *temp=(struct salary*)malloc(sizeof(struct salary));
    strcpy(temp->name, name);
    temp->age=age;
    temp->salary=salary;
    strcpy(temp->joinDate, joinDate);
    temp->id=id;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void display()
{
    struct salary *temp=head;

    while(temp!=NULL)
    {
        printf("\nName: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Salary: %.2lf\n", temp->salary);
        printf("Joining Date: %s\n", temp->joinDate);
        printf("ID: %d\n", temp->id);

        temp=temp->next;
    }
}

void search(int id)
{
    struct salary *temp = head;

    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            printf("\nName: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Salary: %.2lf\n", temp->salary);
            printf("Joining Date: %s\n", temp->joinDate);
            printf("ID: %d\n", temp->id);
            return;
        }
        temp = temp->next;

    }
    printf("\n\nid %d not found\n\n", id);
}

void delete(int id)
{
    struct salary *temp1=head;
    struct salary *temp2=head;

    while(temp1!=NULL)
    {
        if(temp1->id==id)
        {
            printf("\n\nId %d founded!!\n\n", id);
            if(temp1==temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next=temp1->next;
                free(temp1);
            }
            printf("\n delete successfully\n\n");
            return;
        }
        temp2=temp1;
        temp1=temp1->next;
    }
    printf("\n\nStudent id %d not found!!\n\n", id);
}

void update(int id)
{
    struct salary *temp=head;
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            printf("\nEnter name: ");
            getchar();
            gets(temp->name);

            printf("Enter age: ");
            scanf("%d", &temp->age);

            printf("Enter salary: ");
            scanf("%lf", &temp->salary);

            printf("Enter joining date: ");
            getchar();
            gets(temp->joinDate);

            printf("Enter ID: ");
            scanf("%d", &temp->id);

            return;
        }
        temp=temp->next;
    }
}

int main()
{
    int n;

    char name[s1];
    int age;
    double salary;
    char joinDate[s1];
    int id;

    printf("\n-----Welcome Salary Management System-----\n\n");
    do
    {

        printf("\n1. Add Record.\n2. View Record.\n3. Search Record.\n4. Delete Record.\n5. Update Record\n6. Exit.\n");

        printf("\nChose a option: ");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            printf(" ");

            printf("\nEnter name: ");
            getchar();
            gets(name);

            printf("Enter age: ");
            scanf("%d", &age);

            printf("Enter salary: ");
            scanf("%lf", &salary);

            printf("Enter joining date: ");
            getchar();
            gets(joinDate);

            printf("Enter ID: ");
            scanf("%d", &id);

            insert(name, age, salary, joinDate, id);
            break;

        case 2:
            if(head==NULL)
            {
                printf("\ndata empty\n");
            }
            else
            {
                display();
            }
            break;

        case 3:
            printf(" ");
            printf("\nEnter student id: ");
            scanf("%d", &id);

            search(id);
            break;

        case 4:
            printf(" ");
            printf("\nEnter student id: ");
            scanf("%d", &id);

            delete(id);
            break;

        case 5:
            printf(" ");
            printf("\nEnter student id: ");
            scanf("%d", &id);

            update(id);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\nWrong option select!!\n");
            break;
        }

    }
    while(n!=6);
    return 0;
}
