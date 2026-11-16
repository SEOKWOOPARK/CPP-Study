#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        const unordered_map<char, int> values = {
            {'I', 1},   {'V', 5},   {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;

        for (size_t i = 0; i < s.size(); ++i) {
            int current = values.at(s[i]);

            if (i + 1 < s.size() && current < values.at(s[i + 1])) {
                result -= current;
            } else {
                result += current;
            }
        }

        return result;
    }
};