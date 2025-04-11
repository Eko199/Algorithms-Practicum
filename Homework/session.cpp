#include<bits/stdc++.h>
using namespace std;

long lectures[300005];
long alone[300005];

bool check(long long x, size_t n, long long m) {
    long long hours = 0;

    for (size_t i = 0; i < n; ++i) {
        if (lectures[i] > alone[i]) {
            long long attendance = (x + lectures[i] - 1) / lectures[i];

            if (m < attendance) {
                attendance = m;
            }

            long long studied = attendance * lectures[i];
            hours += attendance + (x < studied ? 0 : (x - studied + alone[i] - 1) / alone[i]);
        } else {
            hours += (x + alone[i] - 1) / alone[i];
        }

        if (hours > n * m) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    long long m;
    long max_amount = 0;

    cin >> n >> m;
    
    for (size_t i = 0; i < n; ++i) {
        cin >> lectures[i];

        if (lectures[i] > max_amount) {
            max_amount = lectures[i];
        }
    }
    
    for (size_t i = 0; i < n; ++i) {
        cin >> alone[i];

        if (alone[i] > max_amount) {
            max_amount = alone[i];
        }
    }
    
    long long l = m, r = m * max_amount + 10, mid;

    while (l < r) {
        mid = (l + r + 1) / 2;

        if (check(mid, n, m)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l;
    return 0;
}