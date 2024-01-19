// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

# include<stdio.h> 

int linearSearch(int arr[], int length, int element);

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)\n");

    int arr[] = {5,15,20,25,10};
    int length = sizeof(arr) / sizeof(arr[0]); // 20/4 = 5
    int element = 10;

    int result = linearSearch(arr, length, element);
    if(result == -1)
    {
        printf("Element is not present in array\n");
    }
    else
    {
        printf("Element %d is present at index %d\n", element, result);
    }
    return 0;
}

int linearSearch(int arr[], int length, int element)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}