#include <string>
#include <vector>

using namespace std;

class Solution {
    int decode(const string& s, int i, vector<int>& memo) {
        if (i == static_cast<int>(s.size())) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }

        int ways = decode(s, i + 1, memo);

        if (i + 1 < static_cast<int>(s.size())) {
            int twoDigits = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (twoDigits >= 10 && twoDigits <= 26) {
                ways += decode(s, i + 2, memo);
            }
        }

        memo[i] = ways;
        return ways;
    }

public:
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return decode(s, 0, memo);
    }
};