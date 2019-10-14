#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, l = 0, r = 0;
        while (l < nums.size() && r <= nums.size())
        {
            if (nums[l] == 0)
            {
                ++l;
                ++r;
            }
            else
            {
                if (nums[r] == 1)
                {
                    ++r;
                }
                if (r == nums.size() || nums[r] == 0)
                {
                    res = max(res, r - l);
                    l = r;
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();

    vector<int> nums{1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(nums);
}