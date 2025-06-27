#include <bits/stdc++.h>
using namespace std;

#define MAX 20010

unsigned nums[MAX], dp[2][MAX];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t i = 0;
    while (cin >> nums[i]) {
        ++i;
    }

    if (i == 0) {
        cout << 0;
        return 0;
    }

    dp[0][nums[0]] = 1;
    bool f = 1;

    for (size_t j = 1; j < i; ++j) {
        for (size_t p = 1; p < MAX; ++p) {
            dp[f][p] = p == nums[j] ? dp[!f][p - 1] + 1 : dp[!f][p];
        }

        f = !f;
    }

    unsigned opt = 0;

    for (size_t j = 1; j < MAX; ++j) {
        opt = max(opt, dp[!f][j]);
    }
    
    cout << opt;
    return 0;
}