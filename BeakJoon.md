#include <stdio.h>
#define n 100

int array[n][n];

int combination(int a, int b) {
    if (a == b || b == 0) // a,b가 같거나 b가 0일 때 1을 리턴.
        return 1;
    if (array[a][b] != 0) // 2차원 배열을 이용하여 중복 계산을 피합니다.
        return array[a][b];
    return array[a][b] = combination(a - 1, b - 1) + combination(a - 1, b); // 이 재귀함수를 통해 a 개의 원소 중에서 b 개의 원소를 선택하는 조합 값을 구할 수 있습니다.
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
