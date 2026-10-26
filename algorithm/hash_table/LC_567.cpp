#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> target(26, 0), window(26, 0);

        for (int i = 0; i < n; ++i) {
            ++target[s1[i] - 'a'];
            ++window[s2[i] - 'a'];
        }

        if (target == window) return true;

        for (int i = n; i < m; ++i) {
            ++window[s2[i] - 'a'];
            --window[s2[i - n] - 'a'];

            if (target == window) return true;
        }

        return false;
    }
};