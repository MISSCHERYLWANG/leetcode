#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int res = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0 || nums[i] > nums[i-1])
            {
                ++count;
                // 如果这句放在else中会判断不出连续递增到结尾的数组
                res = max(res, count);
            }
            else
            {   
                count = 1;
            }
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    vector<int> nums1{1,3,5,4,7,8,9}, 
    nums2{2,2,2,2,2};

    cout << s.findLengthOfLCIS(nums1) << " "
        << s.findLengthOfLCIS(nums2);
}