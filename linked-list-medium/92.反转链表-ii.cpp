/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

/**
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
class Solution {
    // 44/44 cases passed (4 ms)
    // Your runtime beats 51.75 % of cpp submissions
    // Your memory usage beats 20.43 % of cpp submissions (7.3 MB)
    ListNode* successor = nullptr;
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

   public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
};
// @lc code=end

class Solution_1 {
   public:
    // 44/44 cases passed (0 ms)
    // Your runtime beats 100 % of cpp submissions
    // Your memory usage beats 13.35 % of cpp submissions (7.3 MB)
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(), *pre = dummy, *cur;
        dummy->next = head;
        for (int i = 0; i < m - 1; i++) {
            pre = pre->next;
        }
        cur = pre->next;
        for (int i = 0; i < n - m; i++) {
            ListNode* temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        return dummy->next;
    }
};