#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100

unsigned comp[MAX];
unsigned long long h[MAX];
unsigned long long couples;

unsigned find(unsigned v) {
    if (comp[v] == v) {
        return v;
    }

    return comp[v] = find(comp[v]);
}

void unify(unsigned u, unsigned v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        return;
    }

    if (h[u] > h[v]) {
        swap(u, v);
    }

    couples -= h[u] * h[v];

    comp[u] = v;
    h[v] += h[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    unsigned m;
    cin >> n >> m;

    couples = n * (n - 1) / 2;

    for (size_t i = 0; i < n; ++i) {
        comp[i] = i;
        h[i] = 1;
    }

    unsigned x, y;
    for (size_t i = 0; i < m; ++i) {
        cin >> x >> y;
        unify(x, y);
    }

    cout << couples;
    return 0;
}