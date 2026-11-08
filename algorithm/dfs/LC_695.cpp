#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= static_cast<int>(grid.size()) ||
            col < 0 || col >= static_cast<int>(grid[0].size()) ||
            grid[row][col] == 0) {
            return 0;
            }

        grid[row][col] = 0;

        int area = 1;

        area += dfs(grid, row - 1, col);
        area += dfs(grid, row + 1, col);
        area += dfs(grid, row, col - 1);
        area += dfs(grid, row, col + 1);

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int rows = static_cast<int>(grid.size());
        const int cols = static_cast<int>(grid[0].size());
        int maxArea = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    maxArea = max(maxArea, dfs(grid, row, col));
                }
            }
        }

        return maxArea;
    }
};