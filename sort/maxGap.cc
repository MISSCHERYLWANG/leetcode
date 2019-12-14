#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.empty() || nums.size() < 2)
        {
            return 0;
        }
        int res = 0, mn = INT32_MAX, mx = INT32_MIN;
        // find the orange A-B
        for (int i : nums)
        {
            mx = max(i, mx);
            mn = min(i, mn);
        }
        int vol = (mx - mn) / nums.size() + 1, n = (mx - mn) / vol + 1;
        vector<int> min_bucket(n, INT32_MAX), max_bucket(n, INT32_MIN);
        for (int i : nums)
        {
            int index = (i - mn) / vol;
            min_bucket[index] = min(min_bucket[index], i);
            max_bucket[index] = max(max_bucket[index], i);
        }
        int pre = 0;
        for (int i = 1; i < n; ++i)
        {
            // empty buckets
            if (min_bucket[i] == INT32_MAX || max_bucket[i] == INT32_MIN)
            {
                continue;
            }

            res = max(min_bucket[i] - max_bucket[pre], res);
            pre = i;
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    //[15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,
    //20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740]
    vector<int> nums{15252, 16764, 27963, 7817, 26155, 20757, 3478, 22602, 20404, 6739, 16790, 10588, 16521, 6644, 20880, 15632, 27078, 25463,
                     20124, 15728, 30042, 16604, 17223, 4388, 23646, 32683, 23688, 12439, 30630, 3895, 7926, 22101, 32406, 21540, 31799, 3768, 26679, 21799, 23740};

    cout << s.maximumGap(nums);
}