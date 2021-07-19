// 剑指 Offer 22. 链表中倒数第k个节点
// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *a = head, *b = head;
        while (k--) {
            b = b->next;
        }
        while (b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};

class Solution_1 {
   public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        while (fast) {
            fast = fast->next;
            if (k == 0) {
                head = head->next;
            } else {
                k--;
            }
        }
        return head;
    }
};
