// 剑指 Offer 14- I. 剪绳子
// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

#include <algorithm>
using namespace std;

// Time out
class Solution_0 {
   public:
    int cuttingRope(int n) { return dfs(1, n); }

    int dfs(int idx, int n) {
        if (idx == n) {
            return 1;
        } else if (idx + 2 >= n) {
            return n - idx;
        }
        int acc = 1;
        for (int i = idx + 1; i <= n; i += 1) {
            if (idx == 1) {
                acc = max(acc, (i - idx + 1) * dfs(i, n));
            } else {
                acc = max(acc, (i - idx) * dfs(i, n));
            }
        }
        return acc;
    }
};

// @greedy
class Solution_1 {
    /*
    如果 n == 2，返回1，如果 n == 3，返回2，两个可以合并成n小于4的时候返回n - 1
    如果 n == 4，返回4
    如果 n > 4，分成尽可能多的长度为3的小段，每次循环长度n减去3，乘积res乘以3；最后返回时乘以小于等于4的最后一小段

    作者：edelweisskoko
    链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/jian-zhi-offer-14-i-jian-sheng-zi-huan-s-xopj/
     */
   public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        return res * n;
    }
};

#include <cmath>
class Solution_2 {
    /*
    if n % 3 == 0: return int(math.pow(3, n / 3))
    if n % 3 == 1: return int(math.pow(3, n / 3 - 1) * 4)

    作者：jyd
    链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/
     */
   public:
    int cuttingRope(int n) { return n <= 3 ? n - 1 : pow(3, n / 3) * 4 / (4 - n % 3); }
};

#include <vector>
// @DP
class Solution {
    /*
    我们先把绳子剪掉第一段（长度为j），如果只剪掉长度为1，对最后的乘积无任何增益，所以从长度为2开始剪
    剩下(i - j)长度可以剪也可以不剪：如果不剪的话长度乘积即为j * (i - j)；如果剪的话长度乘积即为j * dp[i - j]
     */
   public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        // n >= 2
        dp[2] = 1;
        for (int i = 2; i < n + 1; i++) {
            for (int j = 2; j < i; j++) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};
