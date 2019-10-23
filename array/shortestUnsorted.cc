#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int start = -1, end = -2, n = nums.size();
        int mn = nums[n - 1], mx = nums[0];
        for (int i = 1; i < n; ++i)
        {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n - 1 - i]);
            // 更新相当于将mx/mn移到它本来的位置
            if (mx > nums[i])
            {
                end = i;
            }
            if (mn < nums[n - 1 - i])
            {
                start = n - 1 - i;
            }
        }
        return end - start + 1;
    }
};
int main()
{
    Solution s = Solution();
    // 1,2,3,4
    // 2,1
    // 2, 6, 4, 8, 10, 9, 15
    // 1,3,2,2,2
    // 1,3,2,3,3
    // 2,3,3,2,4
    vector<int>
        nums1{2, 3, 3, 2, 4}, nums2{2, 1}, nums3{1, 2, 3, 4},
        nums4{1, 3, 2, 3, 2};

    cout << s.findUnsortedSubarray(nums1) << endl;
    cout << s.findUnsortedSubarray(nums2) << endl;
    cout << s.findUnsortedSubarray(nums3) << endl;
    cout << s.findUnsortedSubarray(nums4) << endl;
}