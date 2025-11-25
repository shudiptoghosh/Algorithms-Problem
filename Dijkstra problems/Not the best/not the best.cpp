#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
typedef pair<long long, int> PII;

vector<pair<int, int>> adj[5005];
long long dist1[5005], distN[5005];

void dijkstra(int start, long long dist[], int N) {
    for (int i = 1; i <= N; i++) dist[i] = INF;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &p : adj[u]) {
            int v = p.first;
            long long w = p.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, R;
        cin >> N >> R;

        for (int i = 1; i <= N; i++) adj[i].clear();
        vector<tuple<int,int,int>> edges;

        for (int i = 0; i < R; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            edges.push_back({u, v, w});
        }

        dijkstra(1, dist1, N);
        dijkstra(N, distN, N);

        long long best = dist1[N];
        long long second_best = INF;

        for (auto &e : edges) {
            int u, v, w;
            tie(u, v, w) = e;
            long long p1 = dist1[u] + w + distN[v];
            long long p2 = dist1[v] + w + distN[u];
            if (p1 > best) second_best = min(second_best, p1);
            if (p2 > best) second_best = min(second_best, p2);
        }

        cout << "Case " << tc << ": " << second_best << "\n";
    }
    return 0;
}

