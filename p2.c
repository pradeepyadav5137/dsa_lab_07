#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char selectionSort(char *arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strlen(arr[min_index]) > strlen(arr[j]))
            {
                min_index = j;
            }
            // swaping
            char *temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main()
{
    char *arr[100];
    int n = 5;
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter string to insert in array : ");
        arr[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", arr[i]);
    }


    selectionSort(arr, n);

    for (i = 0; i < n; i++)
    {
        printf(" %s ", arr[i]);
    }
    return 0;
}