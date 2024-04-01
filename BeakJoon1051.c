#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define POW2(X) ((X) == ((X)&(-(X))))

#define min(a, b) (((a) < (b)) ? (a) : (b)) 

int dirx[4] = {1, 1, 0}; 
int diry[4] = {0, 1, 1}; 

int main(void) {
    int n, m, maxlen; 
    scanf("%d %d", &n, &m);
    maxlen = min(n, m); 
    char arr[n][m + 1]; 

  
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

 
    for (int size = maxlen; size > 0; size--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int issquare = 1; 
                for (int k = 0; k < 3; k++) { 
                    int y = i + diry[k] * (size - 1); 
                    int x = j + dirx[k] * (size - 1); 

                   
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        if (arr[y][x] == arr[i][j]) { 
                            issquare = issquare && 1; 
                        } else {
                            issquare = 0; 
                        }
                    } else {
                        issquare = 0; 
                    }
                }
                if (issquare) { 
                    printf("%d", size * size); 
                    return 0; 
                }
            }
        }
    }

    return 0; 
}
