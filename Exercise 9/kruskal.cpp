#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

size_t n, m;

struct edge {
    unsigned u, v, w;

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

unsigned kruskal() {
    unsigned ans = 0;
    sort(edges.begin(), edges.end());

    for (edge e : edges) {
        if (find(e.u) == find(e.v)) {
            continue;
        }

        ans += e.w;
        unify(e.u, e.v);
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
        edges.push_back({ u, v, w});
    }

    kruskal();
    return 0;
}