#include <bits/stdc++.h>
using namespace std;

unsigned arr[200005];
unsigned results[10005];

int main() {
    size_t t;
    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        size_t n;
        cin >> n;

        for (size_t j = 0; j < n; ++j) {
            cin >> arr[j];
        }

        unsigned* alice = arr, *bob = arr + n - 1;
        unsigned current = 0;
        int sum = 0;

        while (alice <= bob) {
            if (sum != 0) {
                if (sum < 0) {
                    sum += *alice;
                    ++alice;
                } else if (sum > 0) {
                    sum -= *bob;
                    --bob;
                }

                ++current;

                if (sum == 0 && current > results[i]) {
                    results[i] = current;
                }

                continue;
            }

            if (*alice <= *bob) {
                sum += *alice;
                ++alice;
            } else {
                sum -= *bob;
                --bob;
            }

            ++current;
        }
    }

    for (size_t i = 0; i < t; ++i) {
        cout << results[i] << endl;
    }

    return 0;
}