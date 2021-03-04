/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    // 年轻题，不讲码德
    void deleteNode(ListNode* node) {
        //一种"狸猫换太子"的效果
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
// @lc code=end

// 12ms 6.8MB
class Solution1 {
   public:
    void deleteNode(ListNode* node) { *node = *(node->next); }
};