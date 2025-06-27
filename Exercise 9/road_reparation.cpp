#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

size_t n, m;

struct edge {
    unsigned u, v;
    long w;

    bool operator<(const edge& other) const {
        return w < other.w;
    }
};

vector<edge> edges;

unsigned par[MAX], d[MAX];

unsigned find(unsigned x) {
    if (x == par[x]) {
        return x;
    }

    return par[x] = find(par[x]);
}

void unify(unsigned x, unsigned y) {
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

void kruskal() {
    long long ans = 0, cnt = 0;
    sort(edges.begin(), edges.end());

    for (edge e : edges) {
        if (find(e.u) == find(e.v)) {
            continue;
        }

        ans += e.w;
        unify(e.u, e.v);
        ++cnt;
    }

    if (cnt == n - 1) {
        cout << ans;
    } else {
        cout << "IMPOSSIBLE";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    unsigned u, v;
    long w;

    for (size_t i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges.push_back({ u, v, w});
    }

    for (size_t i = 0; i <= n; ++i) {
        par[i] = i;
    }

    kruskal();
    return 0;
}