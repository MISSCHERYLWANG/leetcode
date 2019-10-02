#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res{};
        vector<int> cur{};

        dfs(res, cur, 1, n, k);

        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& cur, int start, int n, int k) {
        if (n < 0)
        {
            return;
        }
        if (n == 0 && cur.size() == k)
        {
            res.push_back(cur);
        }
        for (int i = start; i <= 9; ++i)
        {
            cur.push_back(i);
            dfs(res, cur, i + 1, n - i, k);
            cur.pop_back();
        }
    }
};

int main()
{
    Solution sol = Solution();

    int k = 3, n = 7;
    vector<vector<int>> res = sol.combinationSum3(k, n);

    for (auto cur: res)
    {
        for (int num: cur)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}