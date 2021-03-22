/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

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
    // 15/15 cases passed (0 ms)
    // Your runtime beats 100 % of cpp submissions
    // Your memory usage beats 63.29 % of cpp submissions (6.4 MB)
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end
