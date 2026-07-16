#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };

        int cnt = n;
        for (const auto& e : edges) {
            int px = find(e[0]), py = find(e[1]);
            if (px == py) continue;
            parent[px] = py;
            --cnt;
        }
        return cnt;
    }
};