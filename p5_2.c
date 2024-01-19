// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Write a program to search a given item in the list of n items using Binary Search.*/

# include<stdio.h> 

int binarySearch(int arr[], int element, int left, int right);

int main()
{
    printf("\nCode Prepared by : Meet Jariwala (ET22BTCO046)\n");

    int length, element, i;

    printf("\nEnter number of elements : ");
    scanf("%d", &length); 
    int arr[length];

    // For Binary search the array must be sorted
    printf("\nEnter elements in array in sorted manner : \n");
    for(i=0; i<length; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nYour array is : \n");
    for(i=0; i<length; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\nEnter element for searching : ");
    scanf("%d", &element);

    int result = binarySearch(arr, element, 0, length - 1);
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

int binarySearch(int arr[], int element, int left, int right)
{
    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        if(arr[mid] == element)
        {
            return mid;
        }
        else if(arr[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}