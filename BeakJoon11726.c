#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
  
    int temp[1001] = {0}; 

    temp[0] = temp[1] = 1;
    temp[2] = 2;

    for (int i = 3; i <= n; i++) {
        temp[i] = temp[i-1] + temp[i-2];
        temp[i] %= 10007; 
    }

    printf("%d\n", temp[n]); 

    return 0;
}
