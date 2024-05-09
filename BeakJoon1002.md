#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t); 
    
    for (int i = 0; i < t; i++) {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2); 
        
        // 두 원의 중심 사이의 거리 계산
        double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        
        // 교차점 개수를 판별하고 출력
        if (d == 0 && r1 == r2) { 
            printf("-1\n"); 
        } else if (d == 0 || r1 + r2 < d || fabs(r1 - r2) > d) { 
            printf("0\n"); 
        } else if (fabs(r1 - r2) == d || r1 + r2 == d) { 
            printf("1\n");
        } else if (d < r1 + r2) { 
            printf("2\n"); 
      }
    }
    
    return 0;
}
