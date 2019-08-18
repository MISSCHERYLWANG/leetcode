#include<iostream>
#include<string>
#include<vector>
#include<sstream>   // stringstream
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string res;
        vector<string> temp;
        int n = path.length(), i = 0;
        while (i < n)
        {
            while (i < n && path[i] == '/')
            {
                ++i;
            }
            if (i == n)
            {
                break;
            }
            int start = i;
            while (i < n && path[i] != '/')
            {
                ++i;
            }
            int end = i - 1;
            string cur = path.substr(start, end-start+1);
            if (cur == "..")
            {
                if (!temp.empty())
                {
                    temp.pop_back();
                }
            }
            else if (cur != ".")
            {
                temp.push_back(cur);
            }
        }
        // stringstream+getline分隔字符串
/**     string res, cur;
        vector<string> temp;
        stringstream ss(path);
        while (getline(ss, cur, '/'))
        {
            if (cur == "" || cur == ".")
            {
                continue;
            }
            else if (cur == ".." && !temp.empty())
            {
                temp.pop_back();
            }
            else if (cur != "..")
            {
                temp.push_back(cur);
            }
        }
**/
        if (temp.empty())
        {
            return "/";
        }
        for (int j = 0; j < temp.size(); ++j)
        {
            res += ("/" + temp[j]);
        }
        return res;
    }
};
int main()
{
    Solution sol = Solution();
    string path, ans;
    cin >> path;
    cout << sol.simplifyPath(path);
    return 0;
}