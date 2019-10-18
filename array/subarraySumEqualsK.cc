#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    // int subarraySum(vector<int>& nums, int k) {
    //     if (nums.empty())
    //     {
    //         return 0;
    //     }
    //     int res = 0;
    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         int sum = 0;
    //         for (int j = i; j < nums.size(); ++j)
    //         {
    //             sum += nums[j];
    //             if (sum == k)
    //             {
    //                 ++res;
    //             }
    //         }
    //     }
    //     return res;
    // }
    // prefix sum
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty())
        {
            return 0;
        }
        // the number and its no. of occurence
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0, sum = 0;
        for (int i : nums)
        {
            sum += i;
            // delivery
            res += m[sum-k];
            ++m[sum];
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    vector<int> nums{1,1,1};
    int k = 2;
    cout << s.subarraySum(nums, k);
}