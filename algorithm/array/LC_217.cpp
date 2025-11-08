#include <vector>
#include <unordered_set>

using namespace std;

// Time Complexity: O(n) * O(1) ~= O(n)
// Space Complexity: O(n)
class Solution {
public:
    bool containDuplicate(vector<int>& nums) {
        unordered_set<int> visited;

        for (int n: nums) {
            if (visited.count(n)) {
                return true;
            }

            visited.insert(n);
        }
        return false;
    }

    bool contain(vector<int>& nums) {
        unordered_set<int> visited;

        for (int n: nums) {
            if (visited.count(n)) {
                return true;
            }

            if (visited.count(n)) {
                return true;
            }

            visited.insert(n);
        }

        return false;
    }
};