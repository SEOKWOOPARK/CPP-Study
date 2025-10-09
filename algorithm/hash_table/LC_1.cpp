#include <vector>
#include <unordered_map>

using namespace std;

// T - O(n)
// S - O(n)_
// Brute Force -> O(n ** 2) can lead to time exceed.
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (m.find(complement) != m.end()) {
                return {m[complement], i};
            }

            m[nums[i]] = i;
        }
        return {};
    }
};