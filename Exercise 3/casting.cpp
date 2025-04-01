#include <bits/stdc++.h>
using namespace std;

struct singer {
    unsigned start;
    unsigned duration;

    bool operator<(singer other) {
        return start < other.start || start == other.start && duration > other.duration;
    }
};

unsigned studios[1010];
singer singers[10010];

int main() {
    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i < m; ++i) {
        cin >> singers[i].start >> singers[i].duration;
    }

    sort(singers, singers + m);

    for (size_t i = 0; i < m; ++i) {
        size_t minStudio = 0;

        for (size_t j = 1; j < n; ++j) {
            if (studios[minStudio] <= singers[i].start) {
                break;
            }

            if (studios[j] < studios[minStudio]) {
                minStudio = j;
            }
        }

        studios[minStudio] = max(studios[minStudio], singers[i].start) + singers[i].duration;
    }

    size_t latestStudio = 0;

    for (size_t i = 1; i < n; ++i) {
        if (studios[i] >= studios[latestStudio]) {
            latestStudio = i;
        }
    }

    cout << studios[latestStudio] << " " << latestStudio + 1;
    return 0;
}



