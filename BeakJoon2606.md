#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 101

int answer = 0;
int computers[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE] = {false; // 방문 여부를 저장하기 위한 배열.

void dfs(int n) {
    visited[n] = true;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (computers[n][i] && !visited[i]) {// 감염된 컴퓨터와 연결된 컴퓨터 중에서 방문하지 않은 컴퓨터를 찾음.
            dfs(i);
            answer++; // 방문한 컴퓨터의 수를 증가시킴.
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
        computers[num1][num2] = 1; // 컴퓨터 쌍의 연결을 표시
        computers[num2][num1] = 1; // 양방향 연결을 위해 반대 방향도 표시
    }

    dfs(1); // 감염된 컴퓨터 부터 재귀함수로 감염된 컴퓨터 확인.
    printf("%d\n", answer);
    return 0;
}
