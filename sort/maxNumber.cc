#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool larger(string a, string b) {
        string s1 = a+b;
        string s2 = b+a;
        return s1 > s2;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        string res = "";
        for (int n : nums) {
            temp.push_back(to_string(n));
        }
        sort(temp.begin(), temp.end(), larger);
        for (string s : temp) {
            // cout << s << endl;
            res += s;
        }
        if (res[0] == '0') {
            return "0";
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    vector<int> nums{3, 30};

    cout << s.largestNumber(nums);
}