/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
class Solution {
   public:
    // 26/26 cases passed (24 ms)
    // Your runtime beats 67.83 % of cpp submissions
    // Your memory usage beats 43.18 % of cpp submissions (14.3 MB)
    bool isPalindrome(ListNode* head) {
        std::vector<int> nums;
        for (; head != nullptr; head = head->next) {
            nums.push_back(head->val);
        }
        for (int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] != nums[nums.size() - 1 - i])
                return false;
        }
        return true;
    }
};
// @lc code=end
