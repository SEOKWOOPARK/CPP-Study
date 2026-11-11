#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;

        int remainder = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            remainder = (remainder + static_cast<long long>(nums[i])) % k;

            auto [it, inserted] = firstIndex.emplace(remainder, i);
            if (!inserted && i - it->second >= 2) {
                return true;
            }
        }

        return false;
    }
};