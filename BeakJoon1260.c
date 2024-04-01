#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1001 

int graph[MAX_SIZE][MAX_SIZE] = {0}; 
bool visited[MAX_SIZE] = {false}; 


void dfs(int V, int N) {
    visited[V] = true; 
    printf("%d ", V); 
    for (int i = 1; i <= N; i++) {
        if (graph[V][i] == 1 && !visited[i]) {
            dfs(i, N); 
        }
    }
}

void bfs(int V, int N) {
    int queue[MAX_SIZE];
    int front = 0, rear = 0;
    visited[V] = true; 
    printf("%d ", V); 
    queue[rear++] = V;
    while (front < rear) {
        int node = queue[front++]; 
        for (int i = 1; i <= N; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true; 
                printf("%d ", i); 
                queue[rear++] = i; 
            }
        }
    }
}

int main() {
    int N, M, V; 
    scanf("%d %d %d", &N, &M, &V); 

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1; 
    }

    dfs(V, N);
    printf("\n");

    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }

    bfs(V, N);
    printf("\n");

    return 0;
}
