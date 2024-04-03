#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int tem[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &tem[i]); 
    }

    int m = 0, s = 0;
    for (int i = 0; i < K; i++) {
        s += tem[i];
    }
    m = s; 

    for (int i = K; i < N; i++) {
        s = s - tem[i - K] + tem[i];
        m = (m > s) ? m : s;
    }

    printf("%d\n", m); 

    return 0;
}
