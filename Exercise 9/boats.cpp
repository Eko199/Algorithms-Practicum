#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

struct edge {
    unsigned u, v, w;

    bool operator<(const edge& other) const {
        return w > other.w;
    }
};

vector<edge> edges;
vector<pair<unsigned, unsigned>> queries;

unsigned par[MAX], d[MAX], ans[MAX];

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
    sort(edges.begin(), edges.end());

    for (edge e : edges) {
        if (find(e.u) == find(e.v)) {
            continue;
        }

        unify(e.u, e.v);

        for (size_t i = 0; i < queries.size(); ++i) {
            if (ans[i] == 0 && find(queries[i].first) == find(queries[i].second)) {
                ans[i] = e.w;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    unsigned k, u, v, w;
    cin >> n >> m >> k;

    for (size_t i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges.push_back({ u, v, w });
    }

    for (unsigned i = 0; i < k; ++i) {
        cin >> u >> v;
        queries.push_back({ u, v });
    }

    for (size_t i = 0; i <= n; ++i) {
        par[i] = i;
    }

    kruskal();

    for (unsigned i = 0; i < k; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}