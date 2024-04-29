#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char S[100001]; 
char stack[100001]; 
char answer[100001]; 

int main() {
  int i, top = -1;
  scanf("%[^\n]", &S); 
  int len = strlen(S); 
  for (i = 0; i < len; i++) {
    if (S[i] == '<') { // '<'를 만나면 스택에 저장된 문자들을 역순으로 정답 배열에 저장
      while (top != -1) {
        answer[i - top - 1] = stack[top];
        top--;
      }
      // '>'를 만날 때까지 정답 배열에 문자들을 저장
      while (S[i] != '>') {
        answer[i] = S[i];
        i++;
      }
      answer[i] = S[i]; // '>'도 정답 배열에 저장
    }
    else if (S[i] == ' ') { // 공백을 만나면 스택에 저장된 문자들을 역순으로 정답 배열에 저장
      while (top != -1) {
        answer[i - top - 1] = stack[top];
        top--;
      }
      answer[i] = S[i]; // 공백도 정답 배열에 저장
    }
    else { // '<', ' ', 그리고 '>' 이외의 문자는 스택에 저장
      top++;
      stack[top] = S[i];
    }
  }
  // 스택에 남아있는 문자들을 역순으로 정답 배열에 저장
  while (top != -1) {
    answer[i - top - 1] = stack[top];
    top--;
  }
  printf("%s", answer);
  return 0;
}
