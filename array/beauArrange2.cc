#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    // construction method
    vector<int> constructArray(int n, int k)
    {
        vector<int> res(n);
        for (int i = 1; i < n - k; ++i)
        {
            res[i - 1] = i;
        }
        for (int i = 1; i <= k + 1; ++i)
        {
            res[n - k + i - 2] = (i % 2 == 0 ? (n - i / 2 + 1) : (n - k + i / 2));
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    int n, k;
    cin >> n >> k;
    vector<int> res = s.constructArray(n, k);

    for (int n : res)
    {
        cout << n << " ";
    }
}