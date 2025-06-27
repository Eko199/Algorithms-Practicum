#include <bits/stdc++.h>
using namespace std;

#define MAX 85

unsigned long long dp[MAX];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned k, n;
    cin >> n >> k;

    for (unsigned i = 2; i <= n; ++i) {
        dp[i] = i <= k;

        for (unsigned j = 2; j <= min(k, i - 2); ++j) {
            dp[i] += dp[i - j];

            if (i % j == 0) {
                dp[i] += dp[i / j];
            }
        }
    }
    
    cout << dp[n];
    return 0;
}