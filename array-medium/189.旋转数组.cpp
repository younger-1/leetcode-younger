/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    // 35/35 cases passed (4 ms)
    // Your runtime beats 98.86 % of cpp submissions
    // Your memory usage beats 99.3 % of cpp submissions (9.6 MB)
    // 环状替换
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = std::gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                std::swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};

// @lc code=end

// Time out
class Solution_0 {
   public:
    void rotate(vector<int>& nums, int k) {
        int tmp;
        // reduce unnecessary iterations
        k %= nums.size();
        for (int i = 0; i != k; i++) {
            tmp = nums.back();
            for (int index = nums.size() - 1; index != 0; index--)
                nums[index] = nums[index - 1];
            nums[0] = tmp;
        }
    }
};

// 4ms
// 加一个和输入一样大小的临时数组, 但不满足O(1)
// (i + k) % nums.size() 可直接获取元素旋转之后的位置
class Solution_1 {
   public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums2(nums);
        int n = nums.size();
        for (int i = 0; i != n; ++i) {
            nums[(i + k) % n] = nums2[i];  // image a cirlce
        }
    }
};

// 0ms
class Solution_2 {
   public:
    void rotate(vector<int>& nums, int k) {
        int* temp;
        int n = nums.size();
        temp = (int*)malloc(sizeof(int) * n);
        k %= n;
        for (int i = 0; i != k; i++) {
            temp[i] = nums[n - k + i];  //后面k个
        }
        for (int i = k; i != n; i++) {
            temp[i] = nums[i - k];
        }
        for (int i = 0; i != n; i++) {
            nums[i] = temp[i];
        }
    }
};

class Solution_3 {
   public:
    /*
        nums = "----->-->"; k =3
        result = "-->----->";

        reverse "----->-->" we can get "<--<-----"
        reverse "<--" we can get "--><-----"
        reverse "<-----" we can get "-->----->"
        this visualization help me figure it out :)
    */
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};

#include <algorithm>
class Solution_4 {
   public:
    // 三次翻转
    // 35/35 cases passed (4 ms)
    // Your runtime beats 98.91 % of cpp submissions
    // Your memory usage beats 99.8 % of cpp submissions (9.5 MB)
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= nums.size();
        reverse(&nums[0], &nums[length]);
        reverse(&nums[0], &nums[k]);
        reverse(&nums[k], &nums[length]);
    }
};
