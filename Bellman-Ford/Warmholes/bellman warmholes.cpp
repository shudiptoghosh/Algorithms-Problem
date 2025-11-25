#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges(m);

        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

        vector<long long> dist(n, 0);
        bool neg = false;

        for (int i = 0; i < n - 1; i++) {
            for (auto &e : edges) {
                if (dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        for (auto &e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                neg = true;
                break;
            }
        }

        cout << (neg ? "possible\n" : "not possible\n");
    }

    return 0;
}

