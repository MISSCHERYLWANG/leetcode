#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = n;
        res = (res >> 16) | (res << 16);
        res = ((res & 0xff00ff00) >> 8) | ((res & 0x00ff00ff) << 8);
        res = ((res & 0xf0f0f0f0) >> 4) | ((res & 0x0f0f0f0f) << 4);
        res = ((res & 0xcccccccc) >> 2) | ((res & 0x33333333) << 2);
        res = ((res & 0xaaaaaaaa) >> 1) | ((res & 0x55555555) << 1);
        return res;
     }
};
int main()
{
    Solution s = Solution();
    uint32_t n;
    return s.reverseBits(n);
}