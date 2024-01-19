// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Write a program to enter information of N number of students (Rollno, Name, marks of three subjects). Display following using user defined functions.
a. All students whose average marks are greater than or equal to 60.
b. All students who are PASS (i.e. to obtain marks greater than or equal to 35 in all subjects).
c. To display information of the student whose Roll number is R. If R is not found, display the appropriate message.*/

# include<stdio.h> 

struct student
{
    char name[10];
    int roll_num;
    int marks[3];
    float avg;
};

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)");

    int n, i, j, sum, R, flag=0;
    printf("Enter number of students : ");
    scanf("%d", &n);

    struct student s[n];  

    for(i=0; i<n; i++)
    {
        printf("\nEnter Details for student %d : \n", i+1);
        printf("Name : ");
        scanf("%s", &s[i].name);
        printf("Roll Number : ");
        scanf("%d", &s[i].roll_num);

        printf("Enter marks : \n");
        sum = 0;
        for(j=0; j<3; j++)
        {
            printf("Subject %d : ", j+1);
            scanf("%d", &s[i].marks[j]);
            sum += s[i].marks[j];
        }
        s[i].avg = (float) sum/3;
    }

    for(i=0; i<n; i++)
    {
        if(s[i].avg>=60)
        {
            printf("\nAverage marks >= 60 : \n");
            printf("Name : %s \n", s[i].name);
            printf("Roll number : %d \n", s[i].roll_num);
        }
        else
        {
            printf("\nAverage marks < 60 : \n");
            printf("Name : %s \n", s[i].name);
            printf("Roll number : %d \n", s[i].roll_num);
        }

        for(j=0; j<3; j++)
        {
            if(s[i].marks[0]>=35 && s[i].marks[1]>=35 && s[i].marks[2]>=35)
            {
                printf("\nStudent %s is PASS !! \n", s[i].name);
                break;
            }
            else
            {
                printf("\nStudent %s is Fail !! \n", s[i].name);
                break;
            }
        }
    }

    printf("\nEnter Roll number of student for Details : ");
    scanf("%d", &R);

    for(i=0; i<n; i++)
    {
        if(s[i].roll_num == R)
        {
            printf("Name : %s \n", s[i].name);
            printf("Roll number : %d \n", s[i].roll_num);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("No details found !\n");
    }
    return 0;
}