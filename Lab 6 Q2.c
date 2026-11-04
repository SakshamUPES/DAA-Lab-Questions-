//Write a C program to implement the Activity Selection Problem 
//using the Greedy approach and find the maximum number of 
//non-overlapping activities that can be performed by a single person.

#include <stdio.h>

struct Activity
{
    int start;
    int finish;
};

// Function to swap two activities
void swap(struct Activity *a, struct Activity *b)
{
    struct Activity temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    printf("Enter start and finish time of each activity:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Sort activities according to finish time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (activities[j].finish > activities[j + 1].finish)
            {
                swap(&activities[j], &activities[j + 1]);
            }
        }
    }

    printf("\nSelected Activities:\n");

    // Select first activity
    int i = 0;
    printf("(%d, %d)\n",
           activities[i].start,
           activities[i].finish);

    // Select remaining non-overlapping activities
    for (int j = 1; j < n; j++)
    {
        if (activities[j].start >= activities[i].finish)
        {
            printf("(%d, %d)\n",
                   activities[j].start,
                   activities[j].finish);

            i = j;
        }
    }

    return 0;
}
