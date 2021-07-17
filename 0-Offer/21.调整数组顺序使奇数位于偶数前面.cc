// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/

#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return nums;
        }
        int odd = 0, even = 0;
        while (odd < n && even < n) {
            while (even < n && (nums[even] & 1) == 1) {
                even++;
            }
            odd = even + 1 > odd ? even + 1 : odd;
            while (odd < n && (nums[odd] & 1) == 0) {
                odd++;
            }
            if (odd < n && even < n) {
                swap(nums[odd], nums[even]);
            }
        }
        return nums;
    }

    //    private:
    //     void swap(vector<int>& nums, int a, int b) {
    //         int tmp = nums[a];
    //         nums[a] = nums[b];
    //         nums[b] = tmp;
    //     }
};

// @two-pointer
// 作者：huwt
// 链接：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/ti-jie-shou-wei-shuang-zhi-zhen-kuai-man-shuang-zh/
class Solution_1 {
   public:
    // 首尾双指针
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] & 1) != 0) {
                left++;
                continue;
            }
            if ((nums[right] & 1) != 1) {
                right--;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};

class Solution_2 {
   public:
    // 快慢双指针
    // fast 的作用是向前搜索奇数位置，slow 的作用是指向下一个奇数应当存放的位置
    vector<int> exchange(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] & 1) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }
        return nums;
    }
};
