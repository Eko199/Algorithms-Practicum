//O(n+m) without sort
#include<bits/stdc++.h>
using namespace std;

vector<unsigned> graph[105];
bool visited[105];

void bfs(unsigned v) {
    queue<unsigned> queue;
    queue.push(v);
    visited[v] = true;

    while (!queue.empty()) {
        v = queue.front();
        queue.pop();
        
        cout << v << " ";

        for (unsigned n : graph[v]) {
            if (!visited[n]) {
                queue.push(n);
                visited[n] = true;
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

    for (size_t i = 0; i < m; ++i) {
        unsigned v, u;
        cin >> v >> u;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    for (size_t i = 0; i < n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(0);
}