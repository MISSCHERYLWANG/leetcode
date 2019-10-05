#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m1, m2;
        for (int num : arr)
        {
            ++m1[num];
        }
        for (auto it : m1)
        {
            if (m2.find(it.second) != m2.end())
            {
                return false;
            }
            ++m2[it.second];
        }
        return true;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> arr{1,2,2,1,1,3};

    cout << sol.uniqueOccurrences(arr);

}