/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n + 1);
        //   arr = [1,4,2,5,3]
        // pre = [0,1,5,7,12,15]
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + arr[i];
        }
        int sum = 0;
        for (int len = 1; len <= n; len += 2) {
            for (int start = 0; start + len <= n; start += 1) {
                sum += pre[start + len] - pre[start];
            }
        }
        return sum;
    }
};
// @lc code=end

// 作者：liuyubobobo
// 链接：https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/solution/cong-on3-dao-on-de-jie-fa-by-liuyubobobo/
// TODO: redo
class Solution_1 {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = i + 1, right = arr.size() - i;
            int left_even = (left + 1) / 2, right_even = (right + 1) / 2;
            int left_odd = left / 2, right_odd = right / 2;
            res += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return res;
    }
};
