/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 82.17% 的用户
// 内存消耗： 11.5 MB , 在所有 C++ 提交中击败了 35.27% 的用户
class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) {
            return head;
        }
        int len = 0;
        ListNode *cur = head, *pre = head, *tail;
        while (cur) {
            if (cur && cur->next == nullptr) {
                tail = cur;
            }
            len += 1;
            cur = cur->next;
        }
        k %= len;
        // pre 记录断开的位置
        for (int i = 0; i < len - k - 1; i++) {
            pre = pre->next;
        }
        tail->next = head;
        head = pre->next;
        pre->next = nullptr;
        return head;
    }
};
// @lc code=end
