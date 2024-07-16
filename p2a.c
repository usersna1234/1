#include <stdio.h>
#define MAX_VERTICES 10
int n;
int a[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
void bfs(int source) {
    int q[MAX_VERTICES], f = 0, r = -1;
    visited[source] = 1;
    q[++r] = source;
    while (f <= r) {
        int u = q[f++];
        printf("Node %d is reachable\n", u);
        for (int v = 1; v <= n; ++v) {
            if (a[u][v] == 1 && !visited[v]) {
                visited[v] = 1;
                q[++r] = v;
            }
        }
    }
}
int main() {
    int source;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the directed graph:\n");
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    for (int i = 1; i <= n; ++i)
        visited[i] = 0;
    bfs(source);
    return 0;
}

