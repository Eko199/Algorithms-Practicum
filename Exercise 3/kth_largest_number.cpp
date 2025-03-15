#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unsigned counter[20001] = {};

        for (int num : nums) {
            ++counter[num >= 0 ? num : num + 20001];
        }

        int current = 10000;

        while (current >= 0 && counter[current] < k) {
            k -= counter[current];
            --current;
        }

        if (current >= 0) {
            return current;
        }

        current = 20000;

        while (current > 10000 && counter[current] < k) {
            k -= counter[current];
            --current;
        }

        return current - 20001;
    }
};