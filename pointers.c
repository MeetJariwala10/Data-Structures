// Name : Meet P Jariwala
// Enrollment number : ET22BTCO046

/* Introduction to pointers. Call by Value and Call by reference. */

# include<stdio.h> 

void callByValue(int a, int b);
void callByReference(int *a, int *b);

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)\n");

    int a = 5, b = 10;

    printf("Before swapping a = %d and b = %d\n", a, b);

    callByValue(a, b);
    printf("In call by value function a = %d and b = %d\n", a, b);

    callByReference(&a, &b);
    printf("In call by reference function a = %d and b = %d\n", a, b);

    return 0;
}

void callByValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void callByReference(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}