#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i+=2)
        {
            res += min(nums[i], nums[i+1]);
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    vector<int> nums{};

    cout << s.arrayPairSum(nums);
}