#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        // if visited, nums = 0
        for (int i = 0; i < nums.size(); ++i)
        {
            // has been visited
            if (nums[i] == 0)
            {
                continue;
            }
            
            // record the slow and fast pointer, j, k
            int j = i, k = getNext(nums, i);
            // the same symbol as nums[i]
            while (nums[k] * nums[i] > 0 && nums[getNext(nums, k)] * nums[i] > 0)
            {
                if (j == k)
                {
                    // the length of the loop is 1
                    if (j == getNext(nums, j))
                    {
                        break;
                    }
                    return true;
                }
                j = getNext(nums, j);
                k = getNext(nums, getNext(nums, k));
            }
            // set all the nums visited 0
            j = i;
            while (nums[i] * nums[j] > 0)
            {
                nums[j] = 0;
                j = getNext(nums, j);
            }
        }
        return false;
    }
    // get index of the next
    int getNext(vector<int>& nums, int cur) {
        int n = nums.size();
        return (n + (cur + nums[cur]) % n) % n;
    }
};
int main()
{
    Solution s = Solution();
    // 2,-1,1,2,2
    // -1,2
    // -2,1,-1,-2,-2
    // 3,1,2
    // [2,2,2,2,2,4,7]
    vector<int> nums{2,2,2,2,2,4,7};
    cout << s.circularArrayLoop(nums);
}