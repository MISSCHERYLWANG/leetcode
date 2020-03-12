#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        // preprocess
        string T = "^#";
        for (char ch : s) {
            T.push_back(ch);
            T += "#";
        }
        T += '$';
        cout << T << endl;
        // radius
        vector<int> P(2 * n + 3, 0);
        int center = 0, right = 0;
        for (int i = 1; i < T.size()-1; ++i) {
            // mirror of i
            int j = 2 * center - i;      
            if (i < right) {
                P[i] = min(P[j], right - i);
            }
            while (T[i-1-P[i]] == T[i+1+P[i]]) {
                P[i]++;
            }
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
        }
        int res = 0;
        for (int i : P) {
            cout << i << " ";
            res += (i + 1) / 2;
        }
        cout << endl;
        return res;
    }
    
};

int main()
{
    Solution s = Solution();
    cout << s.countSubstrings("aaa") << endl;
    // cout << s.countSubstrings("abbc") << endl;
}