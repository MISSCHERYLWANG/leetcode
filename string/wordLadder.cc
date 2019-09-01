#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // set提高查找效率
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (!wordDict.count(endWord))
        {
            return 0;
        }
        unordered_map<string, int> pathCount{{{beginWord, 1}}};
        queue<string> q{{beginWord}};
        while (!q.empty())
        {
            string w = q.front();
            q.pop();
            for (int i = 0; i < w.size(); ++i)
            {
                string newWord = w;
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    newWord[i] = ch;
                    if (wordDict.count(newWord) && newWord == endWord)
                    {
                        return pathCount[w] + 1;
                    }
                    if (wordDict.count(newWord) && !pathCount.count(newWord))
                    {
                        q.push(newWord);
                        pathCount[newWord] = pathCount[w] + 1;
                    }
                }
            }
        }
        return 0;
    }
};
int main()
{
    Solution sol = Solution();
    string begw, endw;
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    
    cin >> begw >> endw;
    cout << sol.ladderLength(begw, endw, wordList);

    return 0;
}