#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 2000000
int arr[MAX_SIZE];

size_t parent(size_t i) {
    return i > 0 ? (i - 1) / 2 : 0;
}

size_t left_child(size_t i) {
    return i * 2 + 1;
}

size_t right_child(size_t i) {
    return i * 2 + 2;
}

void heapify(size_t i, size_t size) {
    size_t left = left_child(i), right = right_child(i);

    if (left >= size) {
        return;
    }

    size_t bigger = left;

    if (right < size && arr[right] > arr[left]) {
        bigger = right;
    }

    if (arr[i] < arr[bigger]) {
        swap(arr[i], arr[bigger]);
        heapify(bigger, size);
    }
}

void build_heap(size_t size) {
    for (long i = size / 2; i >= 0; --i) {
        heapify(i, size);
    }
}

int main() {
    size_t n;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    build_heap(n);
    size_t size = n;

    while (size > 1) {
        swap(arr[0], arr[--size]);
        heapify(0, size);
    }

    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
