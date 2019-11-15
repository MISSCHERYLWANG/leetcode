#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> profit0(n), profit1(n);
        profit0[0] = 0;
        profit1[0] = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            profit0[i] = max(profit0[i - 1], profit1[i - 1] + prices[i] - fee);
            profit1[i] = max(profit1[i - 1], profit0[i - 1] - prices[i]);
        }
        // for (int i = 0; i < n; ++i)
        // {
        //     cout << profit0[i] << " " << profit1[i] << endl;
        // }
        return profit0[n - 1];
    }
};
int main()
{
    Solution s = Solution();
    vector<int> p{1, 3, 2, 8, 4, 9};
    int f = 2;
    cout << s.maxProfit(p, f);
}