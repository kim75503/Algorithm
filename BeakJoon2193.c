#include <stdio.h>

unsigned long long sol(int n) {
    unsigned long long dp[91] = {0, 1, 1};
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%llu", sol(n));
    return 0;
}
