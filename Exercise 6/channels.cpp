#include<bits/stdc++.h>
using namespace std;

vector<pair<unsigned, unsigned>> graph[1000005];
bool visited[1000005];

void bfs(unsigned v, unsigned k) {
    queue<unsigned> queue;
    queue.push(v);
    visited[v] = true;

    while (!queue.empty()) {
        v = queue.front();
        queue.pop();

        for (pair<unsigned, unsigned> n : graph[v]) {
            if (!visited[n.first] && n.second >= k) {
                queue.push(n.first);
                visited[n.first] = true;
            }
        }
    }
}

unsigned count_components(size_t n, unsigned k) {
    unsigned count = 0, v = 1;

    for (size_t v = 1; v <= n; ++v) {
        if (visited[v]) {
            continue;
        }

        ++count;
        bfs(v, k);
    }

    return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i < m; ++i) {
        unsigned v, u, d;
        cin >> v >> u >> d;

        graph[v].push_back({u, d});
        graph[u].push_back({v, d});
    }

    unsigned k;
    cin >> k;

    cout << count_components(n, k) - 1;
}