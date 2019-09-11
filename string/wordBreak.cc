#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> unset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1);
        dp[0] = true;

        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && unset.count(s.substr(j, i-j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        for (int i = 0; i <= s.size(); ++i)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
        return dp[s.size()];
    }
};

int main()
{
    Solution sol = Solution();

    string s;
    vector<string> dict{"cats", "dog", "sand", "and", "cat"};
    cin >> s;

    cout << sol.wordBreak(s, dict);

    return 0;
}