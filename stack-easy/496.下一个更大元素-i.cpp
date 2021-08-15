/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start

// @monotonic-stack
class Solution_1 {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        //记录每个值对应的下一个最大值
        unordered_map<int, int> map;
        //正序遍历
        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && s.top() < nums2[i]) {
                //更新map
                map[s.top()] = nums2[i];
                s.pop();
            }
            // map初始化
            map[nums2[i]] = -1;
            s.push(nums2[i]);
        }
        //处理返回
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = map[nums1[i]];
        }
        return nums1;
    }
};

// @monotonic-stack
// 链接：https://leetcode-cn.com/problems/next-greater-element-i/solution/496xia-yi-ge-geng-da-yuan-su-i-c-dan-dia-37dl/
class Solution_2 {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int> map;
        stack<int> s;
        // 从后往前
        for (int i = n - 1; i >= 0; i--) {
            // 单调递减栈
            while (!s.empty() && nums2[i] > s.top()) {
                s.pop();
            }
            map[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = map[nums1[i]];
        }

        return ans;
    }
};

// @lc code=end
