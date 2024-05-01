#include <stdio.h>

// 배열을 초기화하는 함수
void reset_arr(int N, int array[]) {
    for(int i = 1; i < N + 1; i++) { 
        array[i] = i;
    }
}

int main() {
    int arr[51] = {0,}; 
    int size = 0;
    int size_temp = 0;
    int half_size = 0;
    int cycle = 0; 
    int number = 0;
    int cnt = 0;  

    
    scanf("%d %d",&size, &cycle);
    size_temp = size;

   
    reset_arr(size, arr);

   
    for(int i = 0; i < cycle; i++) {
        scanf("%d", &number); 
        int temp = arr[number];

        // 배열을 왼쪽 또는 오른쪽으로 이동할지 결정
        if(size_temp % 2 == 0) // 배열의 길이가 짝수일 때
            half_size = size_temp / 2;
        else // 배열의 길이가 홀수일 때
            half_size = size_temp / 2 + 1;

        if(arr[number] <= half_size) { // 배열이 왼쪽으로 이동할 때
            for(int j = 1; j < size + 1; j++) {
                if(arr[j] < temp)
                    arr[j] = arr[j] + size_temp - temp;
                else
                    arr[j] = arr[j] - temp;
            }
            cnt += temp - 1;
            size_temp -= 1;
        }
        else if(temp > half_size) { // 배열이 오른쪽으로 이동할 때
            for (int j = 1; j < size + 1; j++) {
                if(arr[j] > temp)
                    arr[j] = arr[j] - temp;
                else
                     arr[j] = arr[j] + size_temp - temp;
            }
            cnt += size_temp - temp + 1;
            size_temp -= 1;
        }
    }


    printf("%d\n", cnt);

    return 0;
}
