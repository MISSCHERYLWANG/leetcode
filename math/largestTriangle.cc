#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());

        int i = A.size()-3;
        while (i >= 0)
        {
            if (A[i]+A[i+1]<=A[i+2])
            {
                --i;
            }
            else
            {
                return (A[i]+A[i+1]+A[i+2]);
            }
            
        }
        return 0;
    }
};
int main()
{
    Solution s = Solution();
    vector<int> A{2,1,1};

    cout << s.largestPerimeter(A);
}