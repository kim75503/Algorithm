#include <stdio.h>

int main(void){
  int n, i;
  int dist[100000];
  int cost[100000];
  long long min_cost=0; 
  
  scanf("%d", &n);
  for(i=0;i<n-1;i++){
    scanf("%d", &dist[i]);
  }

  for(i=0;i<n;i++){
    scanf("%d", &cost[i]);
  }

  int c = cost[0];
  for(i=0;i<n-1;i++){
    if(c>cost[i]){
      c = cost[i];
      }
      min_cost += (long long) c*dist[i];
  }

  printf("%lld", min_cost);
}
