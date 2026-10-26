#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> banned(forbidden.begin(), forbidden.end());
        int left = 0, answer = 0;
        int n = word.size();

        for (int right = 0; right < n; ++right) {
            for (int start = right; start >= max(left, right - 9); --start) {
                if (banned.count(word.substr(start, right - start + 1))) {
                    left = start + 1;
                    break;
                }
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};