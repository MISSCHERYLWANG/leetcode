#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int len1 = version1.size(), len2 = version2.size();
        int i = 0, j = 0;
        while (!version1.empty() && !version2.empty())
        {
            int tmp1, tmp2;
            tmp1 = versionNum(version1);
            tmp2 = versionNum(version2);
            if (tmp1 > tmp2)
            {
                return 1;
            }
            else if (tmp1 < tmp2)
            {
                return -1;
            }
        }
        while (!version1.empty())
        {
            if (versionNum(version1) > 0)
            {
                return 1;
            }
        }
        while (!version2.empty())
        {
            if (versionNum(version2) > 0)
            {
                return -1;
            }
        }
        return 0;
    }
    int versionNum(string &version) 
    {
        string tmp = version;
        int i = 0;
        while (i < version.size() && version[i]!='.')
        {
            ++i;
        }
        version = (i+1 < tmp.size()) ? tmp.substr(i+1) : "";
        return atoi(tmp.substr(0, i).c_str());
    }
};
int main()
{
    Solution s = Solution();
    string v1, v2;
    cin >> v1 >> v2;
    cout << s.compareVersion(v1, v2);
}