#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define POW2(X) ((X) == ((X)&(-(X))))
// 2의 제곱수 판정 매크로

#define min(a, b) (((a) < (b)) ? (a) : (b)) 
// 두 수 중 작은 값을 반환하는 매크로

int dirx[4] = {1, 1, 0}; // 이동할 x 방향
int diry[4] = {0, 1, 1}; // 이동할 y 방향

int main(void) {
    int n, m, maxlen; 
    scanf("%d %d", &n, &m);
    maxlen = min(n, m); // 행과 열 중 작은 값 선택
    char arr[n][m + 1]; // 열의 크기는 널 문자('\0')를 고려하여 1 증가

  
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

 
    for (int size = maxlen; size > 0; size--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int issquare = 1; // 정사각형 여부 1로 초기화
                for (int k = 0; k < 3; k++) { // 주변의 3개 방향을 검사
                    int y = i + diry[k] * (size - 1); // 현재 행 위치에서 이동할 y 방향으로 (size - 1) 만큼 이동
                    int x = j + dirx[k] * (size - 1); // 현재 열 위치에서 이동할 x 방향으로 (size - 1) 만큼 이동

                   
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        if (arr[y][x] == arr[i][j]) { // 현재 위치와 같은 문자인지 확인
                            issquare = issquare && 1; // 정사각형이라면 1을 유지
                        } else {
                            issquare = 0; // 정사각형이 아니라면 0으로 설정
                        }
                    } else {
                        issquare = 0; // 배열 범위를 벗어나면 정사각형이 아님
                    }
                }
                if (issquare) { 
                    printf("%d", size * size); 
                    return 0; 
                }
            }
        }
    }

    return 0; 
}
