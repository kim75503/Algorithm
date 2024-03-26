#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 300

int arr[MAX_SIZE];
int dp[MAX_SIZE];


int max(int a, int b) {
    return a > b ? a : b; // 두 정수 중 큰 값을 비교한다.
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    dp[0] = arr[0];                         // 첫 번째 요소는 자신이 최대값.
    dp[1] = arr[0] + arr[1];                // 두 번째 요소는 첫 번째와 두 번째 요소의 합.
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]); // 세 번째 요소는 첫 번째와 세 번째 요소의 합 또는 두 번째와 세 번째 요소의 합 중 큰 값.

    for (int i = 3; i < n; i++) {
        int temp1 = dp[i - 2] + arr[i];                        // 두 칸 이전의 값에 현재 값을 더한 값.
        int temp2 = dp[i - 3] + arr[i - 1] + arr[i];           // 세 칸 이전의 값에 현재 값을 더한 값.
        dp[i] = max(temp1, temp2);                              // 두 값 중 더 큰 값을 최대값으로 설정.
    }
    
    printf("%d\n", dp[n - 1]);   
    return 0;
}
