/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>

using namespace std;

/*
 * 回溯算法框架。解决一个回溯问题，实际上就是一个决策树的遍历过程:
 * 1、路径：也就是已经做出的选择。
 * 2、选择列表：也就是你当前可以做的选择。
 * 3、结束条件：也就是到达决策树底层，无法再做选择的条件。

```python
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```
 */

// @lc code=start

// 25/25 cases passed (4 ms)
// Your runtime beats 70.42 % of cpp submissions
// Your memory usage beats 87.63 % of cpp submissions (7.4 MB)
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrace(res, nums, 0);
        return res;
    }
    void backtrace(vector<vector<int>>& res, vector<int>& path, int first) {
        if (first == path.size()) {
            // note: emplace_back, return
            res.emplace_back(path);
            return;
        }
        for (int i = first; i < path.size(); i += 1) {
            swap(path[i], path[first]);
            backtrace(res, path, first + 1);
            swap(path[i], path[first]);
        }
    }
};
// @lc code=end
