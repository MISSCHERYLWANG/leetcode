#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        string res, word = "";
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] != ' ')
            {
                word = s[i] + word;
            }
            else 
            {
                if (i > 0 && s[i] == ' ' && s[i - 1] != ' ' && !word.empty())
                {
                    res += word + " ";
                    word = "";
                }
            }
        }
        res += word;
        return res;
    }
};
int main()
{
    Solution s = Solution();
    string str;
    cin >> str;
    cout << s.reverseWords(str);
}