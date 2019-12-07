#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    string convertToTitle(int n)
    {
        vector<char> dict{'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                          'U', 'V', 'W', 'X', 'Y'};
        string res = "";
        int q = n, r = n;
        while (q)
        {
            r = q % 26;
            q /= 26;
            if (!r)
            {
                q -= 1;
            }
            res = dict[r] + res;
        }

        return res;
    }
};
int main()
{
    Solution s = Solution();

    int n;
    cin >> n;
    cout << s.convertToTitle(n);
}