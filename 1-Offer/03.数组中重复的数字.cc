// 剑指 Offer 03. 数组中重复的数字
// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

/*
它考察的是程序员的沟通能力，先问面试官要时间/空间需求！！！
只是时间优先就用字典，
还有空间要求，就用指针+原地排序数组，
如果面试官要求空间O(1)并且不能修改原数组，还得写成二分法！！！
 */

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

class Solution_2 {
   public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            while (nums[i] == i) {
                i++;
            }
            if (nums[i] < i) {
                return nums[i];
            }
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

// TODO: redo
// 链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/mian-shi-ti-03-shu-zu-zhong-zhong-fu-de-shu-zi-yua/
class Solution_3 {
   public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};
