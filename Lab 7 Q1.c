//Write a program to solve the 0/1 Knapsack Problem
// using Dynamic Programming and find the maximum profit 
//that can be obtained without exceeding the capacity of the knapsack.

#include <stdio.h>

// Function to find maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// 0/1 Knapsack using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];

    // Build DP table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // Base case
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }

            // If current item can fit
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            }

            // If current item cannot fit
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter weight and profit of each item:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int maxProfit = knapsack(W, wt, val, n);

    printf("Maximum Profit = %d\n", maxProfit);

    return 0;
}
