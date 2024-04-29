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

        // N을 초과하는 경우 무시
        if (i + TP[0] > N + 1) {
            continue;
        }

        // 현재까지의 최대 값 계산
        int maxVal = 0;
        for (int j = 1; j <= i; j++) {
            if (dp[j] > maxVal) {
                maxVal = dp[j];
            }
        }

        // 새로운 값 계산해서 dp 배열에 저장
        dp[i + TP[0]] = (TP[1] + maxVal > dp[i + TP[0]]) ? (TP[1] + maxVal) : dp[i + TP[0]];
    }

    // 최대 값 찾기
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
