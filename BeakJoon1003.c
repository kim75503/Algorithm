#include <stdio.h>
#include <stdlib.h>

int t, n; 
int result[41] = {0, 1};

int main(void)
{
    for(int i = 2; i < 41; i++)
        result[i] = result[i - 1] + result[i - 2];
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
    if (n == 0)
      printf("1 0\n");
    else
          printf("%d %d\n", result[n - 1], result[n]);
    }
    return (0);
}
