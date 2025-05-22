#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

size_t n, m;

vector<pair<unsigned, unsigned>> graph[MAX], graph_rev[MAX];

unsigned early[MAX], late[MAX];
unsigned counter1[MAX], counter2[MAX];

void toposort() {
    queue<unsigned> q;

    for (size_t i = 0; i < n; ++i) {
        if (counter1[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        unsigned v = q.front();
        q.pop();

        for (auto e : graph[v]) {
            if (--counter1[e.first] == 0) {
                q.push(e.first);
            }
            
            early[e.first] = max(early[e.first], early[v] + e.second);
        }
    }
}


void toposort_rev(unsigned last) {
    queue<unsigned> q;

    for (size_t i = 0; i < n; ++i) {
        if (counter2[i] == 0) {
            q.push(i);
            late[i] = last;
        }
    }

    while (!q.empty()) {
        unsigned v = q.front();
        q.pop();

        for (auto e : graph_rev[v]) {
            if (--counter2[e.first] == 0) {
                q.push(e.first);
            }

            late[e.first] = min(late[e.first], late[v] - e.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    unsigned u, v, t;
    queue<pair<unsigned, pair<unsigned, unsigned>>> tasks;

    for (size_t i = 0; i < m; ++i) {
        cin >> u >> v >> t;

        graph[u].push_back({ v, t });
        graph_rev[v].push_back({ u, t });

        ++counter1[v];
        ++counter2[u];

        tasks.push({ u, { v, t } });
    }

    toposort();
    fill(late, late + MAX, -1);

    unsigned total = early[0];
    
    for (size_t i = 1; i < n; ++i) {
        total = max(total, early[i]);
    }
    
    toposort_rev(total);
    cout << total << '\n';

    while (!tasks.empty()) {
        auto task = tasks.front();
        tasks.pop();

        cout << early[task.first] << " " << late[task.second.first] - task.second.second << "\n";
    }

    return 0;
}