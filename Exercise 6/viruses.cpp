//O(n+m) without sort
#include<bits/stdc++.h>
using namespace std;

bool visited[105][105];

bool is_valid(unsigned x, unsigned y, size_t n, size_t m) {
    return x > 0 && y > 0 && x <= n && y <= m && !visited[x][y];
}

void dfs(unsigned x, unsigned y, size_t n, size_t m) {
    visited[x][y] = true;

    if (is_valid(x - 1, y, n, m)) {
        dfs(x - 1, y, n, m);
    }

    if (is_valid(x, y - 1, n, m)) {
        dfs(x, y - 1, n, m);
    }

    if (is_valid(x + 1, y, n, m)) {
        dfs(x + 1, y, n, m);
    }

    if (is_valid(x, y + 1, n, m)) {
        dfs(x, y + 1, n, m);
    }
}

unsigned count_components(size_t n, size_t m) {
    unsigned count = 0, v = 1;

    for (unsigned x = 1; x <= n; ++x) {
        for (unsigned y = 1; y <= m; ++y) {
            if (visited[x][y]) {
                continue;
            }

            ++count;
            dfs(x, y, n, m);
        }
    }

    return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    size_t n, m, k;
    cin >> n >> m >> k;

    for (size_t i = 0; i < k; ++i) {
        unsigned x, y;
        cin >> x >> y;
        visited[x][y] = true;
    }

    cout << count_components(n, m);
}