#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                ++j;
            }
        }
        for (int k = j; k < nums.size(); ++k)
        {
            nums[k] = 0;
        }
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> nums{0,1,0,3,12};

    sol.moveZeroes(nums);

    for (int i : nums)
    {
        cout << i << " ";
    }
}