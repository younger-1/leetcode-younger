/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

// @recursion
class Solution_1 {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* head_k = head;
        for (int i = 0; i < k; i++) {
            if (!head_k) {
                return head;
            }
            head_k = head_k->next;
        }
        ListNode* new_head = reverse(head, head_k);
        head->next = reverseKGroup(head_k, k);
        return new_head;
    }

   private:
    ListNode* reverse(ListNode* a, ListNode* b) {
        if (a->next == b) {
            return a;
        }
        ListNode* last = reverse(a->next, b);
        a->next->next = a;
        return last;
    }
};
// @lc code=end

// @iteration
class Solution_0 {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        head = dummy->next;
        ListNode *tail = dummy, *prev = nullptr, *cur = head, *next;
        int i = len / k, j;
        while (i--) {
            j = k;
            head = cur;
            // head
            // <- 1 <- 2 <- 3   4 -> 5 -> 6
            //           prev cur
            while (j--) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            tail->next = prev;
            tail = head;
        }
        head->next = cur;
        return dummy->next;
    }
};

#include <iostream>

using namespace std;

int main() {
    ListNode* n = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto s = Solution_0();
    n = s.reverseKGroup(n, 2);
    while (n) {
        cout << n->val << " ";
        n = n->next;
    }
}
