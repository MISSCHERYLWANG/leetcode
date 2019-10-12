#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        /*
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
            {
                res.push_back(i + 1);
            }
        }
        */
        for (int i = 0; i < nums.size(); ++i)
        {
            int idx = abs(nums[i]) - 1;
            nums[idx] = nums[idx] < 0 ? nums[idx] : -nums[idx];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();

    vector<int> nums{4,3,2,7,8,2,3,1}, res;
    res = s.findDisappearedNumbers(nums);

    for (int i : res)
    {
        cout << i << " ";
    }
}