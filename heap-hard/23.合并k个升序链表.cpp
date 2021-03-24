/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

#include <queue>
#include <vector>

using namespace std;

/*
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

// 133/133 cases passed (28 ms)
// Your runtime beats 78.01 % of cpp submissions
// Your memory usage beats 61.32 % of cpp submissions (13 MB)

struct Comp {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // For: []
        if (lists.empty()) {
            return nullptr;
        }

        priority_queue<ListNode*, vector<ListNode*>, Comp> q;

        // auto _greater = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        // priority_queue<ListNode*, vector<ListNode*>, decltype(_greater)> q(_greater);

        for (auto list : lists) {
            // For: [nullptr]
            if (list) {
                q.push(list);
            }
        }

        ListNode *dummy = new ListNode(0), *cur = dummy;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if (cur->next) {
                q.push(cur->next);
            }
        }
        return dummy->next;
    }
};
// @lc code=end
