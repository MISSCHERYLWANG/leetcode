#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> temp(128, 0);
        int minLen = INT16_MAX, left = 0, minLeft = -1, cnt = 0;
        // 统计t字符串中出现的字符与个数
        for (int i = 0; i < t.length(); ++i)
        {
            ++temp[t[i]];
        }
        // 遍历s
        for (int i = 0; i < s.length(); ++i)
        {
            // 遇到t中出现的字符，先减1，
            // 如果统计表中的个数依然大于等于0
            if (--temp[s[i]] >= 0)
            {
                ++cnt;
            }
            // 循环计数器跟t的长度相等这种情况从而缩小左边界，一旦这种情况不成立就不再缩小
            // 先更新minLen，然后将左边界的字符加回统计表中，++left
            while (cnt == t.length())
            {
                if (minLen > i - left + 1)
                {
                    minLen = i - left + 1;
                    minLeft = left;
                }
                if (++temp[s[left]] > 0)
                {
                    --cnt;
                }
                ++left;
            }
        }
        return (minLeft == -1 ? "" : s.substr(minLeft, minLen));
    }
};
int main()
{
    Solution sol = Solution();
    string s, t;
    cin >> s >> t;
    cout << sol.minWindow(s, t);
}