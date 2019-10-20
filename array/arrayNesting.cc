#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int cur = 0;
            unordered_set<int> st;
            if (nums[i] != -1)
            {
                int j = i;
                while (nums[j] != -1 && st.find(nums[j]) == st.end())
                {
                    ++cur;
                    st.insert(nums[j]);
                    int tmp = nums[j];
                    nums[j] = -1;
                    j = tmp;
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    // [4,2,3,1,0]
    // 5,4,0,3,1,6,2
    vector<int> nums{4, 2, 3, 1, 0};

    cout << s.arrayNesting(nums);
}