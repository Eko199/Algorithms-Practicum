#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000000

unsigned arr[MAX_SIZE];
unsigned helper[MAX_SIZE];

unsigned long inversion_count(size_t start, size_t end) {
    if (start >= end - 1) {
        return 0;
    }

    size_t mid = (start + end) / 2 + (start + end) % 2;
    unsigned long inversions = inversion_count(start, mid) + inversion_count(mid, end);

    size_t i = start, j = mid, curr = start;

    while (i < mid && j < end) {
        if (arr[i] <= arr[j]) {
            helper[curr++] = arr[i++];
        } else {
            helper[curr++] = arr[j++];
            inversions += mid - i;
        }
    }

    for (; i < mid; ++i) {
        helper[curr++] = arr[i];
    }

    for (; j < end; ++j) {
        helper[curr++] = arr[j];
    }

    for (size_t k = start; k < end; ++k) {
        arr[k] = helper[k];
    }

    return inversions;
}

int main() {
    size_t n;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << inversion_count(0, n);
    return 0;
}


