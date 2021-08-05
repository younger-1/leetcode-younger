// 剑指 Offer 53 - I. 在排序数组中查找数字 I
// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
#include <vector>

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int ret = 0;
        while (left != n && nums[left] == target) {
            left++;
            ret++;
        }
        return ret;
    }
};

#include <algorithm>
class Solution_1 {
   public:
    int search(vector<int>& nums, int target) {
        return upper_bound(begin(nums), end(nums), target) - lower_bound(begin(nums), end(nums), target);
    }
};
