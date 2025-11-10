#include <vector>

using namespace std;

// T - O(1)
// T - O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = { false };
        bool cols[9][9] = { false };
        bool boxes[9][9] = { false };

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];

                if (ch == '.') {
                    continue;
                }

                int d = ch - '1';
                int box_index = (r / 3) * 3 + (c / 3);

                if (rows[r][d] || cols[c][d] || boxes[box_index][d]) {
                    return false;
                }

                rows[r][d] = true;
                cols[c][d] = true;
                boxes[box_index][d] = true;
            }
        }
        return true;
    }
};