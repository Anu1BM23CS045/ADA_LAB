#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];
    printf("KnapSack Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
            printf("%d  ",dp[i][w]);    
        }
        printf("\n");
    }
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int values[n], weights[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &values[i], &weights[i]);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    int maxValue = knapsack(capacity, weights, values, n);
    printf("Maximum value in knapsack = %d\n", maxValue);
    return 0;
}
