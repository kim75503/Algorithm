#include <stdio.h>
#include <stdlib.h>

int t, n; 
int result[41] = {0, 1}; // 피보나치 수열의 값들을 저장할 배열.

int main(void)
{
    for(int i = 2; i < 41; i++) // 피보나치 수열의 값을 미리 계산하여 배열에 저장.
        result[i] = result[i - 1] + result[i - 2];
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
    if (n == 0) // 0번째 피보나치 수열 값은 (1, 0)이다.
      printf("1 0\n");
    else // n-1번째와 n번째 피보나치 수열 값을 출력.
          printf("%d %d\n", result[n - 1], result[n]);
    }
    return (0);
}
