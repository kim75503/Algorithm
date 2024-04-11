#include<stdio.h>

int N, M;
int arr[7];
void Nnm(int cnt);

int main() {
  scanf("%d %d", &N, &M);
  Nnm(0);
  return 0;
}

void Nnm(int cnt) {
  int i;
  if (cnt == M) {
    for (i = 0; i < M; i++)
      printf("%d ", arr[i]);
    printf("\n");
  }
  else {
    for (i = 1; i <= N; i++) {
      arr[cnt] = i;
      Nnm(cnt + 1);
    }
  }
}
