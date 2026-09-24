#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (int num : nums) {
            frequency[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& [num, count] : frequency) {
            buckets[count].push_back(num);
        }

        vector<int> result;
        result.reserve(k);

        for (int count = nums.size(); count >= 1 && result.size() < k; --count) {
            for (int num : buckets[count]) {
                result.push_back(num);

                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};