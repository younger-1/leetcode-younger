/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
// Redo
class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *pre = head, *cur = head->next;
        while (cur) {
            // note:
            while (cur && pre->val == cur->val) {
                cur = cur->next;
            }
            pre->next = cur;
            pre = pre->next;
            if (cur) {
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end
