#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
// moore voting
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;

        for (int n: nums)
        {
            if (n == num1)
            {
                ++cnt1;
            }
            else if (n == num2)
            {
                ++cnt2;
            }
            else if (cnt1 == 0)
            {
                num1 = n;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                num2 = n;
                cnt2 = 1;
            }
            else
            {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int n : nums)
        {
            if (num1 == n)
            {
                ++cnt1;
            }
            else if (num2 == n)
            {
                ++cnt2;
            }
        }
        if (cnt1 > nums.size() / 3)
        {
            res.push_back(num1);
        }
        if (cnt2 > nums.size() / 3)
        {
            res.push_back(num2);
        }
        return res;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> nums{3,2,3};
    
    vector<int> ans = sol.majorityElement(nums);
    for (int n: ans)
    {
        cout << n << " ";
    }
}
