
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxLeft = nums[0];
        long long maxDiff = 0;
        long long ans = 0;

        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, maxDiff * nums[i]);

            maxDiff = max(maxDiff, maxLeft - nums[i]);

            maxLeft = max(maxLeft, (long long)nums[i]);
        }

        return ans;
    }
};
