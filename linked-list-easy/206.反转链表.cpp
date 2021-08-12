/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start

// @iteration
class Solution {
   public:
    // 28/28 cases passed (4 ms)
    // Your runtime beats 97.89 % of cpp submissions
    // Your memory usage beats 83.16 % of cpp submissions (8 MB)
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
// @lc code=end

// TODO: redo
// @recursion
class Solution_1 {
   public:
    // 28/28 cases passed (4 ms)
    // Your runtime beats 97.89 % of cpp submissions
    // Your memory usage beats 60.81 % of cpp submissions (8.2 MB)
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};
