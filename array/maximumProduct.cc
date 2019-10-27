#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // get the max three numbers and the min two numbers
        int max1 = INT32_MIN, max2 = INT32_MIN, max3 = INT32_MIN,
            min1 = INT32_MAX, min2 = INT32_MAX;
        for (int n : nums)
        {
            if (n > max3)
            {
                max1 = max2;
                max2 = max3;
                max3 = n;
            }
            else if (n > max2)
            {
                max1 = max2;
                max2 = n;
            }
            else if (n > max1)
            {
                max1 = n;
            }
            if (n < min1)
            {
                min2 = min1;
                min1 = n;
            }
            else if (n < min2)
            {
                min2 = n;
            }
        }
        return max3*max(max1*max2, min1*min2);
        // sort(nums.begin(), nums.end());
        // if (nums[n-1] > 0)
        // {
        //     if (nums[0]*nums[1] > nums[n-3]*nums[n-2])
        //     {
        //         return nums[0]*nums[1]*nums[n-1];
        //     }
        // }
        // return nums[n-3]*nums[n-2]*nums[n-1];
    }
};
int main()
{
    Solution s= Solution();
    // [-4,-3,-2,-1,60]
    vector<int> nums1{1,2,3,4},
                nums2{-4,-3,-2,-1,60};

    cout << s.maximumProduct(nums1)<<endl;
    cout << s.maximumProduct(nums2)<<endl;
}