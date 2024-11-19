
#include <stdio.h>
#include <conio.h>

int is_sorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

void bubblesort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binary_search(int arr[], int key, int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] > key)
            e = mid - 1;

        else if (arr[mid] < key)
            s = mid + 1;
    }

    return -1;
}

int main()
{
    // int arr[30];
    int i, key, result;
    int n = 5;
    // for (i = 0; i < 5; i++)
    // {
    //     printf("please enter sorted value : ");
    //     scanf("%d", &arr[i]);
    // }
    int arr[5] = {10, 90, 60, 40, 50};

    if (is_sorted(arr, n))
    {
        printf("sorted already\n");
        printf("please enter value to find : ");
        scanf("%d", &key);
        result = binary_search(arr, key, n);
    }
    else
    {   
        printf("not sorted , sorting.....sorted now !\n");
        
        printf("please enter value to find : ");
        scanf("%d", &key);
        bubblesort(arr, n);
        result = binary_search(arr, key, n);
    }

    printf("%d ", result);

    return 0;
}