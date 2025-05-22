#include<bits/stdc++.h>
using namespace std;

vector<pair<unsigned, unsigned>> graph[1005];
unsigned dist[1005];
priority_queue<pair<unsigned, unsigned>, vector<pair<unsigned, unsigned>>, greater<pair<unsigned, unsigned>>> pq;

void dijkstra(size_t n, unsigned v) {
    pq.push({dist[v], v});

    while (!pq.empty()) {
        unsigned v = pq.top().second;
        pq.pop();

        for (auto u : graph[v]) {
            unsigned d = dist[v] + u.second;

            if (d < dist[u.first]) {
                dist[u.first] = d;
                pq.push({dist[u.first], u.first});
            }
        }
    }

    for (unsigned i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i < m; ++i) {
        unsigned u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    for (size_t i = 0; i <= n; ++i) {
        dist[i] = -1;
    }

    unsigned s;
    cin >> s;
    dist[s] = 0;
    dijkstra(n, s);
}