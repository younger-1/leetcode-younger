// 剑指 Offer 09. 用两个栈实现队列
// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

#include <stack>
using namespace std;

// 维护两个栈，第一个栈支持插入操作，第二个栈支持删除操作
class CQueue {
   private:
    stack<int> s1, s2;

   public:
    CQueue() {}

    void appendTail(int value) { s1.push(value); }

    int deleteHead() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            return -1;
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
