#include <stdio.h>
#include <stdbool.h>

bool isPrime(int a) {
    if (a == 1) return false;
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
