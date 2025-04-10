#include<bits/stdc++.h>
using namespace std;

vector<unsigned> graph[1005];
bool visited[1005];
unsigned comp[1005];
bool result[100005];

void dfs(unsigned v, unsigned component) {
    visited[v] = true;
    comp[v] = component;

    for (unsigned neighbour : graph[v]) {
        if (!visited[neighbour]) {
            dfs(neighbour, component);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    for (size_t i = 1; i <= m; ++i) {
        unsigned v, u;
        cin >> v >> u;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    
    for (size_t i = 1; i <= n; ++i) {
        if (visited[i]) {
            continue;
        }

        dfs(i, i);
    }

    unsigned q;
    cin >> q;

    for (size_t i = 0; i < q; ++i) {
        unsigned start, end;
        cin >> start >> end;
        
        result[i] = comp[start] == comp[end];
    }

    for (size_t i = 0; i < q; ++i) {
        cout << result[i];
    }
}