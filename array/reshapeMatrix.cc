#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int row = nums.size(), col = nums[0].size();
        if (row * col != r * c)
        {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c));
        int m = 0, n = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (m == r)
                {
                    return res;
                }
                if (n == c)
                {
                    ++m;
                    n = 0;
                }
                res[m][n] = nums[i][j];
                ++n;
            }
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    vector<vector<int>> nums{
        {1, 2},
        {3, 4}},
        res;

    int r = 4, c = 1;

    res = s.matrixReshape(nums, r, c);
    for (auto v : res)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}