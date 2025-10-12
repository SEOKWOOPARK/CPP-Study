#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> dic;

        for (char s: stones) {
            dic[s]++;
        }

        int answer = 0;

        for (char j: jewels) {
            answer += dic[j];
        }

        return answer;
    }
};
