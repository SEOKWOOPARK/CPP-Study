
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_to_t[256] = {0};
        int t_to_s[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            unsigned char a = s[i];
            unsigned char b = t[i];

            if (s_to_t[a] != t_to_s[b])
                return false;

            s_to_t[a] = i + 1;
            t_to_s[b] = i + 1;
        }

        return true;
    }
};
