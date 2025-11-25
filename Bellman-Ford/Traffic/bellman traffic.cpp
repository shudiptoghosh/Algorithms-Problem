#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v; long long w; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cs = 1;
    while (cin >> n) {
        vector<int> busy(n + 1);
        for (int i = 1; i <= n; i++) cin >> busy[i];

        int r;
        cin >> r;

        vector<Edge> edges;
        while (r--) {
            int u, v;
            cin >> u >> v;
            long long w = busy[v] - busy[u];
            w = w * w * w;
            edges.push_back({u, v, w});
        }

        vector<long long> dist(n + 1, LLONG_MAX);
        dist[1] = 0;

        for (int i = 1; i < n; i++) {
            for (auto &e : edges) {
                if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v])
                    dist[e.v] = dist[e.u] + e.w;
            }
        }

        vector<bool> bad(n + 1, false);
        for (auto &e : edges) {
            if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v])
                bad[e.v] = true;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) if (bad[i]) q.push(i);

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) adj[e.u].push_back(e.v);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!bad[v]) {
                    bad[v] = true;
                    q.push(v);
                }
            }
        }

        int qn;
        cin >> qn;

        cout << "Set #" << cs++ << "\n";
        while (qn--) {
            int x;
            cin >> x;
            if (x < 1 || x > n || dist[x] == LLONG_MAX || dist[x] < 3 || bad[x])
                cout << "?\n";
            else
                cout << dist[x] << "\n";
        }
    }
    return 0;
}

