#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 2000010
int arr[MAX_SIZE];
mt19937 rnd(4325324);

void quicksort(size_t l, size_t r) {
    if (r == 0 || l >= r - 1) {
        return;
    }

    int pivot = arr[l + rand() % (r - l)];

    vector<int> partitioned;

    for (size_t i = l; i < r; ++i) {
        if (arr[i] < pivot) {
            partitioned.push_back(arr[i]);
        }
    }

    size_t end_small = l + partitioned.size();

    for (size_t i = l; i < r; ++i) {
        if (arr[i] == pivot) {
            partitioned.push_back(arr[i]);
        }
    }

    size_t start_big = l + partitioned.size();

    for (size_t i = l; i < r; ++i) {
        if (arr[i] > pivot) {
            partitioned.push_back(arr[i]);
        }
    }

    for (size_t i = l; i < r; ++i) {
        arr[i] = partitioned[i - l];
    }

    quicksort(l, end_small);
    quicksort(start_big, r);
}

int main() {
    size_t n;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    quicksort(0, n);

    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}

