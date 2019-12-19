#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
        {
            return "0";
        }
        string s, sprime = "";
        if ((numerator < 0 && denominator > 0) || (denominator < 0 && numerator > 0))
        {
            s.push_back('-');
        }
        long long nume = abs((long long)numerator), deno = abs((long long)denominator);
        s.append(to_string(nume / deno));
        if (nume % deno == 0)
        {
            return s;
        }
        s.push_back('.');
        unordered_map<long long, int> m;
        int pos = 0;
        long long r = nume % deno;
        while (r)
        {
            if (m.find(r) != m.end())
            {
                sprime.insert(m[r], "(");
                sprime += ")";
                return s + sprime;
            }
            m[r] = pos;
            sprime += to_string(r * 10 / deno);
            r = (r * 10) % deno;
            ++pos;
        }
        return s + sprime;
    }
};
int main()
{
    Solution s = Solution();
    int numerator, denominator;
    cin >> numerator >> denominator;
    cout << s.fractionToDecimal(numerator, denominator);
}