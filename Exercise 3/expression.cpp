#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 110
int arr[MAX_SIZE];

int main() {
    size_t n, m, p;
    cin >> n >> m >> p;

    for (size_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (size_t i = 0; i < m; ++i) {
        arr[i] = -arr[i];
    }

    long result = 0;

    for (size_t i = 0; i < n; ++i) {
        result += arr[i];
    }

    cout << result;
    return 0;
}

