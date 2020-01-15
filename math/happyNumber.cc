#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        int sum = getSum(n);
        int num = 0;
        while (num < 100) {
            if (sum == 1) {
                return true;
            }
            sum = getSum(sum);
            ++num;
        }
        return false;
    }
    int getSum(int n) {
        int res = 0;
        while (n) {
            int mod = n % 10;
            res += (mod * mod);
            n /= 10;
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    int n;
    cin >> n;
    cout << s.isHappy(n);
}