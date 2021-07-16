// 剑指 Offer 25. 合并两个排序的链表
// ttps://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Solution_1 {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tracker = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tracker->next = l1;
                l1 = l1->next;
            } else {
                tracker->next = l2;
                l2 = l2->next;
            }
            tracker = tracker->next;
        }
        tracker->next = l1 ? l1 : l2;
        return head->next;
    }
};
