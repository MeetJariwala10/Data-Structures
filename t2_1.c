// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* (1) Write a 'C' program to read the name and the number of sold copies of the n number of books. Create a user-defined function to display the book information. Pass all arguments by reference. */

# include<stdio.h> 

// display Function declaration
void display(char *name_of_book, int *sold_copies);

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)");

    int n, i;

    printf("Enter the number of books : ");
    scanf("%d", &n);
    
    char name_of_book[n][20];
    int sold_copies[n];

    for(i=0; i<n; i++)
    {
        printf("\nEnter name of book %d : ", i+1);
        scanf("%s", name_of_book[i]);
        printf("\nEnter number of sold copies of book : ");
        scanf("%d", &sold_copies[i]);
        display(name_of_book[i], sold_copies[i]);
    }    
    return 0;
}

// display Function definition 
void display(char *name_of_book, int *sold_copies)
{
    printf("\nName of book : %s \n", name_of_book);
    printf("\nSold copies : %d \n", sold_copies);
}
