#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0, i = 0, j = 0;
        while (j < s.size())
        {
            maxCost -= abs(s[j] - t[j]);
            ++j;
            if (maxCost < 0)
            {
                maxCost += (abs(s[i] - t[i]));
                ++i;
            }
            res = max(res, j - i);
        }
        return res;
    }
};

int main()
{
    Solution sol = Solution();

    string s("abcd"), t("bcdf");
    int mx = 3;
    // string s("krpgjbjjznpzdfy"), t("nxargkbydxmsgby");
    // int mx = 14;

    cout << sol.equalSubstring(s, t, mx);
}