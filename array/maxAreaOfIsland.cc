#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    res = max(res, area(grid, visited, i, j));
                }
            }
        }
        return res;
    }
    int area(vector<vector<int>> &grid, vector<vector<int>> &visited, int r, int c)
    {
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] && !visited[r][c])
        {
            visited[r][c] = 1;
            return (1 + area(grid, visited, r - 1, c) + area(grid, visited, r + 1, c) + area(grid, visited, r, c - 1) + area(grid, visited, r, c + 1));
        }
        return 0;
    }
};
int main()
{
    Solution s = Solution();
    // [[0,0,1,0,0,0,0,1,0,0,0,0,0],
    // [0,0,0,0,0,0,0,1,1,1,0,0,0],
    // [0,1,1,0,1,0,0,0,0,0,0,0,0],
    // [0,1,0,0,1,1,0,0,1,0,1,0,0],
    // [0,1,0,0,1,1,0,0,1,1,1,0,0],
    // [0,0,0,0,0,0,0,0,0,0,1,0,0],
    // [0,0,0,0,0,0,0,1,1,1,0,0,0],
    // [0,0,0,0,0,0,0,1,1,0,0,0,0]]
    vector<vector<int>> grid{
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << s.maxAreaOfIsland(grid);
}