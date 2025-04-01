#include <bits/stdc++.h>
using namespace std;

const size_t MAX_SIZE = 3e5+5;
pair<int, int> arr[MAX_SIZE];
unordered_map<int, int> point_index;
unsigned result[100001];

int main() {
    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i < 2 * n; i += 2) {
        cin >> arr[i].first >> arr[i + 1].first;
        arr[i].second = -1;
        arr[i + 1].second = 1;
    }

    for (size_t i = 0; i < m; ++i) {
        cin >> arr[2 * n + i].first;
        arr[2 * n + i].second = 0;
        point_index[arr[2 * n + i].first] = i;
    }

    int sum = 0;
    sort(arr, arr + 2 * n + m + 1);
     
    for (size_t i = 0; i < 2 * n; ++i) {
        sum -= arr[i].second;

        if (arr[i].second == 0) {
            result[point_index[arr[i].first]] = sum;
        }
    }

    for (size_t i = 0; i < m; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}