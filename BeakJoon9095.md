#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); 

    int arr[11] = {0}; 

    // 초기 값 설정
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (int i = 4; i < 11; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    // 테스트 케이스 출력
    for (int i = 0; i < n; i++) {
        int testNum;
        scanf("%d", &testNum);
        printf("%d\n", arr[testNum]);
    }

    return 0;
}
