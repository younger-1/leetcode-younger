/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

#include <vector>

using namespace std;

// @lc code=start

// 84/84 cases passed (52 ms)
// Your runtime beats 85.16 % of cpp submissions
// Your memory usage beats 85.28 % of cpp submissions (25.4 MB)
class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int D) {
        // 载重可能的最小值
        int left = getMax(weights);
        // 载重可能的最大值 + 1
        int right = getSum(weights) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(weights, mid, D)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool canFinish(vector<int>& weights, int load, int D) {
        int days = 0;
        int daySum = 0;
        for (auto w : weights) {
            daySum += w;
            if (daySum > load) {
                days += 1;
                daySum = w;
            }
        }
        // 剩余货物
        days += 1;
        return days <= D;
    }

    int getMax(vector<int>& weights) {
        int max = 0;
        for (auto w : weights) {
            max = w > max ? w : max;
        }
        return max;
    }

    int getSum(vector<int>& weights) {
        int sum = 0;
        for (auto w : weights) {
            sum += w;
        }
        return sum;
    }
};
// @lc code=end
