#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        int m = M.size(), n = M[0].size();
        vector < vector<int>> res(m, vector<int>(n));
        vector<int> x_add = {-1, -1, -1, 0, 0, 0, 1, 1, 1},
                    y_add = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int count = 0, sum = 0;
                for (int k = 0; k < 9; ++k)
                {
                    int x = i + x_add[k], y = j + y_add[k];
                    if (x >= 0 && x < m && y >= 0 && y < n)
                    {
                        sum += M[x][y];
                        ++count;
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    vector<vector<int>> m{
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}},
        res;
    res = s.imageSmoother(m);

    for (auto r : res)
    {
        for (int i : r)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}