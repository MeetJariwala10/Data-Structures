// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Introduction to Dynamic Memory Allocation. DMA functions malloc(), calloc(), free() 
etc. */

# include<stdio.h> 
# include<stdlib.h> 

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)\n");

    int *ptr, *ptr1, n, i;

    printf("\nEnter number of elements :");
    scanf("%d", &n);

    // memory allocation using malloc
    ptr = (int *)malloc(n * sizeof(int));

    // memory allocation using calloc
    ptr1 = (int *)calloc(n, sizeof(int));

    // If memory is not allocated
    if(ptr == NULL || ptr1 == NULL)
    {
        printf("\nMemory Not Allocated\n");
        exit(0);
    }
    else
    {
        printf("\nMemory allocated\n");

        // Adding elements in array
        printf("\nEnter elements in array (malloc): \n");
        for(i=0; i<n; i++)
        {
            printf("\nElement %d :", i+1);
            scanf("%d", &ptr[i]);
        }

        printf("\nThe array is (malloc): ");
        for(i=0; i<n; i++)
        {
            printf("%d ", ptr[i]);
        }

        // Before adding values calloc function initializes each block with a default value '0' 
        printf("\nBefore adding elements the array is (calloc): ");
        for(i=0; i<n; i++)
        {
            printf("%d ", ptr1[i]);
        }

        for(i=0; i<n; i++)
        {
            ptr1[i] = i + 1;
        }

        printf("\nAfter adding elements the array is (calloc): ");
        for(i=0; i<n; i++)
        {
            printf("%d ", ptr1[i]);
        }

        // free() method de-allocates the memory
        free(ptr);
        printf("\n\nmalloc memory freed\n");
        free(ptr1);
        printf("\ncalloc memory freed\n");
    }
    return 0;
}