#include <bits/stdc++.h>
using namespace std;

#define MAX 505

const unsigned d = 1000000007;
unsigned long long dp[MAX][MAX * MAX / 2];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned n, l, r;
    cin >> n >> l >> r;
    
    for (size_t p = 0; p <= r; ++p) {
        dp[1][p] = 1;
    }

    for (size_t i = 2; i <= n; ++i) {
        dp[i][0] = 1;

        for (size_t p = 1; p <= r; ++p) {
            dp[i][p] = (dp[i - 1][p] + dp[i][p - 1]) % d;

            if (p >= i) {
                dp[i][p] = (d + dp[i][p] - dp[i - 1][p - i]) % d;
            }
        }
    }
    
    cout << (d + dp[n][r] - (l == 0 ? 0 : dp[n][l - 1])) % d;
    return 0;
}