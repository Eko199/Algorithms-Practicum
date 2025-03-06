#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000

unsigned arr[MAX_SIZE];
unsigned print[20][MAX_SIZE];
size_t levels = 0;

void merge_sort(size_t start, size_t end, size_t level = 0) {
    if (level > levels) {
        levels = level;
    }

    if (start >= end - 1) {
        print[level][start] = arr[start];
        return;
    }

    size_t mid = (start + end) / 2 + (start + end) % 2;

    merge_sort(start, mid, level + 1);
    merge_sort(mid, end, level + 1);

    size_t i = start, j = mid, curr = start;

    while (i < mid && j < end) {
        print[level][curr++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    }

    for (; i < mid; ++i) {
        print[level][curr++] = arr[i];
    }

    for (; j < end; ++j) {
        print[level][curr++] = arr[j];
    }

    for (size_t k = start; k < end; ++k) {
        arr[k] = print[level][k];
    }
}

int main() {
    size_t n;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    merge_sort(0, n);

    for (size_t i = 0; i <= levels; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cout << print[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}


