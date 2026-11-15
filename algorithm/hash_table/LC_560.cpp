#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int sum = 0;
        int answer = 0;

        for (int num : nums) {
            sum += num;

            auto it = prefixCount.find(sum - k);
            if (it != prefixCount.end()) {
                answer += it->second;
            }

            ++prefixCount[sum];
        }

        return answer;
    }
};