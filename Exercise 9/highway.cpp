#include <bits/stdc++.h>
using namespace std;

#define MAX 50010

size_t n, m;

struct edge {
    unsigned u, v;
    bool w;

    bool operator<(const edge& other) const {
        return w < other.w;
    }
};

deque<edge> edges;

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
    unsigned ans = 0;

    for (edge e : edges) {
        if (find(e.u) == find(e.v)) {
            continue;
        }

        ans += e.w;
        unify(e.u, e.v);
    }

    cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    unsigned u, v;
    bool w;

    for (size_t i = 0; i < m; ++i) {
        cin >> u >> v >> w;

        if (w) {
            edges.push_back({ u, v, w });
        } else {
            edges.push_front({ u, v, w });
        }
    }

    for (size_t i = 0; i <= n; ++i) {
        par[i] = i;
    }

    kruskal();
    return 0;
}