#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int i = 0, s = flowerbed.size(), place = 0;
        while (i < s)
        {
            int start = i;
            if (flowerbed[i] == 0)
            {
                int num = 0;
                while (i < s && flowerbed[i] == 0)
                {
                    ++num;
                    ++i;
                }
                if (i == s || start == 0)
                {
                    place += (num / 2);
                    if (i == s && start == 0)
                    {
                        place += (num % 2 ? 1 : 0);
                    }
                }
                else
                {
                    place += num / 2 - (num % 2 ? 0 : 1);
                }
            }
            else
            {
                ++i;
            }
        }
        return (place >= n);
    }
};
int main()
{
    Solution s = Solution();
    vector<int> fb{0, 0, 0};
    int n = 2;

    cout << s.canPlaceFlowers(fb, n);
}