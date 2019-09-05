#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (!row)
        {
            return;
        }
        int col = board[0].size();
        for (int i = 0; i < row; ++i)
        {
            dfs(board, i, 0);
            if (col > 1)
            {
                dfs(board, i, col-1);
            }
        }
        for (int j = 1; j < col-1; ++j)
        {
            dfs(board, 0, j);
            if (row > 1)
            {
                dfs(board, row-1, j);
            }
        }
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'P')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O')
        {
            board[i][j] = 'P';
            if (i > 0 && board[i-1][j] == 'O')
            {
                dfs(board, i-1, j);
            }
            if (i < board.size() - 1 && board[i+1][j] == 'O')
            {
                dfs(board, i+1, j);
            }
            if (j > 0 && board[i][j-1] == 'O')
            {
                dfs(board, i, j-1);
            }
            if (j < board[0].size() - 1 && board[i][j+1] == 'O')
            {
                dfs(board, i, j+1);
            }
        }
        
    }
};
int main()
{
    Solution sol = Solution();

    vector<vector<char>> board{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    sol.solve(board);
    for (auto row: board)
    {
        for (char c: row)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}