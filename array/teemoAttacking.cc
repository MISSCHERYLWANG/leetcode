#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty())
        {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < timeSeries.size() - 1; ++i)
        {
            res += min(duration, timeSeries[i+1] - timeSeries[i]);
        }
        res += duration;
        return res;
    }
};
int main()
{
    Solution s = Solution();

    vector<int> t{1, 2};
    int d = 2;

    cout << s.findPoisonedDuration(t, d);
}