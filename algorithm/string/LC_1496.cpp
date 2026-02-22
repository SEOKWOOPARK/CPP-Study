#include <string>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        // Time - O(n log n)
        // Space - O(n) due to a variance 'visited'

        set<pair<int, int>> visited;

        int x = 0, y = 0;
        visited.insert({0, 0});

        for (char direction : path) {
            if (direction == 'N') {
                y += 1;
            } else if (direction == 'S') {
                y -= 1;
            } else if (direction == 'W') {
                x -= 1;
            } else if (direction == 'E') {
                x += 1;
            }

            if (visited.find({x, y}) != visited.end()) {
                return true;
            }

            visited.insert({x, y});
        }

        return false;
    }
};