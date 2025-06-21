#include <bits/stdc++.h>
using namespace std;

#define MAX 20010
#define edge pair<unsigned, unsigned>

size_t n;
unsigned m, k;
vector<edge> graph[MAX];

priority_queue<edge, vector<edge>, greater<edge>> pq;
unsigned d[MAX];

void dijkstra(unsigned v) {
    for (size_t u = 1; u <= n; ++u) {
        d[u] = -1;
    }

    d[v] = 0;
    pq.push({ 0, v });

    while (!pq.empty()) {
        v = pq.top().second;
        pq.pop();

        for (edge e : graph[v]) {
            if (d[e.first] > d[v] + e.second) {
                d[e.first] = d[v] + e.second;
                pq.push({ d[e.first], e.first });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    unsigned u, v, p, t;

    for (unsigned i = 0; i < m; ++i) {
        cin >> u >> v >> p >> t;
        graph[u].push_back({ v, t - p });
        graph[v].push_back({ u, t - p });
    }

    dijkstra(1);
    cout << (int)k - (int)d[n];

    return 0;
}