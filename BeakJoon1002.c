#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        
        double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        
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
