#include <stdio.h>
#define n  20000
int num[n];

void realint(int arr[], int size) { 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int x;

    scanf("%d", &x); 
    for (int i = 0; i < x; i++) {
        scanf("%d", &num[i]);
    }

    realint(num, x);

    if (x % 2 == 0) {  
        printf("%d\n", num[x / 2 - 1]);
    }
    else {
        printf("%d\n", num[x / 2]);
    }

    return 0;
}
