#include <bits/stdc++.h>
using namespace std;

size_t arr[300000];

int main() {
    size_t n;
    unsigned r;

    cin >> n >> r;

    for (size_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long result = 0;

    size_t j = 1;

    for (size_t i = 0; i < n - 1; ++i) {
        for (; j < n; ++j) {
            if (arr[j] - arr[i] > r) {
                result += n - j;
                break;
            }
        }
    }

    cout << result;
    return 0;
}

