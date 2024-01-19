// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* (2) Write a 'C' program to create two dynamic arrays of size n1 and n2. Merge these two arrays into the third array (keep the original arrays unchanged). Display contents of the newly created array. Use runtime memory allocation.*/

# include<stdio.h>
# include<stdlib.h>  

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)");

    int *arr1, *arr2, n1, n2, n3, i, k;

    printf("\nEnter size of array 1 : ");
    scanf("%d", &n1);

    printf("\nEnter size of array 2 : ");
    scanf("%d", &n2);

    // Memory allocation using malloc() function
    arr1 = (int *)malloc(n1 * sizeof(int));
    arr2 = (int *)malloc(n2 * sizeof(int));

    n3 = n1 + n2;
    int *arr3 = (int *)malloc(n3 * sizeof(int));

    // Feeding data in pointer arr1 
    printf("\nEnter elements  for array 1 : \n");
    for(i=0; i<n1; i++)
    {
        scanf("%d", &arr1[i]);
        // copying data from arr1 to arr3 from 0 to size of arr1 
        arr3[i] = arr1[i];
    }

    // Feeding data in pointer arr2 
    printf("\nEnter elements  for array 2 : \n");
    for(i=0; i<n2; i++)
    {
        scanf("%d", &arr2[i]);
        // copying data from arr2 to arr3 from 0 to size of arr2 
        // index of arr3 starting from size of arr1 + i
        arr3[n1 + i] = arr2[i];
    }

    // merging of arr1 and arr2 in arr3
    printf("\nArray after merging is : \n");
    for(i=0; i<n3; i++)
    {
        printf("%d ", arr3[i]);
    }
    return 0;
}