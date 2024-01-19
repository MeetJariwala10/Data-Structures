# include<stdio.h> 

void insertionSort(int arr[], int n);

int main()
{
    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)\n");

    int n, i, j, min_index, temp;
    printf("Enter number of elements in array : ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements in array : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted Array is : \n");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void insertionSort(int arr[], int n)
{
    int temp, i, j;
    for(i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}