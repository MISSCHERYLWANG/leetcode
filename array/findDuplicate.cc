#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
            {
                break;
            }
        }
        slow = 0;
        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> nums{1,3,4,2,2};

    cout << sol.findDuplicate(nums);

}