#include<bits/stdc++.h>
using namespace std;

vector<unsigned> graph[1000005];
bool visited[1000005];

void bfs(unsigned v) {
    queue<unsigned> queue;
    queue.push(v);
    visited[v] = true;

    while (!queue.empty()) {
        v = queue.front();
        queue.pop();

        for (unsigned n : graph[v]) {
            if (!visited[n]) {
                queue.push(n);
                visited[n] = true;
            }
        }
    }
}

unsigned count_components(size_t n) {
    unsigned count = 0, v = 1;

    while (v <= n) {
        if (visited[v]) {
            ++v;
            continue;
        }

        ++count;
        bfs(v);
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
        unsigned v, u;
        cin >> v >> u;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    cout << count_components(n);
}