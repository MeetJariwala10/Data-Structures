// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Write a ‘C’ program to read the employee id, employee name, basic salary, %DA, %HRA and TA of n number of employees. Do as follows.

a.   Calculate gross salary of employees using a user-defined function. Display name and gross salary of all employees.
b.   Give bonus of Rs. 10,000 to all those employees whose basic salary is below 50,000. Display their names and net salary after bonus.
c.   Read an employee id from the user and display his/her information on the screen. If employee id is not found, display an appropriate message */

# include<stdio.h> 

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)");

    int n, flag = 0;
    printf("Enter number of employess : ");
    scanf("%d", &n);

    int id[n], salary[n], i, search;
    float  grossSalary[n], da, hra, ta, da1, hra1;
    char name[n][10];

    for(i=0; i<n; i++)
    {
        printf("\nEnter details for employee %d : \n", i+1);
        printf("Enter name : ");
        scanf("%s", name[i]);
        printf("Enter ID : ");
        scanf("%d", &id[i]);
        printf("Enter basic salary : ");
        scanf("%d", &salary[i]);
    }

    printf("Enter percentage DA : ");
    scanf("%f", &da);

    printf("Enter percentage HRA : ");
    scanf("%f", &hra);

    printf("Enter TA : ");
    scanf("%f", &ta);

    for(i=0; i<n; i++)
    {
        da1=(salary[i]*da)/100;
        hra1 = (salary[i]*hra)/100;

        grossSalary[i] = salary[i] + da1 + hra1 + ta;
        printf("\n Name : %s \n", name[i]);
        printf("The gross salary : %.3f \n", grossSalary[i]); 
    }
    
    for(i=0; i<n; i++)
    {
        if(salary[i] < 50000)
        {
            grossSalary[i] += 10000;
            printf("\nDetails of employee %d after bonus : \n", i+1);
            printf("Name : %s \n", name[i]);
            printf("ID : %d \n", id[i]);
            printf("Gross salary : %.3f \n", grossSalary[i]);
        }
    }
    
    printf("\nEnter Employee ID which you want to search : ");
    scanf("%d", &search);

    for(i=0; i<n; i++)
    {
        if(id[i] == search)
        {
            printf("\nDetails of employee id %d :\n", id[i]);
            printf("Name : %s \n", name[i]);
            printf("ID : %d \n", id[i]);
            printf("Gross Salary : %.3f \n", grossSalary[i]);
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