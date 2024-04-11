#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int m;
    int *selectedNumbers;
    int *selectedSet;
} Main;

void backtrack(Main *main, int depth);
void printSelectedNumbers(Main *main);



void backtrack(Main *main, int depth) {
    if (depth == main->m) {
        printSelectedNumbers(main);
        return;
    }

    for (int i = 1; i <= main->n; i++) { // 선택할 숫자의 개수(m)에 도달하면 선택된 숫자들을 출력하고 함수 종료
        if (main->selectedSet[i]) {  // 이미 선택된 숫자라면 다음 숫자로 넘어감
            continue;
        }

        main->selectedSet[i] = 1; // 현재 숫자를 선택된 숫자들에 추가하고 재귀 함수 호출
        main->selectedNumbers[depth] = i;
        backtrack(main, depth + 1); // 현재 숫자를 선택된 숫자에서 제거함
        main->selectedSet[i] = 0;
    }
}

void printSelectedNumbers(Main *main) {
    for (int i = 0; i < main->m; i++) {
        printf("%d ", main->selectedNumbers[i]);
    }
    printf("\n");
}

int main() {
    Main main;
    scanf("%d %d", &main.n, &main.m);

    main.selectedNumbers = (int *)malloc(main.m * sizeof(int));
    main.selectedSet = (int *)calloc(main.n + 1, sizeof(int));

    backtrack(&main, 0);

    free(main.selectedNumbers);
    free(main.selectedSet);
    return 0;
}
