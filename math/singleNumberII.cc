#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (int i: nums)
        {
            two |= (one & i);
            one ^= i;
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};
int main()
{
    Solution sol = Solution();

    vector<int> nums{};

    cout << sol.singleNumber(nums);

    return 0;
}