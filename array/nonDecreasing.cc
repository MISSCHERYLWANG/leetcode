#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2)
        {
            return true;
        }
        bool flag = true;
        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] > nums[i+1])
            {
                if (nums[i+1] > nums[i+2] || flag == false)
                {
                    return false;
                }
                if (nums[i+2] > nums[i])
                {
                    nums[i+1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i+1];
                }
                flag = false;
            }
            if (nums[i] <= nums[i+1] && nums[i+1] > nums[i+2])
            {
                if (flag == false)
                {
                    return false;
                }
                if (nums[i] > nums[i+2])
                {
                    nums[i+2] = nums[i+1];
                }
                else
                {
                    nums[i+1] = nums[i+2];
                }
                
                flag = false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s = Solution();
    // [3,4,2,3] 0
    // [-1,4,2,3] 1
    //[1,5,4,6,7,10,8,9] 0
    // [3,2,3,2,4] 0
    vector<int> nums1{-1,4,2,3}, 
                nums2{3,4,2,3},
                nums3{4,2,3},
                nums4{4,2,1},
                nums5{1,5,4,6,7,10,8,9},
                nums6{3,2,3,2,4};

    cout << s.checkPossibility(nums1) << endl
            << s.checkPossibility(nums2) << endl
            << s.checkPossibility(nums3) << endl
            << s.checkPossibility(nums4) << endl
            << s.checkPossibility(nums5) << endl
            << s.checkPossibility(nums6) << endl;
}