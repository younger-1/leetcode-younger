/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 98.49% 的用户
// 内存消耗： 10.8 MB , 在所有 C++ 提交中击败了 71.52% 的用户
class Solution {
   public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(0, head), *pre = dummy, *cur = head;

        while (cur != nullptr) {
            bool isDupl = false;
            // 判断 pre 的 next 与 cur 的 next 是否重复
            while (cur->next != nullptr && pre->next->val == cur->next->val) {
                cur = cur->next;
                isDupl = true;
            }
            if (isDupl) {
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
;
// @lc code=end
