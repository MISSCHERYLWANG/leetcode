#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
/*      if (gas.empty())
        {
            return -1;
        }
        int i;
        for (i = 1; i <= gas.size(); ++i)
        {
            int left = gas[i-1];
            int j = i-1;
            int n = gas.size();
            while (n > 0)
            {
                if (left < cost[j])
                {
                    break;
                }
                left = left - cost[j] + gas[(j+1)%gas.size()];
                if (left < 0)
                {
                    break;
                }
                j = (j + 1) % gas.size();
                --n;
            }
            if (n == 0)
            {
                return i-1;
            }
        }
        return -1;
        */
        int start = 0, total = 0, sub = INT16_MAX;
        for (int i = 0; i < gas.size(); ++i)
        {
            total += (gas[i] - cost[i]);
            if (total < sub)
            {
                sub = total;
                start = i + 1;
            }
        }
        return total < 0 ? -1 : start;
    }
};
int main()
{
    Solution sol = Solution();

    vector<int> gas{1,2,3,4,5}, cost{3,4,5,1,2};

    cout << sol.canCompleteCircuit(gas, cost);

    return 0;
}