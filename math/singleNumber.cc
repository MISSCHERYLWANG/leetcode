#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i: nums)
        {
            ++count[i];
        }
        unordered_map<int, int>::iterator x;
        for (x = count.begin(); x != count.end(); ++x)
        {
            if (x->second == 1)
            {
                break;
            }
        }
        return x->first;
    }
};
int main()
{
    Solution sol = Solution();
    vector<int> nums{-1,-1,-2};

    cout << sol.singleNumber(nums);
    
    return 0;
}