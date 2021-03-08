/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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

// 208/208 cases passed (8 ms)
// Your runtime beats 87.37 % of cpp submissions
// Your memory usage beats 66.06 % of cpp submissions (14.4 MB)
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 哨兵节点 prehead ，这可以在最后让我们比较容易地返回合并后的链表
        ListNode* preHead = new ListNode(-1);

        ListNode* pre = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = l1 == nullptr ? l2 : l1;
        return preHead->next;
    }
};

// @lc code=end

// 208/208 cases passed (12 ms)
// Your runtime beats 59.42 % of cpp submissions
// Your memory usage beats 94.14 % of cpp submissions (14.3 MB)
class Solution_1 {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};
