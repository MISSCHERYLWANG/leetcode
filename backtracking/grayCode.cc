#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
        {
            return {0};
        }
        vector<int> res;
        // binary to gray
        for (int i = 0; i < (2 << n); ++i)
        {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};
int main()
{
    Solution sol = Solution();
    int n;
    cin >> n;
    vector<int> ans = sol.grayCode(n);
    for (int a: ans)
    {
        cout << a << " ";
    }
    return 0;
}