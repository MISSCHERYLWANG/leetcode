#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> queenCol(n, -1);
        nQueens(0, queenCol, ans);
        return ans;
    }
    void nQueens(int row, vector<int>& queenCol, int& res) {
        int n = queenCol.size();
        if (row == n)
        {
            ++res;
            
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (isValid(queenCol, row, i))
            {
                queenCol[row] = i;
                
                nQueens(row+1, queenCol, res);
                
                queenCol[row] = -1;
            }
        }
    }
    bool isValid(vector<int>& queenCol, int row, int col) {
        for (int i = 0; i < row; ++i)
        {
            if (queenCol[i] == col || abs(queenCol[i]-col) == abs(i-row))
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
    cout << sol.totalNQueens(n);
    return 0;
}