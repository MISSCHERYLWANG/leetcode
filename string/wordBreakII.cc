#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (m.count(s))
        {
            return m[s];
        }
        if (s.empty())
        {
            return {""};
        }
        vector<string> cur;
        for (string word: wordDict)
        {
            if (s.substr(0, word.size()) != word)
            {
                continue;
            }
            vector<string> memo = wordBreak(s.substr(word.size()), wordDict);
            for (string s: memo)
            {
                cur.push_back(word + (s.empty() ? "" : " ") + s);
            }
        }
        m[s] = cur;
        return cur;
    }

};

int main()
{
    Solution sol = Solution();

    string s;
    cin >> s;

    vector<string> wordDict{"cat", "cats", "and", "sand", "dog"};

    vector<string> ans = sol.wordBreak(s, wordDict);

    for (string s: ans)
    {
        cout << s << " ";
    }
    
}