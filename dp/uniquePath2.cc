#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
        {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n));
        dp[0][0] = (obstacleGrid[0][0] == 1 ? 0 : 1);
        for (int i = 1; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 0)
            {
                dp[i][0] = dp[i-1][0];
            }
        }
        for (int i = 1; i < n; ++i)
        {
            if (obstacleGrid[0][i] == 0)
            {
                dp[0][i] = dp[0][i-1];
            }
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution s = Solution();

    vector<vector<int>> grid{
        {0,0}};
    cout << s.uniquePathsWithObstacles(grid);

    return 0;
}