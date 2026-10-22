#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int count = 0;

        for (const auto& [num, frequency] : freq) {
            if (k == 0) {
                if (frequency >= 2) count++;
            } else {
                if (freq.count(num + k)) count++;
            }
        }

        return count;
    }
};