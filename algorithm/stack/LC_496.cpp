#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> & nums1, vector<int> & nums2) {
        vector<int> result;
        result.reserve(nums1.size());
        vector<int> stack;
        unordered_map<int, int> dic;

        for (int i = static_cast<int>(nums2.size()) - 1; i >= 0; --i) {
            int x = nums2[i];

            while (!stack.empty() && stack.back() <= x) stack.pop_back();

            if (!stack.empty()) dic[x] = stack.back();

            stack.push_back(x);
        }

        for (int n : nums1) {
            auto it = dic.find(n);
            result.push_back(it != dic.end() ? it->second : -1);
        }

        return result;
    }
};