#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

size_t n, m;
vector<pair<unsigned, unsigned>> graph[MAX];

priority_queue<pair<unsigned long long, unsigned>> pq;
unsigned long cost[MAX];

void dijkstra(unsigned v) {
    fill(cost, cost + MAX, -1);
    cost[v] = 0;
    pq.push({ 0, v });

    while (!pq.empty()) {
        unsigned dist = pq.top().first;
        v = pq.top().second;
        pq.pop();

        for (auto e : graph[v]) {
            unsigned long w = v == 0 ? e.second : cost[e.second];

            if (cost[e.first] > cost[v] + w) {
                cost[e.first] = cost[v] + w;
                pq.push({ -cost[e.first], e.first });
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    unsigned c;

    for (size_t i = 1; i <= n; ++i) {
        cin >> c;
        graph[0].push_back({ i, c });
    }

    unsigned a, x, y;

    for (size_t i = 0; i < m; ++i) {
        cin >> a >> x >> y;
        graph[x].push_back({ a, y });
        graph[y].push_back({ a, x });
    }

    dijkstra(0);
    cout << cost[1];
    
    return 0;
}