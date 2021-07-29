/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> pathInZigZagTree(int label) {
        int la = label, n = 0;
        while (la) {
            la /= 2;
            n++;
        }
        vector<int> ans(n);
        while (n) {
            ans[n - 1] = label;
            // 每次先找到对称节点除以二就是其父节点的值
            label = ((1 << n) - 1 + (1 << n - 1) - label) / 2;
            n--;
        }

        return ans;
    }
};
// @lc code=end
