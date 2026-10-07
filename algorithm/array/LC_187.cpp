#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;

        for (int i = 0; i + 10 <= s.size(); ++i) {
            string dna = s.substr(i, 10);

            if (seen.count(dna))
                repeated.insert(dna);
            else
                seen.insert(dna);
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};