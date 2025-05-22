#include <bits/stdc++.h>
using namespace std;

#define MAX 200010

struct edge {
    unsigned u;
    bool is_flight;
};

size_t n, m, k;
vector<edge> graph[MAX];

priority_queue<pair<unsigned, unsigned>, vector<pair<unsigned, unsigned>>, greater<pair<unsigned, unsigned>>> pq;
unsigned d[MAX];

void dijkstra(unsigned v) {
    for (size_t i = 0; i <= n; ++i) {
        d[i] = -1;
    }

    d[v] = 0;
    pq.push({ 0, v });

    while (!pq.empty()) {
        v = pq.top().second;
        pq.pop();

        for (edge e : graph[v]) {
            if (d[e.u] > d[v] + e.is_flight) {
                d[e.u] = d[v] + e.is_flight;
                pq.push({ d[e.u], e.u });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    unsigned u, v;
    bool w;
    queue<pair<unsigned, unsigned>> fly_lanes = {}; 

    for (size_t i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });

        if (w) {
            fly_lanes.push({ u, v });
        }
    }

    dijkstra(1);

    if (d[n] < k) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";
    while (!fly_lanes.empty()) {
        auto e = fly_lanes.front();
        fly_lanes.pop();
        unsigned dist = max(d[e.first], d[e.second]);

        if (dist > k) {
            cout << "1\n";
        } else {
            cout << dist << '\n';
        }
    }

    return 0;
}