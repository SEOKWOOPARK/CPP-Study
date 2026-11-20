#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (target < -sum || target > sum || (sum + target) % 2 != 0) {
            return 0;
        }

        int positiveSum = (sum + target) / 2;
        vector<int> dp(positiveSum + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int s = positiveSum; s >= num; --s) {
                dp[s] += dp[s - num];
            }
        }

        return dp[positiveSum];
    }
};