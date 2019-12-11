#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        vector<int> dp(3);
        for (int i : nums)
        {
            vector<int> temp(dp);
            for (int t : temp)
            {
                dp[(t + i) % 3] = max(dp[(t + i) % 3], t + i);
            }
        }
        return dp[0];
    }
};
int main()
{
    Solution s = Solution();
    vector<int> nums{3, 6, 5, 1, 8};

    cout << s.maxSumDivThree(nums);
}