#include <bits/stdc++.h>
using namespace std;

const size_t  MAX_SIZE = 2e6+5;
pair<unsigned, int> seg[MAX_SIZE];

int main() {
    size_t n;
    cin >> n;

    for (size_t i = 0; i < 2 * n; i += 2) {
        cin >> seg[i].first >> seg[i + 1].first;
        seg[i].second = -1;
        seg[i + 1].second = 1;
    }

    int sum = 0;
    size_t seg_start = 0;
    unsigned result = 0, max_seg = 0;

    sort(seg, seg + 2 * n + 1);
     
    for (size_t i = 0; i < 2 * n; ++i) {
        sum -= seg[i].second;

        if (sum == 0) {
            ++result;
            max_seg = max(max_seg, (unsigned)(seg[i].first - seg_start));
        } else if (sum == 1) {
            seg_start = seg[i].first;
        }
    }

    cout << result << " " << max_seg << endl;
    return 0;
}