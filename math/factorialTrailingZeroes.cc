#include <iostream>

using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        long long facto = 1, res = 0;
        for (int i = 1; i <= n; ++i)
        {
            facto *= i;
            while (facto % 10 == 0)
            {
                ++res;
                facto /= 10;
            }
            facto %= 10;
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