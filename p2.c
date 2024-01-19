// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046


/* Create a structure 'emp' with members employee id, employee name, basic salary, DA, HRA and TA. Read information of n number of employees. Do as follows.

a.   Give bonus to all employees using a user-defined function. if gross salary is equal to or less than 2 lakhs, give bonus of Rs. 10,000 else give bonus of Rs. 15,000. Display name and gross salary of all employees.
b.  Create a user-defined function to display information of all employees whose basic salary is below Rs. 25,000.*/

# include<stdio.h> 
struct employee
{
    int id;
    char name[20];
    float salary, gross_salary;
    float da, hra, ta;
};

void salary_bonus(struct employee *e);
void employee_details(struct employee *e);

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)");

    int n, i;
    printf("\nEnter number of employees : ");
    scanf("%d", &n);

    struct employee emp[n];

    for(i=0; i<n; i++)
    {
        printf("\nEnter Details of employee %d : \n", i+1);

        printf("Name : ");
        scanf("%s", &emp[i].name);

        printf("ID : ");
        scanf("%d", &emp[i].id);
        
        printf("Basic salary : ");
        scanf("%f", &emp[i].salary);

        printf("DA : ");
        scanf("%f", &emp[i].da);

        printf("HRA : ");
        scanf("%f", &emp[i].hra);

        printf("TA : ");
        scanf("%f", &emp[i].ta);

        emp[i].gross_salary = emp[i].salary + emp[i].da + emp[i].hra + emp[i].ta;
        salary_bonus(&emp[i]);
    }

    for(i=0; i<n; i++)
    {
        printf("\nDetails of employee %d after bonus : \n", i+1);
        printf("Name : %s \n", emp[i].name);
        printf("Gross salary : %.3f \n", emp[i].gross_salary);
    }

    for(i=0; i<n; i++)
    {
        employee_details(&emp[i]);
    }

    
    return 0;
}

void salary_bonus(struct employee *e)
{
    if(e->gross_salary <= 200000)
    {
        e->gross_salary += 10000;
    }
    else
    {
        e->gross_salary += 15000;
    }
}

void employee_details(struct employee *e)
{
    if(e->salary <= 25000)
    {
        printf("\nDetails of employee having salary < 25000 : \n");
        printf("Name : %s \n", e->name);
        printf("ID : %d \n", e->id);
        printf("Basic salary : %.3f \n", e->salary);
        printf("Gross salary : %.3f \n", e->gross_salary);
    }
    else
    {
        printf("\nEmployee %s have salary < 25000 \n", e->name);
    }
}
