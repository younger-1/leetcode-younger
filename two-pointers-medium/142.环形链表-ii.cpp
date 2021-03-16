/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start

// 16/16 cases passed (8 ms)
// Your runtime beats 91.05 % of cpp submissions
// Your memory usage beats 50.13 % of cpp submissions (7.5 MB)
class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        // !: 对不成环的情况进行判断
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

// @lc code=end

#include <functional>
class Solution_1 {
   public:
    // 堆的地址从低到高，LeetCode的链表内存是顺序申请的
    ListNode *detectCycle(ListNode *head) {
        while (head) {
            // std::less<>() 实例化 less 结构体
            if (!std::less<ListNode *>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }
};