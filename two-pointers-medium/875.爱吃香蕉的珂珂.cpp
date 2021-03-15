/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

#include <vector>

using namespace std;

// @lc code=start

// 118/118 cases passed (48 ms)
// Your runtime beats 78.64 % of cpp submissions
// Your memory usage beats 46.24 % of cpp submissions (18.4 MB)
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = getMax(piles);
        int lo = 1, hi = max + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (eatUp(piles, mid, h)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    int getMax(vector<int>& nums) {
        int max = 0;
        for (auto n : nums) {
            max = n > max ? n : max;
        }
        return max;
    }

    bool eatUp(vector<int>& nums, int k, int h) {
        int time = 0;
        for (auto n : nums) {
            // bug: time += n / k + 1;
            // time += n / k + (n % k == 0 ? 0 : 1);
            time += (n - 1) / k + 1;
        }
        return time <= h;
    }
};
// @lc code=end
