#include <bits/stdc++.h>
using namespace std;

vector<pair<unsigned, bool>> graph[10005];
int visited[10005];
size_t counter, comp;

void dfs(unsigned v) {
    ++comp;
    if (visited[v] == 1) {
        ++counter;
    }

    for (auto n : graph[v]) {
        if (visited[n.first] != 0) {
            continue;
        }

        visited[n.first] = n.second ? visited[v] : 3 - visited[v];
        dfs(n.first);
    }
}

int main() {
    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        char c;

        cin >> u >> c >> v;
        graph[v].push_back({ u, c == 'h'});
        graph[u].push_back({ v, c == 'h'});
    }

    size_t result = 0;

    for (size_t i = 1; i <= n; ++i) {
        if (visited[i]) {
            continue;
        }

        visited[i] = 1;
        counter = 0;
        comp = 0;
        dfs(i);

        result += max(counter, comp - counter);
    }

    cout << result;
    return 0;
}