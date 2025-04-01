#include <bits/stdc++.h>
using namespace std;

size_t people(size_t l, size_t r, unsigned long long f, unsigned long long n) {
    if (l >= r) {
        return l;
    }

    size_t m = (r + l) / 2;
    size_t sum = m * f + m * (m - 1) / 2;

    if (sum < n) {
        return people(m + 1, r, f, n);
    } else {
        return people(l, m, f, n);
    }
}

int main() {
    unsigned long long n, f;
    cin >> n >> f;

    cout << people(1, sqrt(2 * n), f, n);
    return 0;
}