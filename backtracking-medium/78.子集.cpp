/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // base case，返回一个空集
        if (nums.size() == 0) {
            return {{}};
        }
        // 把最后一个元素拿出来
        int last = nums.back();
        nums.pop_back();
        // 先递归算出前面元素的所有子集
        vector<vector<int>> res = subsets(nums);

        int n = res.size();
        for (int i = 0; i < n; i++) {
            // 然后在之前的结果之上追加
            res.push_back(res[i]);
            res.back().push_back(last);
        }
        return res;
    }
};

// @lc code=end

// 10/10 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 92.79 % of cpp submissions (6.8 MB)
class Solution_0 {
    vector<vector<int>> res;
    vector<int> path;

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrace(nums, 0);
        return res;
    }
    void backtrace(vector<int>& nums, int start) {
        res.emplace_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrace(nums, i + 1);
            path.pop_back();
        }
    }
};
