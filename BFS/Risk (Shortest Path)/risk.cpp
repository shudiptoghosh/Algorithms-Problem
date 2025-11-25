#include <bits/stdc++.h>
using namespace std;

vector<int> adj[21];
int bfs(int start, int end) {
    vector<int> dist(21, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end) {
            return dist[u];
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    int numNeighbors, neighbor;
    int testSet = 1;
    while (cin >> numNeighbors) {
        for (int i = 0; i < 21; i++) {
            adj[i].clear();
        }

        for (int j = 0; j < numNeighbors; j++) {
            cin >> neighbor;
            adj[1].push_back(neighbor);
            adj[neighbor].push_back(1);
        }

        for (int i = 2; i <= 19; i++) {
            cin >> numNeighbors;
            for (int j = 0; j < numNeighbors; j++) {
                cin >> neighbor;
                adj[i].push_back(neighbor);
                adj[neighbor].push_back(i);
            }
        }
        int N;
        cin >> N;

        printf("Test Set #%d\n", testSet++);

        int start, end;
        for (int i = 0; i < N; i++) {
            cin >> start >> end;
            int result = bfs(start, end);
            printf("%2d to %2d: %d\n", start, end, result);
        }
        printf("\n");
    }

    return 0;
}
