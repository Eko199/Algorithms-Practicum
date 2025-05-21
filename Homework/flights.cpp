#include <bits/stdc++.h>
using namespace std;

#define MAX 200010

struct edge {
    unsigned u;
    bool is_flight;
    unsigned n;
};

size_t n, m, k;
vector<edge> graph[MAX];

queue<pair<unsigned, unsigned>> q;
bool visited[MAX];
unsigned result[MAX];

bool bfs(unsigned v) {
    q.push({ v, 1 });
    visited[v] = true;

    for (size_t i = 1; i <= m; ++i) {
        result[i] = -1;
    }

    bool f = false;

    while (!q.empty()) {
        v = q.front().first;
        unsigned level = q.front().second;
        q.pop();

        for (edge e : graph[v]) {
            if (visited[e.u]) {
                continue;
            }

            if (e.is_flight) {
                result[e.n] = min(result[e.n], level);

                if (level == k) {
                    f = true;
                }
            }

            q.push({ e.u, 1 + (level + e.is_flight - 1) % k });
            visited[e.u] = true;
        }
    }

    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    unsigned u, v;
    bool w;

    for (size_t i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back({ v, w, i });
        graph[v].push_back({ u, w, i });
    }

    if (!bfs(1)) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";
    for (size_t i = 1; i <= m; ++i) {
        if (result[i] <= k) {
            cout << result[i] << '\n';
        }
    }

    return 0;
}