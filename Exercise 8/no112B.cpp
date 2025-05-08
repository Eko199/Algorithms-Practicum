#include <bits/stdc++.h>
using namespace std;

#define MAX 1100

unsigned comp[MAX], h[MAX];

unsigned find(unsigned x) {
    if (comp[x] == x) {
        return x;
    }

    return comp[x] = find(comp[x]);
}

void unify(unsigned x, unsigned y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return;
    }

    if (h[x] < h[y]) {
        swap(x, y);
    }

    comp[y] = x;
    if (h[x] == h[y]) {
        ++h[x];
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i <= n; ++i) {
        comp[i] = i;
        h[i] = 0;
    }

    unsigned a, b;
    for (size_t i = 0; i < m; ++i) {
        cin >> a >> b;
        unify(a, b);
    }

    unsigned q, t;
    cin >> q;

    for (unsigned i = 0; i < q; ++i) {
        cin >> t >> a >> b;

        if (t == 1) {
            cout << (find(a) == find(b));
        } else {
            unify(a, b);
        }
    }

    return 0;
}