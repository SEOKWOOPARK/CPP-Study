#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &num1, vector<int> &num2) {
        unordered_set<int> seen(num1.begin(), num1.end());
        vector<int> answer;

        for (int n: num2) {
            if (seen.count(n)) {
                answer.push_back(n);
                seen.erase(n);
            }
        }

        return answer;
    }
};