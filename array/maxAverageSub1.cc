#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double res = 0, sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum += nums[i];
        }
        for (int i = k; i < n; ++i)
        {
            sum += (nums[i] - nums[i-k]);
            res = max(sum, res);
        }
        return (res/k);
    }
};
int main()
{
    Solution s = Solution();
    vector<int> nums{1,12,-5,-6,50,3};
    int k = 4;

    cout << s.findMaxAverage(nums, k) << endl;
}