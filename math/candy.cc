#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
/** two pass
    int candy(vector<int>& ratings) {
        if (ratings.empty())
        {
            return 0;
        }
        int res = 0;
        vector<int> candy(ratings.size(), 1);
        candy[0] = 1;

        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i-1])
            {
                candy[i] = candy[i-1] + 1;
            }
        }
        
        for (int i = ratings.size() - 1; i > 0; --i)
        {
            if (ratings[i-1] > ratings[i])
            {
                candy[i-1] = max(candy[i-1], candy[i] + 1);
            }
        }

        for (int num: candy)
        {
            res += num;
        }
        return res;
    }
**/
// one pass
    int candy(vector<int>& ratings) {
        int res = 1, prev = 1, count = 0;
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] >= ratings[i-1])
            {
                if (count > 0)
                {
                    res += (1+count) * count / 2;
                    if (count >= prev)
                    {
                        res += (count - prev + 1);
                    }
                    count = 0;
                    prev = 1;
                }
                prev = (ratings[i] == ratings[i-1]) ? 1 : prev+1;
                res += prev;
            }
            else
            {
                ++count;
            }  
        }
        if (count > 0)
        {
            res += (1+count) * count / 2;
            if (count >= prev)
            {
                res += (count - prev + 1);
            }
        }
        return res;
    }
};
int main()
{
    Solution sol = Solution();
    vector<int> ratings{1,3,2,2,1};

    cout << sol.candy(ratings);

    return 0;
}