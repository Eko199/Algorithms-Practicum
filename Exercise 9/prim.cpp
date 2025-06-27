#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

size_t n, m;

vector<pair<unsigned, unsigned>> graph[MAX];
bool used[MAX];
priority_queue<pair<unsigned, unsigned>, vector<pair<unsigned, unsigned>>, greater<pair<unsigned, unsigned>>> pq;
unsigned par[MAX], d[MAX];

unsigned find(unsigned x) {
    if (x == par[x]) {
        return x;
    }

    return par[x] = find(par[x]);
}

void unify(unsigned x, unsigned y   ) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return;
    }

    if (d[x] < d[y]) {
        swap(x, y);
    }

    par[y] = x;
    if (d[x] == d[y]) {
        ++d[x];
    }
}

unsigned prim(unsigned v) {
    unsigned ans = 0;

    for (auto e : graph[v]) {
        pq.push({ e.second, e.first });
    }

    while (!pq.empty()) {
        unsigned node = pq.top().second;
        unsigned cost = pq.top().first;
        pq.pop();

        if (used[node]) {
            continue;
        }

        used[node] = true;
        ans += cost;

        for (auto u : graph[node]) {
            pq.push({ u.first, u.second });
        }
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    unsigned u, v, w;

    for (size_t i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back({ v, w});
        graph[v].push_back({ u, w});
    }
    
    prim(1);
    return 0;
}