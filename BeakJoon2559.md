#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int tem[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &tem[i]); 
    }

    int m = 0, s = 0;
    
    for (int i = 0; i < K; i++) { // 초기 K일 동안의 온도합 계산
        s += tem[i];
    }
    m = s; 

    
    for (int i = K; i < N; i++) { // K일부터 N일까지 반복하며 최대 온도합 계산
        s = s - tem[i - K] + tem[i]; // 이전 K일의 온도를 빼고 새로운 날짜의 온도를 더함
        m = (m > s) ? m : s;
    }

    printf("%d\n", m);

    return 0;
}
