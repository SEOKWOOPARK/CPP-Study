#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int twoBack = 0;  // dp[i - 2]
        int oneBack = 0;  // dp[i - 1]
        int n = static_cast<int>(cost.size());

        for (int i = 2; i <= n; ++i) {
            int current = min(oneBack + cost[i - 1],
                              twoBack + cost[i - 2]);

            twoBack = oneBack;
            oneBack = current;
        }

        return oneBack;
    }
};