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

    for (int i = 1; i <= main->n; i++) {
        if (main->selectedSet[i]) {
            continue;
        }

        main->selectedSet[i] = 1;
        main->selectedNumbers[depth] = i;
        backtrack(main, depth + 1);
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
