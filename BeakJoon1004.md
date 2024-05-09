#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point center;
    int radius;
} Circle;

int containsPoint(Point p, Circle c) { // 원 안에 점이 위치하는 개수 계산
    double distance = sqrt(pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2));
    return distance <= c.radius;
}

int countPointsInCircles(Point p1, Point p2, Circle* circles, int n) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int p1Inside = containsPoint(p1, circles[i]);
        int p2Inside = containsPoint(p2, circles[i]);
        
        if (p1Inside && !p2Inside) {// 하나의 점만 원안에 존재할 때 카운트
            count++;
        } else if (!p1Inside && p2Inside) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        Point p1, p2;
        scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
        
  
        int n;
        scanf("%d", &n);
        

        Circle circles[n];
        
        for (int i = 0; i < n; i++) {

            Circle c;
            scanf("%d %d %d", &c.center.x, &c.center.y, &c.radius);
            circles[i] = c;
        }
        
      
        int result = countPointsInCircles(p1, p2, circles, n);
        
        printf("%d\n", result);
    }
    
    return 0;
}
