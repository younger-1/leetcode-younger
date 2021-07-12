// 剑指 Offer 03. 数组中重复的数字
// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

#include <vector>

using namespace std;

class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> arr(nums.size(), 0);
        for (int n : nums) {
            if (arr[n]) {
                return n;
            }
            arr[n] += 1;
        }
        return -1;
    }
};

// space: O(1)
class Solution_1 {
   public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int k = nums[i];
            if (k < 0) {
                k += n;
            }
            if (nums[k] < 0) {
                return k;
            }
            nums[k] -= n;
        }
        return -1;
    }
};