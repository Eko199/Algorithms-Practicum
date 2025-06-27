#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        unsigned dp[10010];
        dp[0] = 0;

        for (size_t i = 1; i < nums.size(); ++i) {
            dp[i] = INT_MAX;

            for (size_t j = 1; j <= i; ++j) {
                if (nums[i - j] >= j) {
                    dp[i] = min(dp[i], 1 + dp[i - j]);
                }
            }
        }

        return dp[nums.size() - 1];
    }
};