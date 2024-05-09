#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;

// 스택 초기화 함수
void initialize(Stack *s) {
    s->top = -1;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 스택에 값 추가 함수
void push(Stack *s, double value) {
    s->data[++(s->top)] = value;
}

// 스택에서 값 제거 함수
double pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1; // 스택이 비어있으면 -1 반환
}

int main() {
    Stack st;
    initialize(&st); 

    int N;
    scanf("%d", &N); 

    char order[100];
    scanf("%s", order); 


    int um[26];
    char alpha = 'A';
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        um[alpha++ - 'A'] = num;
    }

    for (int i = 0; order[i] != '\0'; i++) {
        if (isalpha(order[i])) {
            push(&st, (double)um[order[i] - 'A']); 
        } else {
            double rhs = pop(&st);
            double lhs = pop(&st);
            if (order[i] == '+') push(&st, lhs + rhs);
            else if (order[i] == '-') push(&st, lhs - rhs);
            else if (order[i] == '*') push(&st, lhs * rhs);
            else if (order[i] == '/') push(&st, lhs / rhs);
        }
    }

    printf("%.2f\n", st.data[st.top]); 

    return 0;
}
