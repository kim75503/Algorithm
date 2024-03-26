#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 101

int answer = 0;
int computers[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE] = {false};

void dfs(int n) {
    visited[n] = true;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (computers[n][i] && !visited[i]) {
            dfs(i);
            answer++;
        }
    }
}

int main() {
    int computer = 0;
    int Num = 0;
    int num1, num2;
  
    scanf("%d %d", &computer, &Num);
    
    for (int i = 0; i < Num; i++) {
        scanf("%d %d", &num1, &num2);
        computers[num1][num2] = 1;
        computers[num2][num1] = 1;
    }

    dfs(1);
    printf("%d\n", answer);
    return 0;
}
