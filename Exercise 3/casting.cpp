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

    sort(studios, studios + n);
    sort(singers, singers + m);

    for (size_t i = 0; i < m; ++i) {
        cout << singers[i].start << " " << singers[i].duration << endl;
    }

    return 0;
}



