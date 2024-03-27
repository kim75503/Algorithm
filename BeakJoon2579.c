#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 300

int arr[MAX_SIZE];
int dp[MAX_SIZE];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    for (int i = 3; i < n; i++) {
        int temp1 = dp[i - 2] + arr[i];
        int temp2 = dp[i - 3] + arr[i - 1] + arr[i];
        dp[i] = max(temp1, temp2);
    }

    printf("%d\n", dp[n - 1]);
    return 0;
}
