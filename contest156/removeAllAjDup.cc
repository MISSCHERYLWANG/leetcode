#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int inx = checkifKDuplicates(s, k);
        while (inx >= 0)
        {
            if (inx == 0)
            {
                s = s.substr(inx + k);
            }
            else
            {
                s = s.substr(0, inx) + s.substr(inx + k);
            }
            inx = checkifKDuplicates(s, k);
        }
        return s;
    }
    int checkifKDuplicates(string s, int k) {
        if (s.size() < k)
        {
            return -1;
        }
        for (int i = 0; i <= s.size() - k; ++i)
        {
            int j;
            for (j = i + 1; j < i + k; ++j)
            {
                if (s[i] != s[j])
                {
                    break;
                }
            }
            if (j == i + k)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol = Solution();

    string s("deeedbbcccbdaa");
    int k = 3;
    // string s("pbbcggttciiippooaais");
    // int k = 2;

    cout << sol.removeDuplicates(s, k);
}
