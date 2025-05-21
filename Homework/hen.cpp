#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

size_t n, m;
unsigned p[MAX];
vector<pair<unsigned, unsigned>> graph[MAX];

unsigned comp[MAX];

void dfs(unsigned v, unsigned minW, unsigned component) {
    comp[v] = component;

    for (auto e : graph[v]) {
        if (e.second >= minW && comp[e.first] != component) {
            dfs(e.first, minW, component);
        }
    }
}

bool check(unsigned minW) {
    for (unsigned v = 1; v <= n; ++v) {
        comp[v] = 0;
    }

    for (unsigned v = 1; v <= n; ++v) {
        if (comp[v] == 0) {
            dfs(v, minW, v);
        }
    }

    for (unsigned v = 1; v <= n; ++v) {
        if (comp[v] != comp[p[v]]) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    unsigned pos;
    for (size_t i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    unsigned a, b, w, maxw = 0;
    for (size_t i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });

        maxw = max(maxw, w);
    }

    unsigned l = 1, r = maxw + 10, mid;
    
    while (l < r) {
        mid = (l + r + 1) / 2;
        
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    
    if (l > maxw) {
        cout << -1;
    } else {
        cout << l;
    }
    
    return 0;
}