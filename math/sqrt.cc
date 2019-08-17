#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
/**
        long ans = 0;
        // 最一般的解法
        while (1)
        {
            long left = ans * ans;
            long right = (ans+1) * (ans+1);
            if (x >= left && x < right)
            {
                return ans;
            }
            ++ans;
        }
        // 二分查找
        long left = 0;
        long right = x;
        while (left < right)
        {
            long mid = (left + right) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid > x)
            {
                right = mid - 1;
            }
            else 
            {
                left = mid + 1;
            }
        }
        return right*right>x ? right - 1 : right;
        // 牛顿迭代法
        long res = x;
        while (res * res > x)
        {
            res = (res + x / res) / 2;
        }
        return res;
**/
        // pre没有必要
        double res = 1.0, pre = 0;
        while (abs(res - pre) > 1e-6)
        {
            pre = res;
            res = (pre + x / pre) / 2;
        }
        return res;
    }
};
int main()
{
    Solution sol = Solution();
    int x;
    cin >> x;
    cout << sol.mySqrt(x);
    return 0;
}