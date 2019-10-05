#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 先加再减
        // 位运算

        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            res ^= i ^ nums[i];
        }

        return res;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> nums = {3,0,1};

    cout << sol.missingNumber(nums);
}