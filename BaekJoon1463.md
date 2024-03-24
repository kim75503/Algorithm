#include <stdio.h>
#include <stdlib.h>

int one_divide(int a);

int one_divide(int a){
  int dv[a + 1]; // 입력받은 값의 크기만큼 배열 생성 
  
  dv[1] = 0; // 1을 만드는데 필요한 연산 횟수는 0먼저 처리.

  for (int i = 2; i<= a; i++){ // i 는 2부터 입력받은 값 a 만큼 반복한다. 최소 연산 횟수를 구하기 위한 반복문.
    dv[i] = dv[i - 1] + 1; // dv[i] 배열에 현재의 수 i를 1로 만들기 위한 최소 연산 횟수를 저장합니다. 이전 수 i - 1의 최소 연산 횟수에 1을 더한 값으로 초기화됩니다.
    if (i % 2 == 0 ){
      dv[i] = dv[i] < dv[i/2] + 1 ? dv[i] : dv[i/2] + 1; // ? 조건 연산자를 이용하여 i가 2로 나누어 떨어지는 경우, 2로 나눈 수 i/2의 최소 연산 횟수에 1을 더한 값과 현재 i의 최소 연산 횟수를 비교하여 더 작은 값을 선택합니다.
    }
    if (i % 3 == 0){
      dv[i] = dv[i] < dv[i/3] + 1 ? dv[i] : dv[i/3] + 1; // 마찬가지로 i가 3으로 나누어 떨어지는 경우, i/3 에 대한 최소 연산 횟수를 비교하여 선택합니다.
    }
  }
  return dv[a];
}



int main(void){
  int x;
 
  scanf("%d", &x);

  printf("%d", one_divide(x));
  
  return 0;

}

*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*

// 처음에 다이내믹 프로그래밍을 사용하지 않고 풀었었던 코드입니다.
// 백준에선 다이내믹 프로그래밍을 사용하지 않으면 시간 초과가 발생합니다...

#include <stdio.h>
#include <stdlib.h>

int one_divide(int a) {
    if (a == 1) {
        return 0;
    }
    int ct1, ct2, ct3;
    ct1 = one_divide(a - 1);
    if (a % 2 == 0) {
        ct2 = one_divide(a / 2);
    } else {
        ct2 = one_divide(a - 1); 
    }
    if (a % 3 == 0) {
        ct3 = one_divide(a / 3);
    } else {
        ct3 = one_divide(a - 1); 
    }
    int result = ct1 < ct2 ? ct1 : ct2;
    result = result < ct3 ? result : ct3;

    return result + 1;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d",one_divide(x));

    return 0;
}



