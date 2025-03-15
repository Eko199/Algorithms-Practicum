#include <bits/stdc++.h>
using namespace std;

unsigned arr[1000];

int main() {
    size_t n;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = i; j > 0; --j) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }

        for (size_t j = 0; j < n; ++j) {
            cout << arr[j] << " ";
        }

        cout << endl;
    }

    return 0;
}
