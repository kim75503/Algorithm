#include <stdio.h>

void solution(int N) {
    long long dp[1000001];
    int mod = 15746;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i-1] % mod + dp[i-2] % mod) % mod;
    }

    printf("%lld\n", dp[N]);
}

int main() {
    int N;
    scanf("%d", &N);
    solution(N);
    return 0;
}
