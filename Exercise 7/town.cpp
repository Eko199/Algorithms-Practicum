#include<bits/stdc++.h>
using namespace std;

vector<pair<unsigned, bool>> graph[200005];
unsigned dist[200005];
deque<pair<unsigned, unsigned>> dq;

void dijkstra(size_t n, unsigned v) {
    for (size_t i = 0; i <= n; ++i) {
        dist[i] = -1;
    }

    dist[v] = 0;
    dq.push_front({dist[v], v});

    while (!dq.empty()) {
        unsigned v = dq.front().second;
        unsigned dcurr = dq.front().first;
        dq.pop_front();

        if (dcurr > dist[v]) {
            continue;
        }

        for (auto u : graph[v]) {
            unsigned d = dist[v] + u.second;

            if (d < dist[u.first]) {
                dist[u.first] = d;

                if (u.second == 0) {
                    dq.push_front({dist[u.first], u.first});
                } else {
                    dq.push_back({dist[u.first], u.first});
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    size_t n;
    unsigned a, b, p, q;
    cin >> n >> a >> b;

    while (cin >> p >> q) {
        graph[p].push_back({q, 0});
        graph[q].push_back({p, 1});
    }

    dijkstra(n, a);

    if (dist[b] == -1) {
        cout << "X";
    } else {
        cout << dist[b];
    }
}