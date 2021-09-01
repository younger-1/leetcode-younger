/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */
#include <vector>

using namespace std;

// @lc code=start

// 差分数组+前缀和
// 差分数组对应的概念是前缀和数组，对于数组 [1,2,2,4]，其差分数组为 [1,1,0,2]
// 差分数组的第 i 个数即为原数组的第 i−1 个元素和第 i 个元素的差值，也就是说我们对差分数组求前缀和即可得到原数组。

// 典型区间和维护问题，最简单的方法是使用差分数组
// arr[a, b] 内所有数 +c 反映到差分数组上，对应 diff[a] += c, diff[b+1] += c
// 注意到 diff[b+1] 可能造成数组下标越界，常见处理方法有:
// 1. 每次改变 diff[b+1] 时都先判断会不会越界
// 2. diff 多开辟一位，用以处理越界情况

// @prefix-sum
// TODO: redo
class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);
        for (auto& book : bookings) {
            nums[book[0] - 1] += book[2];
            if (book[1] < n) {
                nums[book[1]] -= book[2];
            }
        }
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
// @lc code=end
