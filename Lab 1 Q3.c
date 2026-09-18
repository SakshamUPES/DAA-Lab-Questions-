//Write a C program to find the sum and average of all elements in an array.
#include <stdio.h>

int main()
{
    int n, i;
    int sum = 0;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    average = (float)sum / n;

    printf("Sum of array elements = %d\n", sum);
    printf("Average of array elements = %.2f\n", average);

    return 0;
}
