/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

// TODO: do
// @iteration
// https://leetcode-cn.com/problems/add-two-numbers/comments/254234
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    }
};
// @lc code=end

// @recursion
class Solution_0 {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { return dfs(l1, l2, 0); }

   private:
    ListNode* dfs(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && !carry) {
            return nullptr;
        }
        int val = carry;
        if (l1) {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            val += l2->val;
            l2 = l2->next;
        }
        carry = val / 10;
        ListNode* root = new ListNode(val % 10);
        root->next = dfs(l1, l2, carry);
        return root;
    }
};
