#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    int titleToNumber(string s)
    {
        int res = 0, n = s.length() - 1;
        for (char c : s)
        {
            int t = 1, count = n;
            while (count)
            {
                t *= 26;
                --count;
            }
            res += ((c - 'A' + 1) * t);
            --n;
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    string str;
    cin >> str;
    cout << s.titleToNumber(str);
}