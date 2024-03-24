#include <stdio.h>
#include <stdlib.h>

int one_divide(int a);

int one_divide(int a){
  int dv[a + 1];
  
  dv[1] = 0;

  for (int i = 2; i<= a; i++){
    dv[i] = dv[i - 1] + 1;
    if (i % 2 == 0 ){
      dv[i] = dv[i] < dv[i/2] + 1 ? dv[i] : dv[i/2] + 1;
    }
    if (i % 3 == 0){
      dv[i] = dv[i] < dv[i/3] + 1 ? dv[i] : dv[i/3] + 1;
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
