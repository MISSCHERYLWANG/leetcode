#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.empty())
        {
            return 0;
        }
        vector<int> dp(s.size());
        vector<vector<bool>> p(s.size(), vector<bool>(s.size()));
        for (int i = 0; i < s.size(); ++i)
        {
            dp[i] = i;
            for (int j = 0; j <= i; ++j)
            {
                if (s[i] == s[j] && (i-j < 2 || p[i-1][j+1]))
                {
                    p[i][j] = true;
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1]+1);
                }
            }
        }
        return dp[s.size()-1];
    }
    
};

int main()
{
    Solution sol = Solution();
    string s;

    cin >> s;

    cout << sol.minCut(s);

}