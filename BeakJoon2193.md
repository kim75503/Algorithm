#include <stdio.h>

unsigned long long sol(int n) {
    unsigned long long dp[91] = {0, 1, 1}; // 0번째, 1번째, 2번째 피보나치 수는 각각 0, 1, 1로 초기화
    for(int i = 3; i <= n; i++) { // 3번째부터 n번째까지의 피보나치 수 계산
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
