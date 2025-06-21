#include <bits/stdc++.h>
using namespace std;

unsigned l[1010];
vector<int> v[1010];
vector<unsigned> w[1010];
int dp[2][5010][110];

int n, m, k, c;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    unsigned v1, w1;
    cin >> n >> m >> k >> c;

    for (size_t i = 1; i <= n; ++i) {
        cin >> l[i];

        for (size_t j = 0; j < l[i]; ++j) {
            cin >> v1 >> w1;
            v[i].push_back(v1);
            w[i].push_back(w1);
        }
    }

    bool f = 1;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t s = 1; s <= m; ++s) {
            for (size_t p = 0; p < k; ++p) {
                dp[f][s][p] = dp[!f][s][p];

                for (size_t j = 1; j <= l[i]; ++j) {
                    if (s < w[i][j - 1]) {
                        continue;
                    }

                    if (p >= j - 1) {
                        dp[f][s][p] = max(dp[f][s][p], v[i][j - 1] + dp[!f][s - w[i][j - 1]][p - j + 1]);
                        continue;
                    }
                    
                    int x = (j - 1 - p + k - 1) / k;
                    dp[f][s][p] = max(dp[f][s][p], v[i][j - 1] + dp[!f][s - w[i][j - 1]][k * x + p - j + 1] - c * x);
                }
            }
        }

        f = !f;
    }
    
    cout << dp[!f][m][0];
    return 0;
}