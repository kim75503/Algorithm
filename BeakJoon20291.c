#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int compare(const void *a, const void *b){
    return strcmp((char *)a, (char *)b);
}



int main() {

    char result[50000][101]; 
    int outputN[50000] = { 0, }; 
    int num = 0; 
    char string[101]; 
    char *ptr; 
    int cnt = 0; 

    scanf("%d", &num);
  
    for (int i = 0; i < num; i++){
        scanf("%s", string);
        ptr = strtok(string, ".");
        ptr = strtok(NULL, ".");
        strcpy(result[i], ptr);
    }

    qsort(result, num, sizeof(result[0]), compare);

    
    for(int i = 0; i < num; i++){
     if(strcmp(result[i],result[i+1]) == 0){
        outputN[cnt]++;
     }

    else if(strcmp(result[i],result[i+1]) != 0){
     printf("%s %d\n", result[i], outputN[cnt] + 1);
     cnt++;
    }
  }

  return 0;

}
