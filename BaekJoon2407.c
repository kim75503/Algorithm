#include <stdio.h>
#define n 100

int array[n][n];

int combination(int a, int b) {
    if (a == b || b == 0)
        return 1;
    if (array[a][b] != 0)
        return array[a][b];
    return array[a][b] = combination(a - 1, b - 1) + combination(a - 1, b);
}

int main(void) {
    int x, y;

  while (1) {
    scanf("%d %d", &x, &y);
    if (x >= y && x >= 5 && y >= 5 && x <= 100 && y <= 100)
      break;
    else
      scanf("%d %d", &x, &y);
  }
    
    printf("%d\n", combination(x, y));
    return 0;
}
