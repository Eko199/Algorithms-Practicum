#include<bits/stdc++.h>
using namespace std;

vector<pair<unsigned, unsigned>> graph[100005];
unsigned dist[100005];
unsigned hotels[100005];
priority_queue<pair<unsigned, unsigned>, vector<pair<unsigned, unsigned>>, greater<pair<unsigned, unsigned>>> pq;

void dijkstra(unsigned v) {
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
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    unsigned u, v, d;

    for (size_t i = 0; i < m; ++i) {
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    for (size_t i = 0; i < n; ++i) {
        dist[i] = -1;
    }

    dist[n] = 0;

    unsigned k;
    cin >> k;
    unsigned place;
    
    for (size_t i = 0; i < k; ++i) {
        cin >> place;
        graph[n].push_back({place, 0});
    }

    dijkstra(n);
    
    unsigned q;
    cin >> q;

    for (unsigned i = 0; i < q; ++i) {
        unsigned hotel;
        cin >> hotel;
        hotels[i] = dist[hotel];
    }

    for (unsigned i = 0; i < q; ++i) {
        cout << hotels[i] << "\n";
    }
}