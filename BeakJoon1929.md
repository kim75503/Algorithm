#include <stdio.h>
#include <stdbool.h>


bool isPrime(int a) {
    // 1은 소수가 아님
    if (a == 1) return false;

    // 2부터 해당 숫자의 제곱근까지의 수로 나누어 떨어지는지를 확인하여 소수 여부를 결정
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return false; 
        }
    }

    return true;
}


int main() {
    int m, n;
    scanf("%d %d", &m, &n);


    for (int x = m; x <= n; ++x) {
        if (isPrime(x)) {
            printf("%d\n", x); 
        }
    }

    return 0; 
}
