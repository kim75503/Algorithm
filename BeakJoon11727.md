#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); 

    int temp[1001] = {0}; // 초기화된 배열

    // 초기 값 설정
    temp[0] = temp[1] = 1;
    temp[2] = 3;

    for (int i = 3; i <= n; i++) {
        temp[i] = temp[i-1] + 2 * temp[i-2];
        temp[i] %= 10007; // 10007로 나눈 나머지를 저장
    }

    printf("%d\n", temp[n]); 

    return 0;
}
