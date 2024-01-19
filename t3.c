//Name : MEET P JARIWALA
//Enrollment number : ET22BTCO046

/* Create a structure student with members Roll No. Name and Marks. Write a 'C' program to read the information of N number of students and then create
following functions:


(a) void search1(struct
student[], int n, int x) : To search a student whose rollno=x and to display
information within the function only. Pass an entire array of students as an argument.


(b) struct student search2(struct
student[], int n, int x): To search a student whose rollno=x and to return the information of that student to the calling function. The calling function should display the information of the student. Pass an entire array of students as an argument.


(c) struct student*
search3(struct student[], int n, int x): To search a student whose rollno=x and
to return a pointer to that student information to the calling function. The
calling function should display information of the student. Pass an entire array of students as an argument.


(d) void sort(struct student[],
int n) : To sort the entire list of students in ascending order as per roll
number. */


#include<stdio.h>
#include<conio.h>

struct student
{
	int rollNum;
	char name[20];
	int marks;
};

void search1(struct student s[], int n, int x);
struct student search2(struct student s[], int n, int x);
struct student *search3(struct student s[], int n, int x);
void sort(struct student s[], int n);

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)");

	int n, i, R1, R2, R3;

	// Number of students
	printf("\nEnter number of students : ");
	scanf("%d", &n);
	struct student s[n], s2, *s3;
	
	// Filling details of students
	for(i = 0; i < n; i++)
	{
		printf("\nEnter details for student %d : \n", i+1);
		
		printf("Enter Name : ");
		scanf("%s", s[i].name);
		
		printf("Enter Roll Number : ");
		scanf("%d", &s[i].rollNum);
		
		printf("Enter Marks : ");
		scanf("%d", &s[i].marks);
	}
	
	printf("\nIn Search 1 function call :\n");
	printf("Enter Student Roll Number for Details : ");
	scanf("%d", &R1);
	
	// search1 function call
	search1(s, n, R1);
	
	printf("\nIn Search 2 function call :\n");
	printf("Enter Student Roll Number for Details : ");
	scanf("%d", &R2);
	
	// search2 function call
	s2 = search2(s, n, R2);
	// Condition checking for search 2
	if(s2.rollNum != 0)
	{
		printf("\nName : %s \n", s2.name);
		printf("\nRoll Number : %d \n", s2.rollNum);
		printf("\nMarks : %d \n", s2.marks);
	}
	else
	{
		printf("\nDetails not found !\n");
	}
	
	printf("\nIn Search 3 function call :\n");
	printf("Enter Student Roll Number for Details : ");
	scanf("%d", &R3);

	// search3 function call
	s3 = search3(s, n, R3);
	// Condition checking for search 3
	if(s3 != NULL)
	{
		printf("\nName : %s \n", s3->name);
		printf("\nRoll Number : %d \n", s3->rollNum);
		printf("\nMarks : %d \n", s3->marks);
	}
	else
	{
		printf("\nDetails not found !\n");
	}
	
	// Sort function call
	sort(s, n);
	
	return 0;
}

void search1(struct student s[], int n, int x)
{
	int i, flag = 0;
	for(i = 0; i < n; i++)
	{
		if(s[i].rollNum == x)
		{
			printf("\nDetails of Student :\n");
			printf("\nName : %s \n", s[i].name);
			printf("\nRoll Number : %d \n", s[i].rollNum);
			printf("\nMarks : %d \n", s[i].marks);
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		printf("Details not found !\n");
	}
}

struct student search2(struct student s[], int n, int x)
{
	struct student  s1;
	for(int i = 0; i < n; i++)
	{
		if(s[i].rollNum == x)
		{
			return s[i];
		}
	}
	s1.rollNum = 0;
	return s1;
}

struct student *search3(struct student s[], int n, int x)
{
	for(int i=0; i<n; i++)
	{
		if(s[i].rollNum == x)
		{
			return &s[i];
		}
	}
	return NULL;
}

void sort(struct student s[], int n)
{
	int i, j, temp;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(s[j].rollNum > s[j+1].rollNum)
			{
				temp = s[j].rollNum;
				s[j].rollNum = s[j+1].rollNum;
				s[j+1].rollNum = temp;
			}
		}
	}

	printf("\nEnter spacebar for Sorted list of students : \n");
	getch();
	
	for(i=0; i<n; i++)
	{
		printf("\nName : %s \n", s[i].name);
		printf("\nRoll Number : %d \n", s[i].rollNum);
		printf("\nMarks : %d \n", s[i].marks);
	}
}

