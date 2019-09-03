#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int buy1 = INT16_MIN, buy2 = INT16_MIN, sell1 = 0, sell2 = 0;
        for (int i: prices)
        {
            sell2 = max(sell2, buy2 + i);
            buy2 = max(buy2, sell1 - i);
            sell1 = max(sell1, buy1 + i);
            buy1 = max(buy1, -i);
        }
        return sell2;
    }
};
int main()
{
    Solution sol = Solution();
    vector<int> prices{3,3,5,0,0,3,1,4};
    cout << sol.maxProfit(prices);
    return 0;
}
