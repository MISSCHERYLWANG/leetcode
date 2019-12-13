#include <iostream>

using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0, tmp = n;
        while (tmp / 5)
        {
            res += tmp / 5;
            tmp /= 5;
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    int n;
    cin >> n;
    cout << s.trailingZeroes(n);
}