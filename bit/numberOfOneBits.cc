#include<iostream>

using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        uint32_t tmp = 1;
        for (int i = 0; i < 32; ++i)
        {
            res += ((n & (tmp << i)) ? 1 : 0);
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    uint32_t n = 0x0000000B;
    cout << s.hammingWeight(n);
}