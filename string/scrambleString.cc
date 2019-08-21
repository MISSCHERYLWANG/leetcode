#include<iostream>
#include<string>
#include<algorithm>
#include<Vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
        {
            return false;
        }
        if (s1 == s2)
        {
            return true;
        }
        string temp1 = s1, temp2 = s2;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if (temp1 != temp2)
        {
            return false;
        }
        // recursive
        for (int i = 1; i < s1.size(); ++i)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s1.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s1.size()-i)))
            {
                return true;
            }
        }
        return false;
        // dp
/**     int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n, false)));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j][1] = true;
                }
            }
        }
**/
    }
};

int main()
{
    Solution sol = Solution();
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << sol.isScramble(s1, s2);
    return 0;
}