/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

#include <climits>
#include <queue>

using namespace std;

// @lc code=start

class Solution {
   public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1);
        long ans;
        while (n--) {
            for (int i : primes) {
                q.push(q.top() * i);
            }
            ans = q.top();
            q.pop();
            while (!q.empty() && ans == q.top()) {
                q.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

#include <unordered_map>

class Solution_1 {
   public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, INT_MAX);
        dp[0] = 1;
        unordered_map<int, int> ugly;
        for (int i = 1; i < n; i++) {
            for (int e : primes) {
                dp[i] = min(dp[i], e * dp[ugly[e]]);
            }
            for (int e : primes) {
                if (dp[i] == e * dp[ugly[e]]) {
                    ugly[e]++;
                }
            }
        }
        return dp[n - 1];
    }
};
