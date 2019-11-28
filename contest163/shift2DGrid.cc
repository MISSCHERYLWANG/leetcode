#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        if (k == 0)
        {
            return grid;
        }
        int m = grid.size(), n = grid[0].size();
        vector<int> temp;
        vector<vector<int>> res(m, vector<int>(n));
        for (auto vec : grid)
        {
            for (int i : vec)
            {
                temp.push_back(i);
            }
        }
        int i = 0, j = 0, sz = m * n, t;
        k %= sz;
        t = (m * n - k) % (m * n);
        while (sz)
        {
            if (j == n)
            {
                ++i;
                j = 0;
            }
            res[i][j] = temp[t];
            ++j;
            t = (t + 1) % (m * n);
            --sz;
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    vector<vector<int>> g{
        // {1, 2, 3},
        // {4, 5, 6},
        // {7, 8, 9}},
        {1},
        {2},
        {3},
        {4},
        {7},
        {6},
        {5}},
        ans;
    int k = 23;
    ans = s.shiftGrid(g, k);
    for (auto vec : ans)
    {
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}