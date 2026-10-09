#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> first(2 * n + 1, -2);

        int sum = 0, ans = 0;
        first[n] = -1;

        for (int i = 0; i < n; ++i) {
            sum += (nums[i] == 1) ? 1 : -1;

            int idx = sum + n;

            if (first[idx] != -2) {
                ans = max(ans, i - first[idx]);
            } else {
                first[idx] = i;
            }
        }

        return ans;
    }
};
