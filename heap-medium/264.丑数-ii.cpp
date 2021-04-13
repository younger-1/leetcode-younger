/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
// 动态规划
class Solution_1 {
   public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2) {
                p2++;
            }
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
        }
        return dp[n];
    }
};

// @lc code=end

// 最小堆
class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> factors{2, 3, 5};
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1L);
        heap.push(1L);
        int ugly = 0;
        for (int i = 0; i < n; i++) {
            long cur = heap.top();
            heap.pop();
            ugly = (int)cur;
            for (int factor : factors) {
                long next = cur * factor;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
};
