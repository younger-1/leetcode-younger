// 剑指 Offer 06. 从尾到头打印链表
// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
#include <vector>
using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @recursion
class Solution {
   public:
    vector<int> reversePrint(ListNode* head) {
        if (!head)
            return {};
        vector<int> a = reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};

// @iteration
class Solution_0 {
   public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode* cur = head;
        while (cur) {
            res.insert(res.begin(), cur->val);
            cur = cur->next;
        }
        return res;
    }
};