//Write a C program to implement Binary Search and calculate its execution time.
#include <stdio.h>
#include <time.h>

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;
    int low = 0, high = n - 1;

    clock_t start = clock();

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            break;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    clock_t end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    if (low > high)
    {
        printf("Element not found\n");
    }

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
