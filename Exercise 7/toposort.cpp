//O(n+m)
#include<bits/stdc++.h>
using namespace std;

vector<unsigned> graph[10005];
unsigned counter[10005];
priority_queue<unsigned, vector<unsigned>, greater<unsigned>> pq;

void topo(size_t n) {
    for (size_t i = 1; i <= n; ++i) {
        if (counter[i] == 0) {
            pq.push(i);
        }
    }

    vector<unsigned> ans = {};

    while (!pq.empty()) {
        unsigned v = pq.top();
        pq.pop();

        ans.push_back(v);

        for (unsigned u : graph[v]) {
            if (--counter[u] == 0) {
                pq.push(u);
            }
        }
    }

    if (ans.size() != n) {
        cout << "Sandro fails.";
        return;
    }
    
    for (unsigned v : ans) {
        cout << v << " ";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        ++counter[v];
    }

    topo(n);
}