// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* 2) Write a program to implement Merge sort.*/

#include<stdio.h>

// merging and sorting the element
void merge(int arr[],int f,int mid,int t)
{
    int i,j,k;
    int n1 = mid - f + 1;
    int n2 = t - mid;
    int l[n1],r[n2];
    
    for(i=0;i<n1;i++)
    {
        l[i] = arr[f+i];
    }
    for(j=0;j<n2;j++)
    {
        r[j] = arr[mid+1+j];
    }

    i=0;
    j=0;
    k=f;

    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}

//dividing array to subarray
void mergesort(int arr[],int first, int last)
{
    if(first < last)
    {
        int mid = first + (last-first)/2;

        mergesort(arr,first,mid);
        mergesort(arr,mid+1,last);

        merge(arr,first,mid,last);
    }
}

//printing the array
void printArray(int arr[],int n)
{
     printf("\n\nSorted Array: \n");
        for(int k=0; k<n; k++)
        {
            printf("%d ",arr[k]);
        }
}

int main()
{
    int n;
    
    printf("Enter length of array: ");
    scanf("%d",&n);

    int arr[n];
    
    printf("Enter Elements in array : \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array without sorting: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

    // Calling function
    mergesort(arr,0,n-1);

    printArray(arr,n);
    
    return 0;
}