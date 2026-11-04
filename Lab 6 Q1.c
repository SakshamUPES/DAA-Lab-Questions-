//Write a C program to implement the Fractional Knapsack Problem 
//using the Greedy approach and find the maximum profit for a given knapsack capacity.

#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    float ratio;
};

void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter profit and weight of each item:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);

        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort items according to profit/weight ratio
    // in descending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                swap(&items[j], &items[j + 1]);
            }
        }
    }

    float maxProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            // Take complete item
            capacity -= items[i].weight;
            maxProfit += items[i].profit;
        }
        else
        {
            // Take fractional part of item
            maxProfit += items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}
