#include <stdio.h>

void combinations(int arr[], int n, int m, int index, int selected[], int selected_count);

void combinations(int arr[], int n, int m, int index, int selected[], int selected_count) {
    if (selected_count == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", selected[i]);
        }
        printf("\n");
        return;
    }

    if (index >= n) {
        return;
    }

    selected[selected_count] = arr[index];
    combinations(arr, n, m, index + 1, selected, selected_count + 1);
    combinations(arr, n, m, index + 1, selected, selected_count);

}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    int selected[M];
    combinations(arr, N, M, 0, selected, 0);

    return 0;
}
