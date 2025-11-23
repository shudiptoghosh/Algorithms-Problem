#include <bits/stdc++.h>

using namespace std;

bool isBipartite(int n, const vector<vector<int>>& adj) {
    vector<int> color(n, -1);
    queue<int> q;


    if (n > 0) {
        color[0] = 1;
        q.push(0);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 3 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n && n != 0) {
        int l;
        cin >> l;

        vector<vector<int>> adj(n);

        for (int i = 0; i < l; ++i) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (isBipartite(n, adj)) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }

    return 0;
}
