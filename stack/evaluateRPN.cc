#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) 
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                st.push(str_to_int(tokens[i]));
            }
            else
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if (tokens[i] == "+")
                {
                    st.push(num1 + num2);
                }
                else if (tokens[i] == "-")
                {
                    st.push(num1 - num2);
                }
                else if (tokens[i] == "*")
                {
                    st.push(num1 * num2);
                }
                else
                {
                    st.push(num1 / num2);
                }    
            }
        }
        return st.top();
    }
    int str_to_int(string s) {
        int ans = 0, i = 0;
        if (s[i] == '-')
        {
            i = 1;
        }
        for (; i < s.size(); ++i)
        {
            ans = ans * 10 + s[i] - '0';
        }
        return (s[0] == '-' ? -ans : ans);
    }
};

int main()
{
    Solution sol = Solution();
    vector<string> tokens{"-2", "1", "+", "3", "*"};

    cout << sol.evalRPN(tokens);

    return 0;
}
