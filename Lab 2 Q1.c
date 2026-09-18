//Write a C program to sort an array in ascending order using Insertion Sort.
#include <stdio.h>

int main()
{
    int A[100], n, i, j, key;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (j = 1; j < n; j++)
    {
        key = A[j];
        i = j - 1;

        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }

        A[i + 1] = key;
    }

    printf("Sorted array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
