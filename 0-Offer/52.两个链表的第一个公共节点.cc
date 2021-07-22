// 剑指 Offer 52. 两个链表的第一个公共节点
// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
// 本题与主站 160 题相同：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// TODO: redo
// @two-pointer
class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        ListNode *n1 = headA;
        ListNode *n2 = headB;

        while (n1 != n2) {
            n1 = n1 == nullptr ? headB : n1->next;
            n2 = n2 == nullptr ? headA : n2->next;
        }
        return n1;
    }
};
