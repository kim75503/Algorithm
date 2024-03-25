#include <stdio.h>
#define n  20000
int num[n];

void realint(int arr[], int size) { // 배열을 오름차순으로 정리.
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int x;

    scanf("%d", &x); // 사용자에게 배열의 크기를 입력받음.
    for (int i = 0; i < x; i++) { // 배열의 원소를 입력받음.
        scanf("%d", &num[i]);
    }

    realint(num, x); // 함수를 이용하여 배열의 대표 자연수를 정리.

    if (x % 2 == 0) {  // x가 짝수면 중앙값이 2개인데 배열의 작은 쪽을 선택.
        printf("%d\n", num[x / 2 - 1]);
    }
    else { // 홀수라면 중앙값을 선택.
        printf("%d\n", num[x / 2]);
    }

    return 0;
}
