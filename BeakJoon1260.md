#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1001 

int graph[MAX_SIZE][MAX_SIZE] = {0}; 
bool visited[MAX_SIZE] = {false}; 

// 깊이 우선 탐색(DFS) 함수 
void dfs(int V, int N) {
    visited[V] = true; // 현재 정점을 방문 했음을 표시
    printf("%d ", V); 
    for (int i = 1; i <= N; i++) {
        if (graph[V][i] == 1 && !visited[i]) {
            dfs(i, N); // i 정점으로 이동하여 재귀적으로 DFS 수행
        }
    }
}

// 너비 우선 탐색(BFS) 함수 
void bfs(int V, int N) {
    int queue[MAX_SIZE]; 
    int front = 0, rear = 0; 
    visited[V] = true; // 시작 정점을 방문 했음을 표시
    printf("%d ", V); 
    queue[rear++] = V; // 시작 정점을 큐에 넣음
    // 큐가 비어있지 않은 동안
    while (front < rear) {
        int node = queue[front++]; // 큐의 맨 앞의 정점을 꺼냄
        for (int i = 1; i <= N; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true; 
                printf("%d ", i); 
                queue[rear++] = i; // i 정점을 큐에 넣음
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
