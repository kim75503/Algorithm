#include <stdio.h>

int a[3], b[3];

int GCD(int n, int m) {
    while (1) {
        int r = n % m;
        if (r == 0) {
            return m;
        }
        n = m;
        m = r;
    }
}

int LCM(int n, int m) {
    return (n * m) / GCD(n, m);
}

void Input() {
    for (int i = 0; i < 2; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
}

void Settings() {
    if (b[0] < b[1]) {
        int temp = a[0];
        a[0] = a[1];
        a[1] = temp;

        temp = b[0];
        b[0] = b[1];
        b[1] = temp;
    }
    int L = LCM(b[0], b[1]);
    a[0] *= (L / b[0]);
    a[1] *= (L / b[1]);
    a[2] = a[0] + a[1];
    b[2] = L;
    int G = GCD(b[2], a[2]);
    a[2] /= G;
    b[2] /= G;
}


int main() {
    Input();
    Settings();
   printf("%d %d\n", a[2], b[2]);

    return 0;
}
