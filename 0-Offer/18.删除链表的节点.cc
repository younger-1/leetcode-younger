// 剑指 Offer 18. 删除链表的节点
// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/

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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *dum = new ListNode(0), *pre = dum;
        dum->next = head;
        while (head->val != val) {
            head = head->next;
            pre = pre->next;
        }
        pre->next = head->next;
        return dum->next;
    }
};

class Solution_1 {
   public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head)
            return nullptr;
        if (head->val == val)
            return head->next;
        head->next = deleteNode(head->next, val);
        return head;
    }
};
