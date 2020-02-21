#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int len = 0;
    int findKthLargest(vector<int>& nums, int k) {
        len = nums.size();
        buildMaxHeap(nums);
        for (int i = 0; i < k; ++i) {
            swap(nums[0], nums[len-1]);
            len--;
            heapify(nums, 0);
        }
        return nums[len];
    }
    // 堆调整
    void heapify(vector<int>& arr, int i) {
        int left = 2*i+1, right = 2*i+2, largest = i;
        if (left < len && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < len && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, largest);
        }
    }
    // 建大堆
    void buildMaxHeap(vector<int>& arr) {
        // 最后一个非0结点: n/2-1
        for (int i = arr.size() / 2 - 1; i >= 0; --i) {
            heapify(arr, i);
        }
    }
};

int main()
{
    Solution s = Solution();

    vector<int> 
    nums{2,1};
    // nums{3,2,1,5,6,4};
    int k = 2;
    cout << s.findKthLargest(nums, k);
}