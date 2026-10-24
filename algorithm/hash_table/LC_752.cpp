
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());

        if (visited.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();

                if (cur == target) return steps;

                for (int j = 0; j < 4; j++) {
                    for (int dir : {-1, 1}) {
                        string next = cur;
                        next[j] = (cur[j] - '0' + dir + 10) % 10 + '0';

                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
