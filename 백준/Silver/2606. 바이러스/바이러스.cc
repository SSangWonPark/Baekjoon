#include <stdio.h>

int n = 0, m = 0;
int graph[101][101] = { 0, };
int visited[101] = { 0, };
int count = 0;

void dfs(int v){
    visited[v] = 1;

    for (int i = 1; i < n + 1; i++)
    {   
        if (!visited[i] && graph[v][i])
        {
            count++;
            dfs(i);
        }   
    }
}

int main() {
    int a = 0, b = 0;

    scanf("%d %d", &n, &m);

    for (int j = 0; j < m; j++)
    {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(1);
    printf("%d", count);

    return 0;
}

// dfs
// 그래프를 그려서 깊이 우선으로 탐색.
/*
input:
7
6
1 2
2 3
1 5
5 2
5 6
4 7

그래프 만들기
  0 1 2 3 4 5 6 7
0 0 0 0 0 0 0 0 0
1 0 0 1 0 0 1 0 0
2 0 1 0 1 0 1 0 0
3 0 0 1 0 0 0 0 0
4 0 0 0 0 0 0 0 1
5 0 1 1 0 0 0 1 0
6 0 0 0 0 0 1 0 0
7 0 0 0 0 1 0 0 0

visited[]에 넣으면서 없는 경우 추가
1에서 가장 먼저 갈 수 있는 노드 2
2에서 가장 먼저 갈 수 있는 노드 3
3에서 가장 먼저 갈 수 있는 노드 X
1에서 2를 빼고 갈 수 있는 노드 5
5에서 가장 먼저 갈 수 있는 노드 7
7에서는 4를 방문했기 때문에 종료.
함수는 모두 확인하지만 다 방문했기에 실상 종료.
2 3 5 7 답은 4
*/