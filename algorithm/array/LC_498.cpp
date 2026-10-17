
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;
        ans.reserve(m * n);

        int r = 0, c = 0;
        int dir = 1;

        for (int i = 0; i < m * n; ++i) {
            ans.push_back(mat[r][c]);

            if (dir == 1) {  // Up-right
                if (c == n - 1) {
                    ++r;
                    dir = -1;
                } else if (r == 0) {
                    ++c;
                    dir = -1;
                } else {
                    --r;
                    ++c;
                }
            } else {  // Down-left
                if (r == m - 1) {
                    ++c;
                    dir = 1;
                } else if (c == 0) {
                    ++r;
                    dir = 1;
                } else {
                    ++r;
                    --c;
                }
            }
        }

        return ans;
    }
};
