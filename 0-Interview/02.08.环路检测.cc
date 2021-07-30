// 面试题 02.08. 环路检测
// https://leetcode-cn.com/problems/linked-list-cycle-lcci/

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *ne) : val(x), next(ne) {}
};

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main() {
    auto s = Solution();
    ListNode *tail = new ListNode(4);
    ListNode *head = new ListNode(3, new ListNode(2, new ListNode(0, tail)));
    tail->next = head->next;
    s.detectCycle(head);
}
