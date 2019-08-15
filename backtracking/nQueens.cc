#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queen(n, string(n, '.'));
        dfs(res, queen, 0);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<string>& queen, int row) {
        int n = queen.size();
        if (row == n)
        {
            res.push_back(queen);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (check(queen, row, i))
            {
                queen[row][i] = 'Q';
                dfs(res, queen, row+1);
                queen[row][i] = '.';
            }
        }
    }
    bool check(vector<string> queen, int row, int col) {
        for (int i = 0; i < row; ++i)
        {
            if (queen[i][col] == 'Q')
            {
                return false;
            }
        }
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j)
        {
            if (queen[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = row-1, j = col+1; i >= 0 && j < queen.size(); --i, ++j)
        {
            if (queen[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol = Solution();
    int n;
    cin >> n;
    vector<vector<string>> ans;
    ans = sol.solveNQueens(n);
    for (auto strs: ans)
    {
        for (string s: strs)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}