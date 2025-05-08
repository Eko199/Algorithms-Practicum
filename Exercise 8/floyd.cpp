#include<bits/stdc++.h>
using namespace std;

#define INF 500000000100
#define MAX 520
unsigned long long dist[MAX][MAX];

size_t n, m;

void floyd() {
    for (unsigned k = 1; k <= n; ++k) {
        for (unsigned i = 1; i <= n; ++i) {
            for (unsigned j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    size_t m, q;
    cin >> n >> m >> q;

    for (size_t i = 0; i <= n; ++i) {
        for (size_t j = 0; j <= n; ++j) {
            if (i != j) {
                dist[i][j] = INF;
            }
        }
    }

    unsigned a, b;
    unsigned long long c;
    for (size_t i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    floyd();

    for (size_t i = 0; i < q; ++i) {
        cin >> a >> b;
        if (dist[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }

    return 0;
}