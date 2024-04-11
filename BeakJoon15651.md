#include<stdio.h>

    
int N, M;
int arr[7];

void Nnm(int cnt) {
  if (cnt == M) { // 만약 cnt가 M이면 arr에 저장된 숫자들을 출력하고 함수 종료
      for (int i = 0; i < M; i++)
        printf("%d ", arr[i]);
        printf("\n");
      }
  else {   
    for (int i = 1; i <= N; i++) { // 현재 숫자를 arr에 추가하고 재귀 호출
      arr[cnt] = i;
      Nnm(cnt + 1);
    }
  }
}

int main() {

  scanf("%d %d", &N, &M);

  Nnm(0);

return 0;
}
