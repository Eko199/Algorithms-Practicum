#include<bits/stdc++.h>
using namespace std;

unsigned p[100005];

bool can_eat(size_t n, unsigned k, unsigned s, unsigned t) {
    unsigned to_eat = t * s;

    for (size_t i = 0; i < n; ++i) {
        if (to_eat >= p[i]) {
            to_eat -= p[i];
            continue;
        }

        if (--k == 0) {
            return false;
        }

        to_eat = t * s;
        --i;
    }

    return true;
}

int main() {
    size_t n;
    unsigned k, s;

    cin >> n >> k >> s;
    unsigned long sum = 0;

    for (size_t i = 0; i < n; ++i) {
        cin >> p[i];
        sum += p[i];
    }

    unsigned left = 1, right = sum / s + 1, mid;

    while (left < right) {
        mid = (left + right) / 2;
        
        if (can_eat(n, k, s, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left;
    return 0;
}