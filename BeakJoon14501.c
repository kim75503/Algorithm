#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *dp = (int *)malloc(sizeof(int) * (N + 2));
    for (int i = 0; i < N + 2; i++) {
        dp[i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        int TP[2];
        scanf("%d %d", &TP[0], &TP[1]);


        if (i + TP[0] > N + 1) {
            continue;
        }

        int maxVal = 0;
        for (int j = 1; j <= i; j++) {
            if (dp[j] > maxVal) {
                maxVal = dp[j];
            }
        }

        dp[i + TP[0]] = (TP[1] + maxVal > dp[i + TP[0]]) ? (TP[1] + maxVal) : dp[i + TP[0]];
    }

    int maxValue = 0;
    for (int i = 0; i < N + 2; i++) {
        if (dp[i] > maxValue) {
            maxValue = dp[i];
        }
    }

    printf("%d\n", maxValue);
    free(dp);
    return 0;
}
