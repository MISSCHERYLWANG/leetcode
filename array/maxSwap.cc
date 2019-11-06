#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> ind(10, -1);
        // the index of the number occured the last time
        for (int i = 0; i < s.length(); ++i)
        {
            ind[s[i]-'0'] = i;
        }

        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = 9; j > s[i]-'0'; --j)
            {
                // 大数在低位
                if (ind[j] > i)
                {
                    swap(s[i], s[ind[j]]);
                    return atoi(s.c_str());
                }
            }
        }
        return atoi(s.c_str());
    }
};
int main()
{
    Solution s = Solution();
    // 98368->98863
    int num;
    cin >> num;

    cout << s.maximumSwap(num);
}
