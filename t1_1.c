// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Write a ‘C’ program to read the employee id, employee name, basic salary, %DA, %HRA and TA of n number of employees. Do as follows.

a.   Calculate gross salary of employees using a user-defined function. Display name and gross salary of all employees.
b.   Give bonus of Rs. 10,000 to all those employees whose basic salary is below 50,000. Display their names and net salary after bonus.
c.   Read an employee id from the user and display his/her information on the screen. If employee id is not found, display an appropriate message */

# include<stdio.h> 

struct employee
{
    char name[10];
    int id;
    float salary;
    float gross_salary;

};

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)");

    int n, i, search, flag = 0;
    float hra, da, ta, hra1, da1;
    printf("Enter number of employees : ");
    scanf("%d", &n);

    struct employee emp[n];

    for(i=0; i<n; i++)
    {
        printf("\nEnter details for employee %d : \n", i+1);
        printf("Enter name : ");
        scanf("%s", &emp[i].name);
        printf("Enter ID : ");
        scanf("%d", &emp[i].id);
        printf("Enter basic salary : ");
        scanf("%f", &emp[i].salary);
    }

    printf("Enter percentage DA : ");
    scanf("%f", &da);

    printf("Enter percentage HRA : ");
    scanf("%f", &hra);

    printf("Enter TA : ");
    scanf("%f", &ta);

    for(i=0; i<n; i++)
    {
        da1 = (emp[i].salary*da)/100;
        hra1 = (emp[i].salary*hra)/100;

        emp[i].gross_salary = emp[i].salary + da1 + hra1 + ta;
        printf("\n");
        printf("Name : %s \n", emp[i].name);
        printf("The gross salary : %.3f \n",  emp[i].gross_salary); 
    }

    for(i=0; i<n; i++)
    {
        if(emp[i].salary < 50000)
        {
            emp[i].gross_salary += 10000;
            printf("\nDetails of employee %d after bonus : \n", i+1);
            printf("Name : %s \n", emp[i].name);
            printf("ID : %d \n", emp[i].id);
            printf("Gross salary : %.3f \n", emp[i].gross_salary);
        }
    }
    
    printf("\nEnter Employee ID which you need to search : ");
    scanf("%d", &search);

    for(i=0; i<n; i++)
    {
        if(emp[i].id == search)
        {
            printf("\nDetails of employee id %d :\n", emp[i].id);
            printf("Name : %s \n", emp[i].name);
            printf("ID : %d \n", emp[i].id);
            printf("Gross Salary : %.3f \n", emp[i].gross_salary);
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("\nID not found \n");
    }

    return 0;
}