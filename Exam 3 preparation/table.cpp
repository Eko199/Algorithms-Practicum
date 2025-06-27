#include <bits/stdc++.h>
using namespace std;

#define MAX 1010

unsigned table[MAX][MAX], dp[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    size_t n, m;
    cin >> m >> n;

    for (size_t row = 0; row < m; ++row) {
        for (size_t col = 0; col < n; ++col) {
            cin >> table[row][col];
        }

        dp[row][0] = table[row][0];
    }

    unsigned opt = -1;

    for (size_t col = 1; col < n; ++col) {
        for (size_t row = 0; row < m; ++row) {
            dp[row][col] = dp[row][col - 1];

            if (row > 0) {
                dp[row][col] = min(dp[row][col], dp[row - 1][col - 1]);
            }

            if (row + 1 < m) {
                dp[row][col] = min(dp[row][col], dp[row + 1][col - 1]);
            }

            dp[row][col] += table[row][col];

            if (col == n - 1) {
                opt = min(opt, dp[row][col]);
            }
        }
    }

    cout << opt;
    return 0;
}