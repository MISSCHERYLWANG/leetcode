#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
        {
            return true;
        }   
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (!isalnum(s[l]))
            {
                ++l;
            }
            else if (!isalnum(s[r]))
            {
                --r;
            }
            else if ((s[l] + 32 - 'a') % 32 != (s[r] + 32 - 'a')% 32)
            {
                return false;
            }
            else
            {
                ++l;
                --r;
            }
            
        }
        return true;
    }
    
};
int main()
{
    Solution sol = Solution();
    string s = "0P";
    
    cout << sol.isPalindrome(s);

    return 0;
}
