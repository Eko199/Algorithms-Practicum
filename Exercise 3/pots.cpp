#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100010
unsigned pots[MAX_SIZE];
unsigned lids[MAX_SIZE];

int main() {
    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i < n; ++i) {
        cin >> pots[i];
    }

    for (size_t i = 0; i < m; ++i) {
        cin >> lids[i];
    }

    sort(pots, pots + n);
    sort(lids, lids + m);

    unsigned result = 0;
    size_t curr_lid = 0;

    for (size_t i = 0; i < n; ++i) {
        while (curr_lid < m && pots[i] > lids[curr_lid]) {
            ++curr_lid;
        }

        if (curr_lid >= m) {
            break;
        }

        ++result;
        ++curr_lid;
    }

    cout << result;
    return 0;
}


