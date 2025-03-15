#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000000

unsigned arr1[MAX_SIZE], arr2[MAX_SIZE];

int main() {
    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    for (size_t i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    size_t i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            cout << arr1[i] << " ";
            ++i;
        } else {
            cout << arr2[j] << " ";
            ++j;
        }
    }

    for (; i < n; ++i) {
        cout << arr1[i] << " ";
    }

    for (; j < m; ++j) {
        cout << arr2[j] << " ";
    }

    return 0;
}

