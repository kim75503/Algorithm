#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;


void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, double value) {
    s->data[++(s->top)] = value;
}


double pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1; 
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

    printf("%.2f\n", st.data[st.top]); // 계산 결과 출력

    return 0;
}
