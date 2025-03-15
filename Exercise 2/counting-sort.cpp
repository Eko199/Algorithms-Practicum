#include <bits/stdc++.h>
using namespace std;

size_t hist[1000];

int main() {
    size_t n;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        ++hist[arr[i]];
    }

    size_t counter = 0;

    for (size_t i = 0; i < 1000; ++i) {
        for (size_t j = 0; j < hist[i]; ++j) {
            cout << i << " ";
        }

        counter += hist[i];

        if (counter >= n) {
            break;
        }
    }

    return 0;
}

