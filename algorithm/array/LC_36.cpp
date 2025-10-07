#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char ch = board[row][col];

                if (ch == '.') {
                    continue;
                }

                int box_index = (row / 3) * 3 + (col / 3);

                if (rows[row].count(ch) || cols[col].count(ch) || boxes[box_index].count(ch)) {
                    return false;
                }

                rows[row].insert(ch);
                cols[col].insert(ch);
                boxes[box_index].insert(ch);
            }
        }

        return true;
    }
};