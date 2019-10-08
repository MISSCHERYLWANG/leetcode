#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0: dead->dead, 1: live->live, 2: live->dead, 3: dead->live
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<int> x_add{-1,-1,-1,0,0,1,1,1}, y_add{-1,0,1,-1,1,-1,0,1};

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                // eight neighbours
                int num = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int x = i + x_add[k], y = j + y_add[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2))
                    {
                        ++num;
                    }
                }
                if (board[i][j] && (num > 3 || num < 2))
                {
                    board[i][j] = 2;
                }
                else if (board[i][j] == 0 && num == 3)
                {
                    board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                board[i][j] %= 2;
            }
        }
        return;
    }
};

int main()
{
    Solution s = Solution();

    vector<vector<int>> board{
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };

    s.gameOfLife(board);

    for (auto nums : board)
    {
        for (int i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}