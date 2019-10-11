#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT64_MIN;
        for (int i : nums)
        {
            if (i > mx1)
            {
                mx1 = i;
            }
        }
        for (int i : nums)
        {
            if (i > mx2 && i < mx1)
            {
                mx2 = i;
            }
        }
        for (int i : nums)
        {
            if (i > mx3 && i < mx2)
            {
                mx3 = i;
            }
        }
        return mx3 == INT64_MIN ? mx1 : mx3;
    }
};
int main()
{
    Solution s = Solution();
    vector<int> nums{-2147483648, 1, 2};

    cout << s.thirdMax(nums);
}